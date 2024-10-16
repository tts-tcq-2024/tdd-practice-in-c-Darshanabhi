#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBERS 100
#define MAX_DELIMITER_LENGTH 10

void throw_negative_exception(int negatives[], int count) {
    printf("negatives not allowed: ");
    for (int i = 0; i < count; i++) {
        printf("%d", negatives[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("\n");
    exit(1); // Exit program due to exception
}

void check_for_custom_delimiter(char *line){
if (line[0] == '/' && line[1] == '/') {
        // Extract the custom delimiter
        char *custom_delimiter = line + 2; // Skip "//"
        if (custom_delimiter[0] == '[') {
            char *end_delim = strchr(custom_delimiter, ']');
            if (end_delim) {
                strncpy(delimiter, custom_delimiter + 1, end_delim - custom_delimiter - 1);
                delimiter[end_delim - custom_delimiter - 1] = '\0';
                line = strtok(NULL, ""); // Get the rest of the numbers
            }
        } else {
            // Just a simple delimiter
            delimiter[0] = custom_delimiter[0];
            line = strtok(NULL, ""); // Get the rest of the numbers
        }
    }
}

void delimiter_for_uniform_splitting(char *line,char delimiter) {
for (char *p = line; *p; p++) {
        if (*p == '\n') {
            *p = delimiter[0]; // Replace with default delimiter
        }
    }
}

void split_by_delimiter(char *line, char delimiter) {
 char *num = strtok(line, delimiter);
    while (num != NULL) {
        int value = atoi(num);
        if (value < 0) {
            negatives[negative_count++] = value;
        } else if (value <= 1000) {
            total += value;
        }
        num = strtok(NULL, delimiter);
    }
}

int add(const char *numbers) {
    if (strlen(numbers) == 0) {
        return 0;
    }

    char delimiter[2] = {',', '\0'}; // Default delimiter
    char *numbers_copy = strdup(numbers); // Duplicate string for manipulation
    char *line = strtok(numbers_copy, "\n");

    // Check for custom delimiter
    check_for_custom_delimiter(char *line);

    // Replace newlines with the delimiter for uniform splitting
    delimiter_for_uniform_splitting(line,delimiter);

    int total = 0;
    int negatives[MAX_NUMBERS] = {0};
    int negative_count = 0;

    // Split by delimiter
    split_by_delimiter(line,delimiter);

    if (negative_count > 0) {
        throw_negative_exception(negatives, negative_count);
    }

    free(numbers_copy); // Free duplicated string
    return total;
}
