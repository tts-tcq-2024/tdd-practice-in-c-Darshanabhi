#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertStringToInteger(char *token) {
  int value = atoi(token);
  return value;
}

int additionOfInputs(int value){
  if (value <= 1000)      }
  total += value;
  return total;
}

int add(const char* numbers) {
  if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
  }
  int total = 0;
  char *token = strtok(numbers, ",\n");
  while (token != NULL) {  
    int value = convertStringToInteger(token);
    total = additionOfInputs(value);
    token = strtok(NULL, ",\n");
  }
  return total;
}
