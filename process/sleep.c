#include <unistd.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds){
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    rem.tv_sec = 0;
    rem.tv_nsec = 0;
    int ret = nanosleep(&req, &rem);
    if (ret == 0){
        return 0;
    }
    return rem.tv_sec;
}
