#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertStringToInteger(char* token) {
    return atoi(token);
}

int additionOfInputs(int value, int total) {
    if (value <= 1000) {
        total += value;
    }
    return total;
}

int checkEmptyString(const char* numbers) {
    return numbers == NULL || strlen(numbers) == 0;
}

void checkNegativeNumber(int value) {
    if (value < 0) {
        printf("negatives not allowed\n");
        exit(0);
    }
}

int string_Calculator(char *token, int total, char *token) {
    while (token != NULL) {  
        int value = convertStringToInteger(token);
        checkNegativeNumber(value);
        total = additionOfInputs(value, total);
        token = strtok(NULL, ",\n");
    }
}

int add(const char* numbers) {
    if (checkEmptyString(numbers)) {
        return 0; // Return 0 for empty input
    }

    int total = 0;
    char *num_copy = strdup(numbers); // Duplicate the input string
    if (num_copy == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    char *token = strtok(num_copy, ",\n");
    total = string_Calculator(token,total,token);

    free(num_copy); // Free the duplicated string
    return total;
}
