//
// Created by rffar on 24/09/2023.
//

#ifndef BETTERSHELL_UTILS_H
#define BETTERSHELL_UTILS_H

#include <stdbool.h>
#include <corecrt.h>
#include <string.h>

bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
            lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}

void cls(){
    system("cls");
}

#endif //BETTERSHELL_UTILS_H
