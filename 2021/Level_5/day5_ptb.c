#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void remake_diagram(int diagram[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2){
    // diagram[x1][y1] = 9; // example to debug the problem
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

     if(y1 == x1 && y2 == x2){                   // code diagonals correctly !
        if(x1 < x2){                            // as an example 1,1 -> 3,3 covers points 1,1, 2,2, and 3,3
            for(int k = x1 ; k <= x2 ; k++){
                diagram[k][k]++;
            }
        } else if (x1 > x2) {
            for(int k = x1 ; k >= x2 ; k--){
                diagram[k][k]++;
            }
        } 

    } else if (x1 < x2) {
        if(y1 < y2){
            for(int k = x1 ; k <= x2 ; k++){
                for(int j = y1 ; j <= y2 ; j++){
                    diagram[k][j]++ ;
                    k++;
                }
            }
        } else if (y1 > y2){
            for(int k = x1 ; k <= x2 ; k++){
                for(int j = y2 ; j <= y1 ; j++){
                    //diagram[k][j]++ ;
                    k++;
                }
            }
        }  
    
    } 
    
    // check it again !!
    if (x1 == y2 && y1 == x2){
        if(x1 > x2 && y1 < y2){
            for (int j = y1 ; j <= y2; j++) {
                diagram[j][y2-j]++;  
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
    
    int x1, y1, x2, y2;
    int points = 0;
    
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

    // Print the updated diagram
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (diagram[i][j] != 0) {
                printf("%d ", diagram[i][j]);
            } else {
                printf(". ");
            }
        }   
        printf("\n");
    }

    fprintf(stderr, "Points where at least two lines overlap: %d\n", points);
    
    fclose(fp);
    return 0;
}