// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(35, req, rem);
    if (ret >= 0) {
		return ret;
	}
	errno = -ret;
	return -1;
}

