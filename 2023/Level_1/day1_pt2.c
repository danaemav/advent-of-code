#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_CHARS 1024

// letters from which an acceptable number written as letters is starting with //
bool isnamestart(char ch){
    return (ch == "o" || ch == "t" || ch == "f" || ch == "s" || ch == "e" || ch == "n");
}

char letter_num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// i must check for each char if it makes up a num in letters from the front //
// and after that do the same but from the back, reversely //
// for example for "four" check "r, u, o, f" --> inverse loop // 

void find_arithmetic(char line[], int pos1, int pos2, int num1, int num2){

    int size = strlen(line);
    int digit = 0; 
    int k = 0;              // counter to get the number from num array //
    

    for(int i = 0; i < size; i++){
        pos_name = -1 ;
        
        if (isalpha(line[i]) && isnamestart(line[i])){
            pos_name = i;   // starting position of "letter - number" // 
            
            for (int k = 0; k < 10 ; k++) {
                if (line[i] == num[k]){
                    // do stuff //
                }
            }
        }
    }
    if (pos_name != -1){
        // stuff //
    }
}


// much stuff missing and gone wrong //
// functions must return both the position and the number in the case that pos != -1//
// need modifications to get the positions and compare them //
// check notes.txt//

// function that finds the first and last digits from a line - if they exist - //
void find_num(char line[], int pos1, int pos2, int dig1, int dig2){
    
    int size = strlen(line);
    int countline;
    
    // get the first digit from the front of the line //
    for(int i = 0; i < size; i++){
        countline = i ;
        if(isdigit(line[i])) {      // search for a digit starting from the front of the line //
            dig1 = line[i] -'0';    // convert char ascii code to decimal value //
            pos1 = i;               // if it is found, store its position and break loop //
            break;
        }
    }

    if (pos1 != 0 || (pos1 == 0 && countline == 0)) {      // if another digit exists //
        for(int i = size ; i > pos1; i--){        // iterate from the back of line to the position of digit1 //
            if(isdigit(line[i])){
                dig2 = line[i] - '0';
                break;
            }
        }
    } 
}

// i have to check if line has only char - numbers or only digits at front and back //
void combine_pos(char *line[], int pos_name1, int pos_name2, int pos_dig1,
                int pos_dig2, int num_n1, int num_n2, int num_d1, int num_d2) {
    
    int sum = 0, digit1;
    
    if (pos_name1 != -1){       // get whats number is found first besides found as char or digit //
        min_pos = (pos_name1 < pos_dig1) ? pos_name1 : pos_dig1 ;
        digit1 = (min_pos == pos_name1) ? num_n1 : num_d1 ;         // first number found //
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
    int sum = 0;

    // read each line of the file in order to get each calibration value //
    while (fgets(line, sizeof(line), fp) != NULL) {
        
        // stuff depending on my functions and what they return //
        
    }

    fprintf(stderr,"\nFinal calibration result is: %d\n", sum);
    return 0;
}