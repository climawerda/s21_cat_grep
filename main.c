#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#define MAXLINE 1000

int main(int argc, char* argv[]) {
    int i = 1;
    if (argc == 2) {
        nofile();
    } else if (argv[2][0] == '-') {
        for (int i = 3; i < argc; i++) {
            optional(argv[2], argv[i]);
        }
    } else {
        for (int i = 2; i < argc; i++) {
            nooption(argv[i]);
        }
    }
    return 0;
}

