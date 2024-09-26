#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int add(const char* numbers) {
  if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }
    int total = 0;
    char num_copy = strdup(numbers);
    char token = strtok(num_copy, ",\n");
  if (value > 1000) {
            value = 0;  // Ignore numbers greater than 1000
        }
  total = total+ value;
  return total;
}
