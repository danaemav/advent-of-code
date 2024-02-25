#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function that finds the first and last digits from a line and calculates the calibration value //
int find_calibration(int line[]){
    
    int size = strlen(line);
    int dig1 = 0, dig2 = 0;
    int pos1 = 0;
    
    for(int i = 0; i < size; i++){
        if(isdigit(line[i])) {   // search for a digit starting from the front of the line //
            dig1 = line[i];
            pos1 = i;           // if it is found, store its position and break loop //
            break;
        }
    }
    if (pos1 != 0) {                                // if a digit exists //
        for(int i = size ; i > pos1; i--){          // iterate from the back of line to the position of digit1 //
            if(isdigit(line[i])){
                dig2 = line[i];
                break;
            }
        }
    } else {
        return 0;   // if there is no digit found, the calibration value of the line is 0 //
    }

    dig2 = (dig2 == 0) ? dig1 : dig2;   // in the case that only 1 digit exists, the digit2 equals to digit1 //

    int result = dig1 * 10 + dig2; 
    return result;
}


int main(void){
    
    // attempt to open the file and check if it opened succesfully //
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    // read each line of the file and call find_calibration in order to get each value and sum later //
    // things missing - must do this for all lines //

    int line[1024];
    int sum = 0;
    while (fscanf(fp, "%1023d", line) != EOF){
        int result = find_calibration(line);
        fprintf(stderr,"%d", result);
        sum+=result ;
    }

    fprintf(stderr,"Final calibration result is: %d", sum);

    return 0;
}