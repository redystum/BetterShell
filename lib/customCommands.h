//
// Created by redystum on 06/10/2023.
//

#ifndef BETTERSHELL_CUSTOMCOMMANDS_H
#define BETTERSHELL_CUSTOMCOMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "colors.h"
#include "utils.h"

int ls(char *run, char *currentDir) {
    FILE *fp;
    char path[4096];
    fp = popen(run, "r");
    if (fp == NULL) {
        perror("Failed to run command\n");
        return 0;
    }

    int lineSize = 0;
    int width = getTerminalWidth();
    while (fgets(path, sizeof(path), fp) != NULL) {

        path[strcspn(path, "\n")] = 0;

        lineSize += strlen(path) + 12;

        // basically this is wrong if I run ls ~ the fullpath will be the opened/directory/fileFromHome instead of C:\Users\redystum\fileFromHome
        char *fullPath = malloc(strlen(currentDir) + strlen(path) + 1);
        strcpy(fullPath, currentDir);
        strcat(fullPath, "\\");
        strcat(fullPath, path);

        fullPath = strtok(fullPath, "\n");

        if (isDirectory(fullPath)) {
            green();
            printf("%s  \t", path);
            reset();
        } else {
            printf("%s  \t", path);
        }

        if (lineSize >= width) {
            printf("\n");
            lineSize = 0;
        }
    }

    pclose(fp);

    free(run);
    return 0;
}

int la(char *currentDir, char *args){
    char *customRun = malloc(strlen("ls -a") + strlen(args) + 1);
    strcpy(customRun, "ls -a");
    strcat(customRun, " ");
    strcat(customRun, args);
    return ls(customRun, currentDir);
}

#endif //BETTERSHELL_CUSTOMCOMMANDS_H