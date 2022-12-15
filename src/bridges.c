#include "../inc/pathfinder.h"

int mx_getPointIndex(int size, t_point points[size], char *point){
    for(int i = 0; i < size; i++){
        if (mx_strcmp(points[i].name, point) == 0) return i;
    }
    return -1;
}

void mx_findShortest(int size, int startPoint, t_point points[size], int matrix[size][size]){
    points[startPoint].shortest = 0;
    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0; i < size; i++){
            if(points[i].shortest >= 0){
                for(int j = 0; j < size; j++){
                    if(matrix[i][j] >= 0 && (points[i].shortest + matrix[i][j] < points[j].shortest || points[j].shortest < 0)){
                        changed = true;
                        points[j].shortest = points[i].shortest + matrix[i][j];
                    }
                }
            }
        }
    }
}

void mx_clearBridges(int size, t_point points[size]){
    for (int i = 0; i < size; i++) points[i].shortest = -1;
}

