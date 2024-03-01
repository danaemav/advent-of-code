#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_CHARS 100

void calculations(char line[], int *horizontal, int *depth, int *aim) {
    // according to the first letter, update the horizontal and depth position //
    switch (line[0]) {
        case 'f':
            *horizontal += (line[8] - '0');
            *depth += *aim * (line[8] - '0');
            break;
        case 'd':
            *aim += (line[5] - '0');
            break;
        case 'u':
            *aim -= (line[3] - '0');
            break;
    }
    printf("Current position: %d , %d\n", *horizontal, *depth);
}


int main(void) {
    
    // check if the file opened successfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    char line[MAX_LINE_CHARS];
    int horizontal = 0, depth = 0, aim = 0;
    
    // read each line of the file //
    while (fgets(line, sizeof(line), fp) != NULL) {
        calculations(line, &horizontal, &depth, &aim);
    }

    int result = horizontal * depth ;
    fprintf(stderr, "Result = %d\n", result);

    fclose(fp);
    return 0;
}