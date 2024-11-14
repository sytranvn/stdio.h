#include "stdio.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Read formatted data from stdin
 *
 * Reads data from stdin and stores them according to the parameter format into
 * the locations pointed by the additional arguments.
 * The additional arguments should point to already allocated objects of the
 * type specified by their corresponding format specifier within the format
 * string.
 * A format specifier for scanf follows this prototype:
 * %[*][width][length]specifier
 *
 * Supported specifiers: %d, %c, %o
 */
int mscanf(const char *restrict fmt, ...) {

  va_list args;
  va_start(args, fmt);
  char buff[BUFSIZ];
  ssize_t bytes_read;
  int c = 0;
  size_t fmtlen = strlen(fmt);
  int args_read = 0;
  int ignored;
  int width;
  int length; // one of hh, h, l, ll, j, z, t, L
  for (int i = 0; i < fmtlen; i++) {
    if (isspace(fmt[i]))
      continue;
    if (fmt[i] == '%') {
      // read formated data
      ignored = 0;
      width = -1;
      i++;
      while (i < fmtlen) {
        if (fmt[i] == '*') {
          ignored = 1;
          continue;
        }
        if (fmt[i] >= '0' && fmt[i] <= '9') {
          width = fmt[i] - '0';
          i++;
          while (fmt[i] >= '0' && fmt[i] <= '9') {
            width = width * 10 + fmt[i++] - '0';
          }
        }
        switch (fmt[i]) {
        // TODO: current data type fit in int type, add support for custom
        // length later
        case 'l':
        case 'h':
        case 'j':
        case 'z':
        case 't':
        case 'L':
          i++;
          break;
        default:
          break;
        }
        // parse input to data
        char* carg;
        int* iarg, neg = 0;
        switch (fmt[i]) {
        case 'c':
          carg = va_arg(args, char*);
          bytes_read = read(stdin, buff, 1);
          if (bytes_read == 1) {
            *carg = buff[0];
          } else {
              return args_read;
          }
          break;
        case 'd':
          iarg = va_arg(args, int*);
          *iarg = 0;
          while ((bytes_read = read(stdin, buff, 1) == 1) && isspace(buff[0])) {
          continue;
          }
          if (!bytes_read) {
            return args_read;
          }
          if (buff[0] == '-') {
            neg = 1;
          } else *iarg = buff[0] - '0';
          while ((bytes_read = read(stdin, buff, 1) == 1) &&
            buff[0] >= '0' && buff[0] <= '9' &&
            width-- != 0) {
                *iarg = (*iarg) * 10 + (buff[0] - '0');
          }
          if (neg) *iarg = -(*iarg);
          break;
        case 'o':
          iarg = va_arg(args, int*);
          *iarg = 0;
          while ((bytes_read = read(stdin, buff, 1) == 1) && isspace(buff[0])) {
          continue;
          }
          if (!bytes_read) {
            return args_read;
          }
          if (buff[0] == '-') {
            neg = 1;
          } else *iarg = buff[0] - '0';
          while ((bytes_read = read(stdin, buff, 1) == 1) &&
            buff[0] >= '0' && buff[0] <= '7' &&
            width-- != 0) {
                *iarg = (*iarg) * 8 + (buff[0] - '0');
          }
          if (neg) *iarg = -(*iarg);
          break;
          break;
        default:
          // invalid specifier
          return args_read;
        }
        break;
      }
      args_read++;
    } else {
      read(stdin, buff, 1);
      if (buff[0] == fmt[i])
        continue;
      else {
        return args_read;
      }
    }
  }
  return args_read;
}

int scanf(const char *restrict fmt, ...) { return 0; }

int mprintf(const char *s, ...) {
  write(STDOUT_FILENO, s, strlen(s) + 1);
  return 0;
}

