#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

void remake_diagram(int diagram[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2){
    
    if(x1 == x2){
        if( y1 < y2){
            for(int k = y1 ; k <= y2 ; k++){
                diagram[k][x1]++ ;
            }
        } else if( y1 > y2 ){
            for(int k = y2 ; k <= y1 ; k++){
                diagram[k][x1]++ ;
            }
        }
    
    } else if (y1 == y2){
        
        if(x1 < x2) {
            for(int k = x1; k <= x2 ; k++){
                diagram[y1][k]++ ;
            }
        } else if(x1 > x2){
           for(int k = x2; k <= x1 ; k++){
                diagram[y1][k]++ ;
            } 
        }
    }
}


int main(void){
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }
    
    int x1, y1, x2, y2 ;
    int points = 0 ;

    int diagram[MAX_SIZE][MAX_SIZE] = {{0}} ; // create the starting diagram and initilize every cell as zero //

    
    while (fscanf(fp, "%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2) == 4) {
        remake_diagram(diagram, x1, y1, x2, y2);
    }
    
    for (int i = 0; i < MAX_SIZE; i++){
        for(int j = 0 ; j < MAX_SIZE ; j++){
            if(diagram[i][j] >= 2){
                points++; 
            }
        }   
    }

    fprintf(stderr, "Points where at least two lines overlap: %d\n", points);
    
    fclose(fp);
    return 0;
}