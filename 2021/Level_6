//  --- Day 6: Lanternfish ---
// We get the initial state of the laternfishes' internal counters.
// Each lanternfish creates a new lanternfish once every 7 days.
// However, this process isn't necessarily synchronized between every lanternfish.
// So, model each fish as a number that represents the number of days until it creates a new lanternfish - the internal counter.
// A lanternfish that creates a new fish resets its timer to 6 (because 0 is included as a valid timer value). 
// The new lanternfish starts with an internal timer of 8 and does not start counting down until the next day.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000000        // Assume that the initial state fish are less than 1000000 
#define DAYS 80                 // Number of days for which we have to find the laternfish count

// Update the lanternfish timers and add new lanternfish when needed
void laternfish_update(int timer[], int *count);

int main() {
    
    // Declare internal timer array to store the integers
    int timer[MAX_NUMBERS];
    int count = 0;

    // Open the file for reading
    FILE *file = fopen("input", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file content into a string
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }
    fclose(file);

    // Parse the string to extract integers and store them in the array
    char *token = strtok(buffer, ",");
    while (token != NULL && count < MAX_NUMBERS) {
        timer[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // Print the array and verify the content
    printf("\nInitial state: ");
    for (int i = 1; i <= count; i++) {
        printf("%d, ", timer[i]);
    }
    printf("\n");

    for(int i = 1; i <= DAYS; i++){
        laternfish_update(timer, &count);
    }

    printf("Laternfish count after %d days = %d\n\n", DAYS, count);

    return 0;
}


void laternfish_update(int timer[], int *count) {
    int initial_count = *count;
    for (int i = 0; i < initial_count; i++) {       // iterate for 1 day through all the internal counters
        if (timer[i] == 0) {
            timer[i] = 6;
            if (*count < MAX_NUMBERS) {
                timer[(*count)++] = 8;              // update the new lanternfish's counter into the timer array
            }
        } else {
            timer[i] -= 1;
        }
    }
}
