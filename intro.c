// allows us to output to console
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // print statements DON'T skip lines
  printf("Hello, World!");
  printf("\n");
  printf("I love eating tacos!\n");

  int grade = 0;
  // grade == NULL can be used for pointers
  if (!grade) {
    printf("Grade is 0\n");
  } else if (grade < 10) {
    printf("Grade is less than 10\n");
  } else {
    printf("Grade is at least 10\n");
  }

  // array of size 200
  int list[10];
  for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
    // random int from [0, 101)
    list[i] = rand() % 101;
    // %d means decimal value
    printf("%d", list[i]);
    printf("\n");
  }

  char name[12] = "Christopher\n";
  printf("%s", name);

  // iterates through each letter in name
  for (size_t i = 0; i < strlen(name); i++) {
    // checks if name has only letters
    if (!isalpha(name[i])) {
      printf("NAME HAS A NON-LETTER\n");
      break;
    }
  }

  // checks if name has upper case
  for (size_t i = 0; i != '\0'; i++) {
    if (isupper(name[i])) {
      printf("NAME HAS A CAPITAL LETTER\n");
      break;
    }
  }

  // always include extra space for length for null terminator
  char vehicle1[4] = "bus";
  char vehicle2[4] = "car";
  // compares char values in each char array, returns 0 if same, 1 if different
  int compare = strcmp(vehicle1, vehicle2);
  if (compare) {
    printf("The vehicles are different\n");
  } else {
    printf("The vehicles are the same\n");
  }

  return 0;
}