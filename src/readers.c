#include "../inc/pathfinder.h"

int mx_readIslandCount(int file){
    char *line = mx_readLine(file, '\n');
    if (!mx_ifNumber(line)){
        mx_printErr("error: line 1 is not valid\n");
    }
    int count = mx_atoi(line);
    free(line);
    return count;
}

int mx_countLines(char *filename){
    int file = open(filename, O_RDONLY);
    int count = 0;
    char buff[1];
    int rd = read(file, buff, 1);
    while(rd  == 1){
        if(buff[0] == '\n') count++;
        rd = read(file, buff, 1);
    }
    close(file);
    count--;
    return count;
}

char *mx_addSym(char *text, char c){
    int len = 1;
    if (text != NULL) len += mx_strlen(text);
    char *line = mx_strnew(len);
    if (text != NULL) mx_strcpy(line, text);
    line[len - 1] = c;
    free(text);
    return line;
}

char *mx_readLine(int file, char del){
    char *s = NULL;
    char buff[1];
    int rd = read(file, buff, 1);
    if(rd < 0){
        free(s);
        return NULL;
    }
    while(rd == 1){
        if (buff[0] == del){
            s = mx_addSym(s, '\0');
            break;
        }
        s = mx_addSym(s, buff[0]);
        rd = read(file, buff, 1);
    }
    return s;
}


bool mx_validateLine(char *s){
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < mx_strlen(s) - 1; i++){
        if (!mx_isalpha(s[i]) && i == 0) {
            return false;
        } else if (!mx_isalpha(s[i]) && s[i] != '-' && flag1 == 0) {
            return false;
        } else if (!mx_isalpha(s[i]) && s[i] == '-' && flag1 == 0) {
            flag1 = 1;
        } else if (!mx_isalpha(s[i]) && s[i] != ',' && flag1 == 1 && flag2 == 0) {
            return false;
        } else if (!mx_isalpha(s[i]) && s[i] == ',' && flag1 == 1) {
            flag2 = 1;
        } else if (!mx_isalpha(s[i]) && !mx_isdigit(s[i]) && flag2 == 1 && s[i] != 3) {
            return false;
        }
    }
    return true;
}

void mx_fillLine (t_line **line, char *text){
    *line = malloc(sizeof(t_line));
    int firstLen = mx_indexOf(text, '-');
    int secondLen = mx_indexOf(text, ',');
    (*(line))->first = mx_strndup(text, firstLen);
    text += firstLen + 1;
    (*(line))->second = mx_strndup(text, secondLen - (firstLen + 1));
    text += secondLen - firstLen;
    (*(line))->length = mx_atoi(text);
}

int mx_indexOf(char *text, char delim){
    int i = 0;
    for ( ;i < mx_strlen(text); i++){
        if (text[i] == delim) return i;
    }
    return -1;
}
