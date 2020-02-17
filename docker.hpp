#include <sys.wait.h>	// waitpid
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

    };  // 类结束

} // namespace结束

