// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
        return NULL;
    }
	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (block == MAP_FAILED) {
        return NULL;
    }
	if (mem_list_add(block, size) < 0) {
        munmap(block, size);
        return NULL;
    } else {
		return block;
	}
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total = nmemb * size;
	if (total == 0) {
        return NULL;
    }
	void *block = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (block == MAP_FAILED) {
        return NULL;
    }
	if (mem_list_add(block, total) < 0) {
        munmap(block, total);
        return NULL;
    } else {
		block = memset(block, 0, total);
		return block;
	}
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
        return;
    }
    struct mem_list *block = mem_list_find(ptr);
    if (block == NULL) {
        return;
    }
    if (munmap(ptr, block->len) == 0) {
        mem_list_del(ptr);
    }
	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0 && ptr != NULL) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(size);
    }
    struct mem_list *block_found = mem_list_find(ptr);
    if (block_found == NULL) {
        return NULL;
    }
    if (block_found->len == size) {
        return ptr;
    }
    void *new_block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_block == MAP_FAILED) {
        return NULL;
    }
	size_t copy_size = size;
	if(block_found->len < size){
		copy_size = block_found->len;
	}
    memcpy(new_block, ptr, copy_size);
    free(ptr);
    if (mem_list_add(new_block, size) < 0) {
        munmap(new_block, size);
        return NULL;
    }
    return new_block;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total = nmemb * size;
	if (total == 0) {
        free(ptr);
        return NULL;
    }
	void *block = realloc(ptr, total);
	return block;
}
