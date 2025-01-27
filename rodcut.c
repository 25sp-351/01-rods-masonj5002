#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char** argv){
  // Rod length exists
  if(argc != 2) {
    printf("USAGE: rod_length<int>");
    return 1;
  }

  // convert rod length into int
  int rod_length = atoi(argv[1]);
  if (rod_length == 0) {
    printf("INVALID ROD LENGTH.");
    return 1;
  }
  
  printf("\nYou entered: %d", rod_length);
  printf("\n");

  int length[100];
  int value[100];
 
  char user_input[25];

  int cut_counter = 0;
  printf("Enter the list of piece prices \"length, value\":\n");
  while(fgets(user_input, 400, stdin) != NULL){    //EOF is NULL
    int comma_pos = 0;
    for(int i = 0; i < 100; i++) {
      int cursor = user_input[i];
      if (cursor == 44) {
        comma_pos = i;
        break;
      }
    }

    // Converts to parallel strings
    char str_length[9];
    strncpy(str_length, user_input, comma_pos);
    str_length[comma_pos] = '\0';

    char str_value[9];
    strncpy(str_value, user_input+comma_pos+1, 5);
    str_length[5] = '\0';

    // Converts to int & appends arrays
    length[cut_counter] = atoi(str_length);
    value[cut_counter] = atoi(str_value);

    //***DELETE ME
    printf("Value in length array: %d", length[cut_counter]);
    printf("\n");
    printf("Value in value array: %d", value[cut_counter]);
    printf("\n");

    cut_counter++;
  }
  printf("end of loop");    //DELETEME
  // // loops until EOF is reached.
  // while(fgets(userInput, 100, stdin) == 1) {
  //   printf("%s\n", userInput);
  //   printf("Enter the list of piece prices \"length, value\": ");
  //   instruction_counter++;
  // }

  int remaining_rod_length = rod_length;
  int total_value = 0;

  //for(i=0; i < instruction_counter; i++) {   
  // if (can_cut(remaining_rod_length, length[i])) {
  //    remaining_rod_length = remaining_rod_length - length[i];
  //    total_value = total_value + value[i];
  //    print <n> @ <size> = <value>
  // }
  //}

  printf("Value: %d\n", total_value);
  printf("\n");
  return 0;
}

//TODO
int can_cut(int rem_rod_length, int cut_length) {}