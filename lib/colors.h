//
// Created by redystum on 24/09/2023.
//

#ifndef BETTERSHELL_COLORS_H
#define BETTERSHELL_COLORS_H

#include <stdio.h>

void black(){
    printf("\033[0;30m");
}

void red(){
    printf("\033[0;31m");
}

void green(){
    printf("\033[0;32m");
}

void yellow(){
    printf("\033[0;33m");
}

void blue(){
    printf("\033[0;34m");
}

void magenta(){
    printf("\033[0;35m");
}

void cyan(){
    printf("\033[0;36m");
}

void white(){
    printf("\033[0;37m");
}

void reset(){
    printf("\033[0m");
}

void bold(){
    printf("\033[1m");
}

void underline(){
    printf("\033[4m");
}

void blink(){
    printf("\033[5m");
}

void reverse(){
    printf("\033[7m");
}

void invisible(){
    printf("\033[8m");
}

void black_bg(){
    printf("\033[40m");
}

void red_bg(){
    printf("\033[41m");
}

void green_bg(){
    printf("\033[42m");
}

void yellow_bg(){
    printf("\033[43m");
}

void blue_bg(){
    printf("\033[44m");
}

void magenta_bg(){
    printf("\033[45m");
}

void cyan_bg(){
    printf("\033[46m");
}

void white_bg(){
    printf("\033[47m");
}

void reset_bg(){
    printf("\033[49m");
}

void bold_off(){
    printf("\033[21m");
}

void underline_off(){
    printf("\033[24m");
}

void blink_off(){
    printf("\033[25m");
}

void reverse_off(){
    printf("\033[27m");
}

void invisible_off(){
    printf("\033[28m");
}

void black_bg_off(){
    printf("\033[40m");
}

void red_bg_off(){
    printf("\033[41m");
}

void green_bg_off(){
    printf("\033[42m");
}

void yellow_bg_off(){
    printf("\033[43m");
}

void blue_bg_off(){
    printf("\033[44m");
}

void magenta_bg_off(){
    printf("\033[45m");
}

void cyan_bg_off(){
    printf("\033[46m");
}

void white_bg_off(){
    printf("\033[47m");
}

void reset_bg_off(){
    printf("\033[49m");
}

void reset_all(){
    printf("\033[0m");
}

void clear_screen(){
    printf("\033[2J");
}

void clear_line(){
    printf("\033[K");
}

void move_cursor(int x, int y){
    printf("\033[%d;%dH", x, y);
}

void move_cursor_up(int n){
    printf("\033[%dA", n);
}

void move_cursor_down(int n){
    printf("\033[%dB", n);
}

void move_cursor_right(int n){
    printf("\033[%dC", n);
}

void move_cursor_left(int n){
    printf("\033[%dD", n);
}

void save_cursor(){
    printf("\033[s");
}

void restore_cursor(){
    printf("\033[u");
}

void hide_cursor(){
    printf("\033[?25l");
}

void show_cursor(){
    printf("\033[?25h");
}

void set_title(char *title){
    printf("\033]0;%s\007", title);
}

void set_icon(char *icon){
    printf("\033]1;%s\007", icon);
}

void set_icon_and_title(char *title, char *icon){
    printf("\033]0;%s\007", title);
    printf("\033]1;%s\007", icon);
}


#endif //BETTERSHELL_COLORS_H
