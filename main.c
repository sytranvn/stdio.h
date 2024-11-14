#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *f;
  f = malloc(11);
  mprintf("input f: ");
  mscanf(f);
  printf("printf: %s", f);
  mprintf(f);
  printf("%d \n", foo(6, 1, 2, 3, 4, 0, 5));
  printf("%d \n", op("sum", 6, 1, 2, 3, 4, 0, 5));
  return 0;
}
