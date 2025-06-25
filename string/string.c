// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
    if (destination == NULL) {
        return NULL;
    }
    char *ptr_dest = destination;
    while (*source != '\0')
    {
        *ptr_dest = *source;
        ptr_dest++;
        source++;
    }
    *ptr_dest = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (destination == NULL) {
        return NULL;
    }
	char *ptr_dest = destination;
	while (len > 0 && *source != '\0')
    {
        *ptr_dest = *source;
        ptr_dest++;
        source++;
		len--;
    }
	if (len > 0){
		*ptr_dest = '\0';
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char* ptr_dest = destination + strlen(destination);
    while (*source != '\0') {
        *ptr_dest = *source;
		ptr_dest++;
        source++;
    }
    *ptr_dest = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char* ptr_dest = destination + strlen(destination);
    while (len > 0 && *source != '\0') {
        *ptr_dest = *source;
		ptr_dest++;
        source++;
		len--;
    }
    *ptr_dest = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while(*str1 != '\0'){
		if(*str1 != *str2){
			break;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while(len > 0){
		if(*str1 != *str2){
			return *str1 - *str2;
		}
		str1++;
		str2++;
		len--;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while(*str != '\0'){
		if(*str == c){
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *last = NULL;
	while(*str != '\0'){
		if(*str == c){
			last = (char *)str;
		}
		str++;
	}
	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0') {
		return (char *)haystack;
	}
	while (*haystack != '\0')
    {
		const char *ptr_heystack = haystack;
		const char *ptr_needle = needle;
        while (*ptr_heystack == *ptr_needle && *ptr_needle != '\0')
        {
            ptr_heystack++;
            ptr_needle++;
        }
        if (*ptr_needle == '\0')
            return (char *)haystack;

        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (*needle == '\0') {
		return (char *)haystack;
	}
	char *last = NULL;
	while (*haystack != '\0')
    {
		const char *ptr_heystack = haystack;
		const char *ptr_needle = needle;
        while (*ptr_heystack == *ptr_needle && *ptr_needle != '\0')
        {
            ptr_heystack++;
            ptr_needle++;
        }
        if (*ptr_needle == '\0')
            last = (char *)haystack;
        haystack++;
    }
	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *ptr_dest = (char *)destination;
    char *ptr_src = (char *)source;
    while (num > 0){
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		num--;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *ptr_dest = (char *)destination;
    char *ptr_src = (char *)source;

	if(source < destination){
		while(num > 0){
			num--;
			*(ptr_dest + num) = *(ptr_src + num);
		}
	} else {
	 	while(num > 0){
	 		*ptr_dest = *ptr_src;
	 		ptr_dest++;
	 		ptr_src++;
	 		num--;
	 	}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *str1 = (char *)ptr1;
    char *str2 = (char *)ptr2;
	while(num > 0){
		if(*str1 != *str2){
			return (int)(*str1 - *str2);
		}
		str1++;
		str2++;
		num--;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *ptr_src = (char *)source;
	while(num > 0){
		*ptr_src = value;
		ptr_src++;
		num--;
	}
	return source;
}
