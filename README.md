# mini-libc

## Overview

This is a minimal implementation of the standard C library. It provides core string manipulation, memory management, and low-level I/O functionalities by directly invoking Linux system calls without relying on any external libraries, including glibc.

This project is designed to deepen understanding of:

- How the standard C library is structured and implemented
- Direct interaction with the Linux syscall interface
- Memory and string management in C
- Basic POSIX-compliant file and process I/O

### Implemented Headers and Functions

#### `<string.h>`
- `strcpy`, `strncpy`, `strcat`, `strncat`
- `strlen`, `strcmp`, `strncmp`
- `strstr`, `strrstr`
- `memcpy`, `memmove`, `memset`, `memcmp`

#### `<stdio.h>`
- `puts`

#### `<unistd.h>` / `<sys/fcntl.h>` / `<sys/stat.h>`
- `open`, `close`, `lseek`, `stat`, `fstat`
- `truncate`, `ftruncate`
- `nanosleep`, `sleep`
### `<time.h>`
- `sleep`, `nanosleep`
#### `<stdlib.h>` / `<sys/mman.h>`
- `malloc`, `calloc`, `free`
- `realloc`, `realloc_array`
- `mmap`, `munmap`, `mremap`