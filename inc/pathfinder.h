#pragma once

#include "../libmx/inc/libmx.h"

typedef struct s_line{
    char *first;
    char *second;
    int length;
}              t_line;

typedef struct s_point{
    char *name;
    int shortest;
}              t_point;

typedef struct s_path{
    int first;
    int second;
    char *route;
    char *indRoute;
    char *indPath;
    char *bridgeArifm;
    int bridge;
}              t_path;

typedef struct s_pathList{
    t_path *path;
    struct s_pathList *next;
}              t_pathList;

void mx_checkForFileErrors(int argcount, char **args);
void mx_checkForSumErrors(int size, t_line *lines[size]);
bool mx_ifExists(char *filename);
bool mx_ifNotEmpty(char *filename);
void mx_printErr(char *errorText);
bool mx_ifNumber(char *num);
int mx_atoi(const char *str);
int mx_readIslandCount(int file);
int mx_countLines(char *filename);
char *mx_readLine(int file, char del);
void mx_fillLines(int size, t_line *lines[size], int file);
void mx_fillLine (t_line **line, char *text);
bool mx_validateLine(char *s);
int mx_indexOf(char *text, char delim);
char *mx_addSym(char *text, char c);
void mx_fillPoints(int size, int lineSize, t_point points[size], t_line *lines[size]);
bool mx_ifInPointsArr(int size, char *island, t_point *points);
void mx_addToPointsArr(int size, char *island, t_point *points);
int mx_getPointIndex(int size, t_point points[size], char *point);
void mx_fillBridges(int size, int lineSize, int matrix[size][size], t_line *lines[size], t_point points[size]);
void mx_findShortest(int size, int startPoint, t_point points[size], int matrix[size][size]);
void mx_fillArrays(int size, int lineSize, t_line *lines[size], t_point points[size], int bridges[size][size], int file, bool outputed[size]);
void mx_clearBridges(int size, t_point points[size]);
void mx_fillPathList(int size, int startPoint, t_pathList **list, t_point points[size], int matrix[size][size]);
t_pathList *mx_findPaths(t_pathList **list, int startInd, int endInd);
void mx_outPaths(int size, t_pathList *list, t_point points[size], bool outputed[size]);

t_pathList *mx_createPathNode(t_path *data);
void mx_pushFrontPath(t_pathList **list, t_path *data);
void mx_clearPathList(t_pathList **list);
bool mx_pathListComparator(t_pathList *a, t_pathList *b);
void mx_sortPathList(t_pathList **list, bool (*compare)(t_pathList *a, t_pathList *b));

void mx_clearArrays(int lineSize, t_line *lines[lineSize]);
