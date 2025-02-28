#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

// TODO: ALLOW FUNCTION TO EXIT PROGRAM CLEANLY
void userInput(int length[], int value[], int *rod_length, int *cut_list_size) {
  int cut_length, cut_value = 0;

  while (scanf("%d,%d", &cut_length, &cut_value) == 2) { // 2 is not NULL
    if (*cut_list_size >= MAX_SIZE) {
      printf("MAXIMUM INPUT SIZE EXCEEDED - PROGRAM WILL EXIT.\n");
      break;
    }

    if (cut_length > *rod_length) {
      printf("The cut is too long for this rod. Program will exit\n");
      return;
    }

    length[*cut_list_size] = cut_length;
    value[*cut_list_size] = cut_value;
    (*cut_list_size)++;
  }
}

int recursiveRodcut(int length[], int value[], int *rod_length,
                    int *cut_list_size) {
  printf("HELLO FROM recursiveRodcut\n");

  // ARE WE DONE? (BASE CASE)
  // check if remainder is less than the smallest cut size

  // LEAST WE CAN DO
  // choose the cut that has the highest dollar amount

  // TRUST THAT SOMEONE ELSE CAN DO
  // reduce the remainder and run it again

  return 0;
}

// system output

int main(int argc, char **argv) {
  // Rod length exists
  if (argc != 2) {
    printf("USAGE: rod_length<int>\n");
    return 1;
  }

  // convert rod length into int
  int rod_length = atoi(argv[1]);
  if (rod_length < 1) {
    printf("INVALID ROD LENGTH.");
    return 1;
  }
  printf("Rod length: %d\n", rod_length);

  int cut_list_size = 0;
  int length[MAX_SIZE];
  int value[MAX_SIZE];
  userInput(length, value, &rod_length, &cut_list_size);

  // DEBUGGING OUTPUT
  printf("\nYOU ENTERED:\n");
  for (int i = 0; i < cut_list_size; i++) {
    if (length[i] == 0 && value[i] == 0)
      break;
    printf("Length: %d, Value: %d\n", length[i], value[i]);
  }

  return 0;
}
