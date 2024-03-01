#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_CHARS 100


void calculations(char line[], int horizontal, int depth){
    
    int size = strlen(line);
    
    for (int i = 0; i < size; i++){
        switch(line[i]){
            case 'f':
                horizontal = horizontal + (line[i + 8] - '0');
                break;
            case 'd':
                depth = depth + (line[i + 5] - '0');
                break;
            case 'u':
                depth = depth - (line[i + 3] - '0');
                break;
        }
    }
    printf("horizontal : %d , depth : %d\n", horizontal, depth);

}



int main(void){
    
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }
    
    char line[MAX_LINE_CHARS];
    int horizontal = 0, depth = 0 ;
    
    // read each line of the file //
    while (fgets(line, sizeof(line), fp) != NULL) {
        
        calculations(line, horizontal, depth);

    }

    int result = horizontal * depth; 

    fprintf(stderr, "Result final = %d\n", result );

    fclose(fp);
    return 0;
}