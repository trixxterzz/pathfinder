#include "../inc/pathfinder.h"

void mx_checkForFileErrors(int argcount, char **args){
    if (argcount != 2){
        mx_printErr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    if(!mx_ifExists(args[1])){
        mx_printErr("error: file ");
        mx_printErr(args[1]);
        mx_printErr(" does not exist\n");
        exit(1);
    }
    if(!mx_ifNotEmpty(args[1])){
        mx_printErr("error: file ");
        mx_printErr(args[1]);
        mx_printErr(" is empty\n");
        exit(1);
    }
}

void mx_checkForSumErrors(int size, t_line *lines[size]){
    int sum =0;
    for (int i = 0; i < size; i++){
        sum += lines[i]->length;
        if (sum > __INT_MAX__){
            mx_printErr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }
}

void mx_printErr(char *errorText){
    write(2, errorText, mx_strlen(errorText));
}


