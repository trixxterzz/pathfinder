#include "../inc/pathfinder.h"

int main(int argc, char *argv[]){
    mx_checkForFileErrors(argc, argv);
    int lineCount = mx_countLines(argv[1]);
    int file = open(argv[1], O_RDONLY);
    int islandCount = mx_readIslandCount(file);
    t_line *lines[lineCount];
    t_point points[islandCount];
    bool outputed[islandCount];
    int bridges[islandCount][islandCount];
    t_pathList *paths = NULL;
    mx_fillArrays(islandCount, lineCount, lines, points, bridges, file, outputed);
    mx_checkForSumErrors(islandCount, lines);
    close(file);
    for (int i = 0; i < islandCount; i++){
        mx_findShortest(islandCount, i, points, bridges);
        mx_fillPathList(islandCount, i, &paths, points, bridges);
        mx_sortPathList(&paths, mx_pathListComparator);
        mx_outPaths(islandCount, paths, points, outputed);
        mx_clearBridges(islandCount, points);
        outputed[i] = true;
        mx_clearPathList(&paths);
    }
    mx_clearArrays(lineCount, lines);
}

