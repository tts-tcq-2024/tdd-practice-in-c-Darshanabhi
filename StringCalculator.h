#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertStringToInteger(char* token) {
  int value = atoi(token);
  return value;
}

int additionOfInputs(int value){
  int total;
  if (value <= 1000)      
  total += value;
  return total;
}

char checkEmptyString(const char* numbers) {
  if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
  }
}

int checkNegativeNumber(int value) {
  if(value<0){
    printf("negatives not allowed");
    return 0;
  }
  return 1;
}

int add(const char* numbers) {
  checkEmptyString(numbers);
  int total = 0;
  char *num_copy = strdup(numbers);
  char *token = strtok(num_copy, ",\n");
  while (token != NULL) {  
    int value = convertStringToInteger(token);
    checkNegativeNumber(value);
    total = additionOfInputs(value);
    token = strtok(NULL, ",\n");
  }
  return total;
}
