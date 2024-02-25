#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function that finds the first and last digits from a line and calculates the calibration value //
int find_calibration(int *line, int size){
    
    int dig1 = 0, dig2 = 0;
    int pos1 = 0;
    
    for(int i = 0; i < size){
        if(isdigit(line[i])){   // search for a digit starting from the front of the line //
            dig1 = content[i];
            pos1 = i;           // if it is found, store its position and break loop //
            break;
        }
    }
    if (posi != 0) {                                // if a digit exists //
        for(int i = size ; i > posi; i--){          // iterate from the back of line to the position of digit1 //
            if(isdigit(line[i])){
                dig2 = content[i];
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
    
    FILE *fp = fopen(stdin, "r");
    if (fp1 == NULL) {   // check if file opened correctly //
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    // find size of file by using the steam //
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int *content = malloc((size + 1) * sizeof(int));    // store the content of the file //
    if (content == NULL){
        printf("Memory allocation error.\n");
        exit(1);
    }

    // read content of the file //
    if (fread(content, sizeof(int), size, fp) != size) {
        fprintf(stderr, "Error at reading file.\n");
        free(content);
        exit(1);
    }
    content[size] = 0;


    return 0;
}