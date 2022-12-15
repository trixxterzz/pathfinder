#include "../inc/pathfinder.h"

int mx_atoi(const char *str){
    int flag = 0;
    int count = 0;
    int num = 0;
    while(*str != '\0'){
        if (*str > 47 && *str < 58){
            num *= 10;
            num += *str - 48;
        }
        else if(*str == '-'){
            flag = 1;
            count++;
        }
        else if(*str == '+'){
            count++;
        }
        str++;
        if(count > 1){
            break;
        }
    }
    if (flag == 1){
        return num * -1;
    }
    else {
        return num;
    }
}

bool mx_ifExists(char *filename){
    int file = open(filename, O_RDONLY);
    if (file < 0) return false;
    close(file);
    return true;
}

bool mx_ifNotEmpty(char *filename){
    int file = open(filename, O_RDONLY);
    char buff[1];
    int isRead = read(file, &buff, 1);
    if(isRead < 1) return false;
    close(file);
    return true;
}

bool mx_ifNumber(char *num){
    while(*num != 3 && *num != '\0'){
        if (*num < '0' || *num > '9'){
            return false;
        }
        num++;
    }
    return true;
}

bool mx_ifInPointsArr(int size, char *island, t_point *points){
    for (int i = 0; i < size; i++){
        if(points[i].name == NULL) break;
        if(mx_strcmp(island, points[i].name) == 0) return true;
    }
    return false;
}

void mx_addToPointsArr(int size, char *island, t_point *points){
    for(int i = 0; i < size; i++){
        if(points[i].name == NULL){
            points[i].name = island;
            return;
        }
    }
    mx_printErr("error: invalid number of lines\n");
    exit(1);
}

