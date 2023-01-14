#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("ERROR!");
    } else if (argc >= 3) {
        char *option;
        char *files[100];
        int cou = 0;
        int flag_opt = 0;

        for (int i = 2; i < argc; i++) {
            char c;
            c = argv[i][0];
            if (c == '-') {
                option = argv[i];
                flag_opt = 1;
            } else {
                files[cou] = argv[i];
                printf("file = %s\n", files[cou]);
                cou++;
            }
        }
        if (flag_opt == 0) {
            printf("ABOBA");
        } else {
            printf("option = %s\n", option);
        }
    }
}