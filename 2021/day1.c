#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 2000


int is_larger(int line[], int line_number){
    int count = 0;  
    for(int i = 0; i < line_number ; i++){
        if (line[i]> line[i-1]){
            count++;
        }
    }
    return count ;
}


int main(void){ 
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }
    
    int line_number = 0;
    char buffer[256];
    int line[MAX_LINES];
    
    // read each line of the file //
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        int number = atoi(buffer);
        line[line_number] = number;
        line_number++;
    }

    int result = is_larger(line, line_number);
    fprintf(stderr,"%d measurements larger than the previous one\n", result);

    fclose(fp);
    return 0;
}