#include <sys/wait.h>	// waitpid
#include <sys/mount.h>  // mount
#include <fcntl.h>      // open
#include <unistd.h>     // execv, sethostname, chroot, fchdir
#include <sched.h>

#include <cstring>  // C   lib
#include <string>   // C++ lib

#define STACK_SIZE (512*512)

namespace docker {
    typedef int proc_statu;
    proc_statu proc_err  = -1;
    proc_statu proc_exit = 0;
    proc_statu proc_wait = 1;

    typedef struct container_config {
        std::string host_name;
        std::string root_dir;
    } container_config;

    class container {
    private:
        // 可读性增强
        typedef int process_pid;
        // 子进程栈
        char child_stack[STACK_SIZE];
        // 容器配置
        container_config config;
    public:
        container(container_config &config) {
            this->config = config;
        }

        void start(){
            auto setup = [](void *args) -> int {
                auto _this = reinterpret_cast<container *>(args);

                // 对容器进行相关配置
                _this->set_hostname();
                _this->set_rootdir();
                _this->set_procsys();
				_this->start_bash();

                return proc_wait;
            };

            process_pid child_pid = clone(setup, child_stack+STACK_SIZE, // 移动到栈底
                                CLONE_NEWUTS|	// 添加 UTS namespace
                                CLONE_NEWNS|    // Mount    namespace
                                CLONE_NEWPID|   // PID      namespace
								SIGCHLD,      	// 子进程退出时会发出信号给父进程
                                this);
            waitpid(child_pid, nullptr, 0);     // 等待子进程退出
          
        }
    private:
	// 设置容器主机名
	void set_hostname() {
            sethostname(this->config.host_name.c_str(), this->config.host_name.length());
        }
	
    private:
	void set_rootdir(){
        // chdir 系统调用，切换到某个目录下
        chdir(this->config.root_dir.c_str());
        
        // chroot 系统调用，设置根目录，因为刚才已经切换过当前目录
        // 故直接使用当前目录作为根目录即可
        chroot(".");
	} 
    // 设置独立的进程空间
    void set_procsys(){
        // 挂载 proc 文件系统
        mount("none", "/proc", "proc", 0, nullptr);
        mount("none", "/sys", "sysfs", 0, nullptr);
    }

    void start_bash() {
        // 将C++风格的string 转换为 C 风格的字符串 char* 
        std::string bash = "/bin/bash";
        char *c_bash = new char[bash.length()+1];
        strcpy(c_bash, bash.c_str());

        char* const child_args[] = { c_bash, NULL };
        execv(child_args[0], child_args);   // 在子进程中执行 /bin/bash
        delete []c_bash;

    }
        

    };  // 类结束

} // namespace结束

