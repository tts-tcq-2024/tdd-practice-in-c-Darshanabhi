#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertStringToInteger(const char* token) {
    return atoi(token);
}

int add(const char* numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0; // Return 0 for empty input
    }

    int total = 0;
    char *num_copy = strdup(numbers);
    if (num_copy == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    char *token = strtok(num_copy, ",\n");
    while (token != NULL) {
        int value = convertStringToInteger(token);
        if (value < 0) {
            printf("negatives not allowed\n");
            free(num_copy); // Free before exiting
            exit(0);
        }
        if (value <= 1000) {
            total += value;
        }
        token = strtok(NULL, ",\n");
    }

    free(num_copy);
    return total;
}
