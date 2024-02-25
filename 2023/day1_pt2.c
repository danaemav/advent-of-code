#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_CHARS 1024

bool isnamestart(char ch){
    return (ch == "o" || ch == "t" || ch == "f" || ch == "s" || ch == "e" || ch == "n");
}

int find_arithmetic(char line[]){

    int size = strlen(line);
    int dig1 = 0, dig2 = 0;
    int pos_num = -1, pos_name = -1, countline;
    
    for(int i = 0; i < size; i++){

        bool possible_num = true ;
        if (isalpha(line[i]) && isnamestart(line[i])){
            
            pos_name = i;                       // if possible to be alphabetical num keep it sposition //
            for (int j = 1 ; j <= 5 , j++){                 // i check it for one-digit numbers for now  //
                if(!isalpha(line[j])) {
                    possible_num = false;
                }
            }
        }
    }
}


// much stuff missing and gone wrong //
// need modifications to get the positions and compare them //
// check notes.txt



// function that finds the first and last digits from a line and calculates the calibration value //
int find_calibration(char line[]){
    
    int size = strlen(line);
    int dig1 = 0, dig2 = 0;
    int pos1 = 0, countline;
    
    for(int i = 0; i < size; i++){
        countline = i ;
        if(isdigit(line[i])) {      // search for a digit starting from the front of the line //
            dig1 = line[i] -'0';    // convert char ascii code to decimal value //
            pos1 = i;               // if it is found, store its position and break loop //
            break;
        }
    }
    if (pos1 != 0 || (pos1 == 0 && countline == 0)) {                              // if a digit exists //
        for(int i = size ; i > pos1; i--){        // iterate from the back of line to the position of digit1 //
            if(isdigit(line[i])){
                dig2 = line[i] - '0';
                break;
            }
        }
    } else {
        return 0;   // if there is no digit found, the calibration value of the line is 0 //
    }

    

    return pos1;
}

int main(void){
    
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    char line[MAX_LINE_CHARS];
    int sum = 0;

    // read each line of the file in order to get each calibration value //

    while (fgets(line, sizeof(line), fp) != NULL) {
        
        int posdig = find_calibration(line);

        dig2 = (dig2 == 0) ? dig1 : dig2;   // in the case that only 1 digit exists, the digit2 equals to digit1 //
        fprintf(stderr, "%d ", result);
        sum += result;                              // sum up calibration value from each line // 
    }

    fprintf(stderr,"\nFinal calibration result is: %d\n", sum);

    return 0;
}






int main(void){
    
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    char line[MAX_LINE_CHARS];
    int sum = 0;

    // read each line of the file in order to get each calibration value //

    while (fgets(line, sizeof(line), fp) != NULL) {
        int result = find_calibration(line);
        fprintf(stderr, "%d ", result);
        sum += result;                              // sum up calibration value from each line // 
    }

    fprintf(stderr,"\nFinal calibration result is: %d\n", sum);

    return 0;
}