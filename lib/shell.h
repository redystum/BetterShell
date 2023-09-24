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
    printf("%s", getUserName());
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

int execute(char *command){

    char *cmd = strtok(command, " ");
    char *args = strtok(NULL, "\n");

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

    system(command);

    return 0;
}

#endif //BETTERSHELL_SHELL_H
