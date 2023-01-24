#ifndef S21_CAT_C
#define S21_CAT_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

static const char* const symb[255] = {
    [0] = "^@",      [1] = "^A",     [2] = "^B",     [3] = "^C",
    [4] = "^D",      [5] = "^E",     [6] = "^F",     [7] = "^G",
    [8] = "^H",      [9] = " ",      [10] = "\n",    [11] = "^K",
    [12] = "^L",     [13] = "^M",    [14] = "^N",    [15] = "^O",
    [16] = "^P",     [17] = "^Q",    [18] = "^R",    [19] = "^S",
    [20] = "^T",     [21] = "^U",    [22] = "^V",    [23] = "^W",
    [24] = "^X",     [25] = "^Y",    [26] = "^Z",    [27] = "^[",
    [28] = "^\\",    [29] = "^]",    [30] = "^^",    [31] = "^_",
    [32] = " ",      [33] = "!",     [34] = "\"",    [35] = "#",
    [36] = "$",      [37] = "%",     [38] = "&",     [39] = "'",
    [40] = "(",      [41] = ")",     [42] = "*",     [43] = "+",
    [44] = ",",      [45] = "-",     [46] = ".",     [47] = "/",
    [48] = "0",      [49] = "1",     [50] = "2",     [51] = "3",
    [52] = "4",      [53] = "5",     [54] = "6",     [55] = "7",
    [56] = "8",      [57] = "9",     [58] = ":",     [59] = ";",
    [60] = "<",      [61] = "=",     [62] = ">",     [63] = "?",
    [64] = "@",      [65] = "A",     [66] = "B",     [67] = "C",
    [68] = "D",      [69] = "E",     [70] = "F",     [71] = "G",
    [72] = "H",      [73] = "I",     [74] = "J",     [75] = "K",
    [76] = "L",      [77] = "M",     [78] = "N",     [79] = "O",
    [80] = "P",      [81] = "Q",     [82] = "R",     [83] = "S",
    [84] = "T",      [85] = "U",     [86] = "V",     [87] = "W",
    [88] = "X",      [89] = "Y",     [90] = "Z",     [91] = "[",
    [92] = "\\",     [93] = "]",     [94] = "^",     [95] = "_",
    [96] = "`",      [97] = "a",     [98] = "b",     [99] = "c",
    [100] = "d",     [101] = "e",    [102] = "f",    [103] = "g",
    [104] = "h",     [105] = "i",    [106] = "j",    [107] = "k",
    [108] = "l",     [109] = "m",    [110] = "n",    [111] = "o",
    [112] = "p",     [113] = "q",    [114] = "r",    [115] = "s",
    [116] = "t",     [117] = "u",    [118] = "v",    [119] = "w",
    [120] = "x",     [121] = "y",    [122] = "z",    [123] = "{",
    [124] = "|",     [125] = "}",    [126] = "~",    [127] = "^?",
    [128] = "M-^@",  [129] = "M-^A", [130] = "M-^B", [131] = "M-^C",
    [132] = "M-^D",  [133] = "M-^E", [134] = "M-^F", [135] = "M-^G",
    [136] = "M-^H",  [137] = "M-^I", [138] = "M-^J", [139] = "M-^K",
    [140] = "M-^L",  [141] = "M-^M", [142] = "M-^N", [143] = "M-^O",
    [144] = "M-^P",  [145] = "M-^Q", [146] = "M-^R", [147] = "M-^S",
    [148] = "M-^T",  [149] = "M-^U", [150] = "M-^V", [151] = "M-^W",
    [152] = "M-^X",  [153] = "M-^Y", [154] = "M-^Z", [155] = "M-^[",
    [156] = "M-^\\", [157] = "M-^]", [158] = "M-^^", [159] = "M-^_",
};

void flag_v(char c) { printf("%s", symb[(int)c]); }

int optional(char* option, char* filename) {
  FILE* f;
  f = fopen(filename, "r");
  if (strcmp(option, "-b") == 0 || strcmp(option, "--number-nonblank") == 0) {
    int i = 1;
    if (f == 0) {
      printf("cat: %s: No such file or directory", filename);
      exit(1);
    } else {
      char line[BUFSIZE];
      while (fgets(line, BUFSIZE, f) != NULL) {
        if (strlen(line) <= 1) {
          printf("%s", line);
        } else {
          printf("%6.d\t%s", i, line);
          i++;
        }
      }
    }
  } else if (strcmp(option, "-n") == 0 || strcmp(option, "--number") == 0) {
    int i = 1;
    if (f == 0) {
      printf("cat: %s: No such file or directory", filename);
      exit(1);
    } else {
      char line[BUFSIZE];
      while (fgets(line, BUFSIZE, f) != NULL) {
        printf("%6.d\t%s", i, line);
        i++;
      }
    }
  } else if (strcmp(option, "-E") == 0 || strcmp(option, "-e") == 0) {
    if (f == 0) {
      printf("cat: %s: No such file or directory", filename);
      exit(1);
    } else {
      char line[BUFSIZE];
      while (fgets(line, BUFSIZE, f) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
          if ((line[i] != '\n') && strcmp(option, "-E") == 0) {
            printf("%c", line[i]);
          } else if ((line[i] != '\n') && strcmp(option, "-e") == 0) {
            flag_v(line[i]);
          } else {
            printf("$\n");
          }
        }
      }
    }
  } else if (strcmp(option, "-T") == 0 || strcmp(option, "-t") == 0) {
    if (f == 0) {
      printf("cat: %s: No such file or directory", filename);
      exit(1);
    } else {
      char line[BUFSIZE];
      while (fgets(line, BUFSIZE, f) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
          if ((line[i] != '\t') && strcmp(option, "-T") == 0) {
            printf("%c", line[i]);
          } else if ((line[i] != '\t') && strcmp(option, "-t") == 0) {
            flag_v(line[i]);
          } else {
            printf("^I");
          }
        }
      }
    }
  } else if (strcmp(option, "-s") == 0 ||
             strcmp(option, "--squeeze-blank") == 0) {
    if (f == 0) {
      printf("cat: %s: No such file or directory", filename);
      exit(1);
    } else {
      char line[BUFSIZE];
      int flag = 0;
      while (fgets(line, BUFSIZE, f) != NULL) {
        if (strcmp(line, "\n") == 0 && flag == 0) {
          printf("%s", line);
          flag = 1;
        } else if (strcmp(line, "\n") != 0) {
          printf("%s", line);
          flag = 0;
        }
      }
    }
  }
  fclose(f);
  return 0;
}

int nofile() {
  char buf[BUFSIZE];
  while (fgets(buf, BUFSIZE, stdin)) {
    int len = strlen(buf);
    buf[len - 1] = '\0';
    fprintf(stdout, "%s\n", buf);
  }
  return 0;
}

int nooption(char* filename) {
  FILE* f;
  f = fopen(filename, "r");
  if (f == 0) {
    printf("cat: %s: No such file or directory", filename);
    exit(1);
  } else {
    char line[BUFSIZE];
    while (fgets(line, BUFSIZE, f) != NULL) {
      printf("%s", line);
    }
  }
  fclose(f);
  return 0;
}
#endif

