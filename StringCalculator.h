#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100

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

char get_delimiter(char *numbers) {
    if (numbers[0] == '/' && numbers[1] == '/') {
        if (numbers[2] == '[') {
            // Custom delimiter in the format //[*delim*]
            char *end = strchr(numbers + 3, ']');
            return (end) ? *(numbers + 3) : ',';
        }
        return numbers[2]; // Simple single-character delimiter
    }
    return ','; // Default delimiter
}

int add(const char *numbers) {
    if (strlen(numbers) == 0) {
        return 0;
    }

    char delimiter = get_delimiter((char *)numbers);
    char *numbers_copy = strdup(numbers); // Duplicate string for manipulation
    char *line = strtok(numbers_copy, "\n");

    int total = 0, negatives[MAX_NUMBERS] = {0}, negative_count = 0;

    // Replace newlines and process numbers
    for (char *p = line; *p; p++) {
        if (*p == '\n') *p = delimiter;
    }

    char *num = strtok(line, (char[]){delimiter, '\0'});
    while (num) {
        int value = atoi(num);
        if (value < 0) {
            negatives[negative_count++] = value;
        } else if (value <= 1000) {
            total += value;
        }
        num = strtok(NULL, (char[]){delimiter, '\0'});
    }

    if (negative_count > 0) {
        throw_negative_exception(negatives, negative_count);
    }

    free(numbers_copy); // Free duplicated string
    return total;
}
