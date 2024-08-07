#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS 256 // number of days for which we have to find the lanternfish count


void laternfish_timer(long long timers[]){
    
    // Simulate the growth of lanternfish over the specified number of days
    for (int day = 0; day < DAYS; day++) {
        long long newFish = timers[0];
        for (int i = 1; i < 9; i++) {
            timers[i - 1] = timers[i];
        }
        timers[6] += newFish;
        timers[8] = newFish;
    }

}

int main() {


    FILE *file = fopen("input", "r");       // open the file
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

    // Array to store the number of lanternfish at each timer value
    long long timers[9] = {0};
    
    // Parse the string to extract integers and store them in the timers array
    char *token = strtok(buffer, ",");
    while (token != NULL) {
        int timer = atoi(token);
        timers[timer]++;
        token = strtok(NULL, ",");
    }

    laternfish_timer(timers);

    // Calculate the total number of lanternfish
    long long total = 0;
    for (int i = 0; i < 9; i++) {
        total += timers[i];
    }

    // Print the total number of lanternfish
    printf("Total number of lanternfish after %d days: %lld\n", DAYS, total);

    return 0;
}
