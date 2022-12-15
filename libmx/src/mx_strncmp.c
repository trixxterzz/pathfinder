#include "../inc/libmx.h"

int mx_strncmp(const char*s1, const char*s2, int n){
    for (int i = 0; i < n; i++){
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        } 
        else{
            if(s1[i] == '\0' && s2[i] == '\0'){
                return 0;
            }
        }

    }   
    return 0;
}

