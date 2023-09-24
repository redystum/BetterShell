//
// Created by redystum on 24/09/2023.
//

#ifndef BETTERSHELL_SHELL_H
#define BETTERSHELL_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "colors.h"
#include "utils.h"

char* getUser(){
    char *username = getenv("USERPROFILE"); // output: C:\Users\redystum
    char *copy = strdup(username);
    return copy;
}

char* getUserName(){

    char *userName = getUser();

    char *user = strrchr(userName, '\\');
    memmove(user, user+1, strlen(user));

    return user;
}

char* getDisc(char *currentDir){
    char *dir = strdup(currentDir);
    char *disc = strtok(dir, ":");
    return disc;
}

char* processedDir(char *currentDir){
    char *homeDir = getUser();
    char *dir = strdup(currentDir);

    if(startsWith(homeDir, dir)){
        char *home = "~";
        char *newDir = malloc(strlen(dir) + strlen(home) - strlen(homeDir) + 1);
        strcpy(newDir, home);
        strcat(newDir, dir + strlen(homeDir));
        return newDir;
    } else {
        char *newDir = malloc(strlen(dir) - 2 + 1);
        strcpy(newDir, dir + 2);
        return newDir;
    }
}

void navigation(char *currentDir){

    green();
    printf("\n%s", getUserName());
    reset();
    printf("@");
    blue();
    printf("BetterShell");
    reset();
    printf(":");
    yellow();
    printf("(%s)%s", getDisc(currentDir), processedDir(currentDir));
    blue();
    printf("\n$> ");
    reset();
}

int execute(char *command, char *currentDir){

    char *cmd = strtok(strtok(command, " "), "\n");
    char *args = strtok(command + strlen(cmd) + 1, "\n");
    args = args == NULL ? "" : args;

    if (strstr(args, "~") != NULL) {
        char *homeDir = getUser();
        char *newArgs = malloc(strlen(args) - 1 + strlen(homeDir) + 1);
        strcpy(newArgs, homeDir);
        strcat(newArgs, args + 1);
        args = newArgs;
    }

    if(strcmp(cmd, "exit") == 0){
        return 1;
    }

    if(strcmp(cmd, "clear") == 0 || strcmp(cmd, "cls") == 0){
        cls();
        return 0;
    }

    if (strcmp(cmd, "cd") == 0) {
        chdir(args);
        return 0;
    }

    char *run = malloc(strlen(cmd) + strlen(args) + 1);
    strcpy(run, cmd);
    strcat(run, " ");
    strcat(run, args);


    if (strcmp(cmd, "ls") == 0) {
        // run ls and get the output to a string and print it separated by coma

        FILE *fp;
        char path[1035];
        fp = popen(run, "r");
        if (fp == NULL) {
            perror("Failed to run command\n" );
            return 0;
        }

        while (fgets(path, sizeof(path), fp) != NULL) {

            // fullpath = currentDir + \ + path
            char *fullPath = malloc(strlen(currentDir) + strlen(path) + 1);
            strcpy(fullPath, currentDir);
            strcat(fullPath, "\\");
            strcat(fullPath, path);

            fullPath = strtok(fullPath, "\n");

            if (isDirectory(fullPath)) {
                green();
                printf("%s", path);
                reset();
            } else {
                printf("%s", path);
            }
        }

        pclose(fp);

        free(run);
        return 0;
    }

    system(run);

    free(run);

    return 0;
}

#endif //BETTERSHELL_SHELL_H
