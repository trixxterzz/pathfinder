#include "../inc/pathfinder.h"

void mx_outPaths(int size, t_pathList *list, t_point points[size], bool outputed[size]){
    for(t_pathList *i = list; i != NULL; i = i->next){
        if (outputed[i->path->second]) continue;
        for(int k = 0; k < 40; k++) mx_printstr("=");
        mx_printstr("\n");
        mx_printstr("Path: ");
        mx_printstr(points[i->path->first].name);
        mx_printstr(" -> ");
        mx_printstr(points[i->path->second].name);
        mx_printstr("\n");
        mx_printstr("Route: ");
        mx_printstr(i->path->route);
        mx_printstr("\n");
        mx_printstr("Distance: ");
        mx_printstr(i->path->bridgeArifm);
        mx_printstr("\n");
        for(int k = 0; k < 40; k++) mx_printstr("=");
        mx_printstr("\n");
    }
}

