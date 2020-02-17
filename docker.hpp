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


}

