#include "../inc/pathfinder.h"


void mx_fillPathList(int size, int startPoint, t_pathList **list, t_point points[size], int matrix[size][size]){
    bool changed = true;
    while(changed){
        changed = false;
        for (int i = 0; i < size; i++){
            if(points[i].shortest >= 0){
                for (int j = 0; j < size; j++){
                    if(matrix[i][j] >= 0 && points[i].shortest + matrix[i][j] == points[j].shortest){
                        t_pathList *check = mx_findPaths(list, i, j);
                        if (i == startPoint && check == NULL){
                            t_path *new = malloc(sizeof(t_path));
                            new->first = startPoint;
                            new->second = j;
                            char *buff = mx_strdup(points[i].name);
                            char *temp = buff;
                            buff = mx_strjoin(temp, " -> ");
                            free(temp);
                            temp = buff;
                            buff = mx_strjoin(temp, points[j].name);
                            free(temp);
                            new->route = buff;
                            char *itoaed = mx_itoa(i);
                            char *buffIndRoute = mx_strdup(itoaed);
                            temp = buffIndRoute;
                            buffIndRoute = mx_strjoin(temp, " -> ");
                            free(itoaed);
                            free(temp);
                            temp = buffIndRoute;
                            itoaed = mx_itoa(j);
                            buffIndRoute = mx_strjoin(temp, itoaed);
                            free(itoaed);                            
                            free(temp);
                            new->indRoute = buffIndRoute;
                            new->bridgeArifm = mx_itoa(points[j].shortest);
                            new->bridge = points[j].shortest;
                            itoaed = mx_itoa(startPoint);
                            char *buffIndPath = mx_strdup(itoaed);
                            temp = buffIndPath;
                            buffIndPath = mx_strjoin(temp, " -> ");
                            free(itoaed);
                            free(temp);
                            temp = buffIndPath;
                            itoaed = mx_itoa(j);
                            buffIndPath = mx_strjoin(temp, itoaed);
                            free(itoaed);
                            free(temp);
                            new->indPath = buffIndPath;
                            mx_pushFrontPath(list, new);
                        }
                        else{
                            t_pathList *buffList = mx_findPaths(list, startPoint, i);
                            for (t_pathList *node = buffList; node != NULL; node = node->next){
                                t_path *new = malloc(sizeof(t_path));
                                new->first = startPoint;
                                new->second = j;
                                char *buff = mx_strjoin(node->path->route, " -> ");
                                char *temp = buff;
                                buff = mx_strjoin(temp, points[j].name);
                                free(temp);
                                new->route = buff;
                                char *buffIndRoute = mx_strjoin(node->path->indRoute, " -> ");
                                temp = buffIndRoute;
                                char *itoaed = mx_itoa(j);
                                buffIndRoute = mx_strjoin(temp, itoaed);
                                new->indRoute = buffIndRoute;
                                free(itoaed);
                                free(temp);
                                char *buffBridgeArifm = mx_strjoin(node->path->bridgeArifm, " + ");
                                temp = buffBridgeArifm;
                                itoaed = mx_itoa(matrix[i][j]);
                                buffBridgeArifm = mx_strjoin(temp, itoaed);
                                free(itoaed);
                                free(temp);
                                new->bridgeArifm = buffBridgeArifm;
                                new->bridge = points[j].shortest;
                                itoaed = mx_itoa(startPoint);
                                char *buffIndPath = mx_strdup(itoaed);
                                temp = buffIndPath;
                                buffIndPath = mx_strjoin(temp, " -> ");
                                free(itoaed);
                                free(temp);
                                temp = buffIndPath;
                                itoaed = mx_itoa(j);
                                buffIndPath = mx_strjoin(temp, itoaed);
                                free(itoaed);
                                free(temp);
                                new->indPath = buffIndPath;
                                mx_pushFrontPath(list, new);
                            }
                            t_pathList *head = buffList;
                            while(head != NULL){
                                t_pathList *buff = head;
                                head = head->next;
                                free(buff);
                            }
                        }
                    }
                }
            }
        }
    }
    for (t_pathList *i = *list; i != NULL; i = i->next){
        if (mx_strchr(i->path->bridgeArifm, '+') != NULL){
            char *temp = i->path->bridgeArifm;
            i->path->bridgeArifm = mx_strjoin(temp, " = ");
            free(temp);
            temp = i->path->bridgeArifm;
            char *itoaed = mx_itoa(i->path->bridge);
            i->path->bridgeArifm = mx_strjoin(temp, itoaed);
            free(itoaed);
            free(temp);
        }
    }
}

void mx_pushFrontPath(t_pathList **list, t_path *data){
    t_pathList *new = mx_createPathNode(data);
    if (new == NULL) return;
    new->next = *list;
    *list = new;
}

t_pathList *mx_createPathNode(t_path *data){
    t_pathList *node = malloc(sizeof(t_pathList));
    if (node == NULL) return NULL;
    node->path = data;
    node->next = NULL;
    return node;
}

void mx_clearPathList(t_pathList **list){
    if (list == NULL) return;
    t_pathList *head = *list;
    while(head != NULL){
        t_pathList *buff = head;
        head = head->next;
        free(buff->path->bridgeArifm);
        free(buff->path->indPath);
        free(buff->path->indRoute);
        free(buff->path->route);
        free(buff->path);
        free(buff);
    }
    *list = NULL;
    return;
}

void mx_sortPathList(t_pathList **list, bool (*compare)(t_pathList *a, t_pathList *b)){
    if (list == NULL) return;
    bool sorted = true;
    while(sorted){
        sorted = false;
        for (t_pathList *i = *list; i->next != NULL; i = i->next){
            t_pathList *buff = i;
            t_pathList *buffNext = i->next;
            if(compare(buff, buffNext)){
                sorted = true;
                t_path *temp = buff->path;
                buff->path = buffNext->path;
                buffNext->path = temp;
            }
        }
    }
}

bool mx_pathListComparator(t_pathList *a, t_pathList *b){
    if (mx_strcmp(a->path->indPath, b->path->indPath) > 0) return true;
    if (mx_strcmp(a->path->indPath, b->path->indPath) == 0 && mx_strcmp(a->path->indRoute, b->path->indRoute) > 0) return true; 
    return false;
}

t_pathList *mx_findPaths(t_pathList **list, int startInd, int endInd){
    t_pathList *new = NULL;
    for (t_pathList *i = *list; i != NULL; i = i->next){
        if (i->path->first == startInd && i->path->second == endInd){
            mx_pushFrontPath(&new, i->path);
        }
    }
    return new;
}
