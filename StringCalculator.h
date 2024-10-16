#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertStringToInteger(char* token) {
  int value = atoi(token);
  return value;
}

int additionOfInputs(int value){
  int total=0;
  if (value <= 1000)  {    
  total += value;
  }
  return total;
}

void checkEmptyString(const char* numbers) {
  if (numbers == NULL || strlen(numbers) == 0) {
    exit(0);
}

void checkNegativeNumber(int value) {
  if(value<0){
    printf("negatives not allowed");
    exit(0);
  }
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
  free(num_copy);
  return total;
}
