#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_grep.h"

#define MAXLINE 1000

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("ERROR!");
  } else if (argc >= 3) {
    char *tmp;
    tmp = (char *)malloc(MAXLINE);
    char option;
    char *files[100];
    int cou = 0;
    char *pat;
    int flag_opt = 0;
    int flag_file = 0;
    int fl = 0;
    for (int i = 1; i < argc; i++) {
      char c;
      c = argv[i][0];
      if (c == '-') {
        option = argv[i][1];
        if (strlen(argv[i]) > 2) {
          for (int j = 0; j < strlen(argv[i]) - 2; j++) {
            tmp[j] = argv[i][j + 2];
          }
          tmp = (char *)realloc(tmp, strlen(argv[i]) - 2);
          files[cou] = tmp;
          cou++;
          fl++;
        }
        flag_opt = 1;
      } else {
        files[cou] = argv[i];
        cou++;
      }
    }
    pat = files[0];
    if (cou > 2) {
      flag_file = 1;
    }
    if (flag_opt == 0) {
      option = 'e';
      for (int i = 1; i < cou; i++) {
        options(pat, files[i], option, flag_file);
      }
    } else {
      for (int i = 1; i < cou; i++) {
        options(pat, files[i], option, flag_file);
      }
    }
    free(tmp);
  }
}
