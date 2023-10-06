#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "lib/shell.h"


int main() {

    setlocale(LC_ALL, "");

    char currentDir[FILENAME_MAX];

    cls();

    while (1) {
        if (getcwd(currentDir, sizeof(currentDir)) != NULL) {

            navigation(currentDir);

            char command[FILENAME_MAX];
            fgets(command, sizeof(command), stdin);

            if (
                    strcmp(command, "\n") == 0 ||
                    strcmp(command, "\r\n") == 0 ||
                    strcmp(command, "\r") == 0 ||
                    strcmp(command, "\0") == 0 ||
                    strcmp(trim(command), "") == 0
            ) {
                continue;
            }

            int result = execute(command, currentDir);

            if (result == 1) {
                break;
            }
        } else {
            perror("Please run this program in a directory on call it from terminal.");
            system("pause");
            return 1;
        }

    }

    return 0;
}
