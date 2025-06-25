// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int ret = syscall(__NR_close, fd);
	return (ret < 0) ? (errno = -ret, -1) : ret;
}
