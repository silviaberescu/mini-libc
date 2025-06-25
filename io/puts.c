// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <string.h>
#include <errno.h>

int puts(const char *str) {
    if (str == NULL) {
        return -1;
    }
    size_t len = strlen(str);
    int ret = write(1, str, len);
    if (ret == -1) {
        return -1;
    }
    ret = write(1, "\n", 1);
    return ret;
}
