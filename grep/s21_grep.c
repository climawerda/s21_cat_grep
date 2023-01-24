#ifndef S21_GREP_C
#define S21_GREP_C
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void options(char *pat, char *filename, char opt, int flag) {
  FILE *f;
  f = fopen(filename, "r");
  char line[BUFSIZE];
  int count = 0;
  int line_count = 1;
  int cflags = REG_EXTENDED;
  regex_t reg;
  if ((f == 0) && (opt != 's')) {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    exit(1);
  } else if ((f == 0) && (opt == 's')) {
    exit(1);
  } else {
    if (opt == 'i') {
      cflags |= REG_ICASE;
    }
    regcomp(&reg, pat, cflags);
    while (fgets(line, BUFSIZE, f) != NULL) {
      int suc = regexec(&reg, line, 0, NULL, 0);
      if (opt == 'v') {
        if ((suc == 1) && (flag == 0)) {
          printf("%s", line);
        } else if ((suc == 1) && (flag == 1)) {
          printf("%s:%s", filename, line);
        }
      }
      if (opt == 'e') {
        if ((suc == 0) && (flag == 0)) {
          printf("%s", line);
        } else if ((suc == 0) && (flag == 1)) {
          printf("%s:%s", filename, line);
        }
      }
      if (opt == 'i') {
        if ((suc == 0) && (flag == 0)) {
          printf("%s", line);
        } else if ((suc == 0) && (flag == 1)) {
          printf("%s:%s", filename, line);
        }
      }
      if (opt == 'h') {
        if (suc == 0) {
          printf("%s", line);
        }
      }
      if (opt == 'c') {
        if (suc == 0) {
          count++;
        }
      }
      if (opt == 'n') {
        if ((flag == 0) && (suc == 0)) {
          printf("%d:%s", line_count, line);
        } else if ((flag == 1) && (suc == 0)) {
          printf("%s:%d:%s", filename, line_count, line);
        }
      }
      if (opt == 'l') {
        if (suc == 0) {
          printf("%s\n", filename);
          break;
        }
      }
      line_count++;
    }
    if (opt == 'c') {
      if (flag == 0) {
        printf("%d\n", count);
      } else {
        printf("%s:%d\n", filename, count);
      }
    }
    regfree(&reg);
    fclose(f);
  }
}

#endif
