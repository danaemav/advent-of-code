#include <stdio.h>

int get_sum(char *line[]){
    int sum = 0 ;
    int size = strlen(line);
    for (int i = 0; i < size; i++){
        if (isdigit(line[i])){

        }
    }
}


int main(void){
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    char line[MAX_LINE_CHARS];
    
}