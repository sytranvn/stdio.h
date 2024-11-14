#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int count, ...) {
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

int op(const char *o, ...) {
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
    sum += x;
  }

  return sum;
}
int main() {
  char a;
  int b, c;
  mscanf("%c", &a);
  printf("%c\n", a);
  mscanf("%d %o", &b, &c);
  printf("%d %o=%d\n", b, c, c);
}
