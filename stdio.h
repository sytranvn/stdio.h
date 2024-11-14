#include <stdarg.h>
#include <unistd.h>
// standard buffered input/output

#define BUFSIZ 255
#define EOF -1

#define stderr STDERR_FILENO
#define stdin  STDIN_FILENO
#define stdout STDOUT_FILENO

// TODO: declare and implement following functions
int      printf(const char *restrict, ...);
int      putchar(int);
int      puts(const char *);
int      remove(const char *);
int      rename(const char *, const char *);
int      scanf(const char *restrict, ...);
// TODO: END

int mscanf(char *f);
int mprintf(const char *, ...);
int foo(const int, ...);
int op(const char *, ...);
