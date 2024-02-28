#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 2000

// function that calculates the three-measurement windows //
// for every line add to the first number the numbers of the next 2 lines //
void get_sum(int line[], int line_number, int sum[]){
    for(int i = 0; i < line_number ; i++){
        sum[i] = 0 ;
        for(int j = 0 ; j < 3; j++){
            sum[i]+= line[j+i]; 
        }
    }
}

int is_larger(int sum_line[], int line_number){
    int count = 0;  
    for(int i = 0; i < line_number ; i++){
        if (sum_line[i] > sum_line[i-1]){
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

    int sum[line_number];
    get_sum(line, line_number, sum);
    int result = is_larger(sum, line_number);
    fprintf(stderr,"%d sums that are larger than the previous sum\n", result);

    fclose(fp);
    return 0;
}