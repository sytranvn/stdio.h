#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int mscanf(char* f) {
	char buff[11];
	memset(buff, '\0', 11);
	memset(f, '\0', 11);
	read(STDIN_FILENO, buff, 10);
	memcpy(f, buff, strlen(buff));
	return 1;
}

int scanf (const char * restrict, ...) {
	return 0;
}

int mprintf(const char *s, ...) {
	write(STDOUT_FILENO, s, strlen(s) + 1);
	return 0;
}


 
int foo(int count, ...) 
{
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        sum += num;
    }
    va_end(args);
    return sum;
}

int op(const char * o, ...) {
	va_list args;
	va_start(args, o);
	int count;
	if (strcmp(o, "sum") != 0) {
		return -1;
	}
	count = va_arg(args, int);
	int sum = 0;
	int x;
	for (int i = 0; i < count; i++) {
		x = va_arg(args, int);
		sum+= x;
	}

	return sum;
}
