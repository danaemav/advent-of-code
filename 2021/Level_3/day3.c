#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_CHARS 1024

void count_binary(const char bit_line[], int ZEROS[], int ONES[]) {
    int size = strlen(bit_line);
    for (int i = 0; i < size; i++) {
        if (bit_line[i] == '1') {
            ONES[i]++;
        } else if (bit_line[i] == '0') {
            ZEROS[i]++;
        }
    }
}

void get_rates(int lines, const int ZEROS[], const int ONES[], int gamma[], int epsilon[]) {
    for (int i = 0; i < lines; i++) {
        if (ZEROS[i] > ONES[i]) {
            gamma[i] = 0;
            epsilon[i] = 1;
        } else {
            gamma[i] = 1;
            epsilon[i] = 0;
        }
    }
}

// function that converts the binary number to decimal //
int convert(int lines, const int num[]) {
    int dec = 0;
    for (int i = 0; i < lines; i++) {
        dec += num[i] * pow(2, (lines - i - 1));
    }
    return dec;
}

int main(void) {
    FILE *fp = freopen(NULL, "r", stdin);
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    char line[MAX_LINE_CHARS];
    int lines = 0;

    if (fgets(line, sizeof(line), fp) != NULL) {
        lines = strlen(line) - 1;
    }

    int zeros[lines], ones[lines], gamma[lines], epsilon[lines];
    for (int i = 0; i < lines; i++) {   // initialize //
        zeros[i] = 0, ones[i] = 0;
        gamma[i] = 0, epsilon[i] = 0;
    }

    // read each line of the file to update arrays //
    while (fgets(line, sizeof(line), fp) != NULL) {
        count_binary(line, zeros, ones);
        get_rates(lines, zeros, ones, gamma, epsilon);
    }

    int g = convert(lines, gamma);
    int e = convert(lines, epsilon);
    int power = g * e ; 
    
    printf("%d\n",power);
    fclose(fp);
    return 0;
}