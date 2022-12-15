#include "../inc/pathfinder.h"

void mx_fillArrays(int size, int lineSize, t_line *lines[lineSize], t_point points[size], int bridges[size][size], int file, bool outputed[size]){
    for (int i = 0; i < size; i++){
        points[i].name = NULL;
        points[i].shortest = -1;
        for (int j = 0; j < size; j++){
            bridges[i][j] = -1;
        }
        outputed[i] = false;
    }
    for (int i = 0; i < lineSize; i++){

    }
    mx_fillLines(lineSize, lines, file);
    mx_fillPoints(size, lineSize, points, lines);
    mx_fillBridges(size, lineSize, bridges, lines, points);
}

void mx_clearArrays(int lineSize, t_line *lines[lineSize]){
    for (int i = 0; i < lineSize; i++){
        free(lines[i]->first);
        free(lines[i]->second);
        free(lines[i]);
    }
}

void mx_fillLines(int size, t_line *lines[size], int file){
    for(int i = 0; i < size; i++){
        char *line = mx_readLine(file, '\n');
        if (!mx_validateLine(line)){
            mx_printErr("line number ");
            mx_printErr(mx_itoa(i + 1));
            mx_printErr(" is invalid\n");
            exit(1);
        }
        mx_fillLine(&(lines[i]), line);
        free(line);
    }
}

void mx_fillPoints(int size, int lineSize, t_point points[size], t_line *lines[size]){
    for(int i = 0; i < lineSize; i++){
        if (!mx_ifInPointsArr(size, lines[i]->first, points)) mx_addToPointsArr(size, lines[i]->first, points);
        if (!mx_ifInPointsArr(size, lines[i]->second, points)) mx_addToPointsArr(size, lines[i]->second, points);
    }
}

void mx_fillBridges(int size, int lineSize, int matrix[size][size], t_line *lines[size], t_point points[size]){
    for(int i = 0; i < lineSize; i++){
        int firstInd = mx_getPointIndex(size, points, lines[i]->first);
        int secondInd = mx_getPointIndex(size, points, lines[i]->second);
        if (matrix[firstInd][secondInd] > -1 || matrix[secondInd][firstInd] > -1 || firstInd == secondInd){
            mx_printErr("error: duplicate bridges\n");
        }
        if (firstInd < 0 || secondInd < 0){
            mx_printErr("some error occured\n");
            exit(1);
        }
        matrix[i][i] = -1;
        matrix[firstInd][secondInd] = lines[i]->length;
        matrix[secondInd][firstInd] = lines[i]->length;
    }
}


