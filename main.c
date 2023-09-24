#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/shell.h"


int main() {

    char currentDir[FILENAME_MAX];

    cls();

    while (1) {
        if (getcwd(currentDir, sizeof(currentDir)) != NULL) {

            navigation(currentDir);

            char command[FILENAME_MAX];
            fgets(command, sizeof(command), stdin);

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
