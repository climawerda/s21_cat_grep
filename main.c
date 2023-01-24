#include <stdio.h>
#include <stdlib.h>

#include "s21_cat.h"
#define MAXLINE 1000

int main(int argc, char* argv[]) {
  int i = 1;
  if (argc == 1) {
    nofile();
  } else if (argv[1][0] == '-') {
    for (int i = 2; i < argc; i++) {
      optional(argv[1], argv[i]);
    }
  } else {
    for (int i = 1; i < argc; i++) {
      nooption(argv[i]);
    }
  }
  return 0;
}


