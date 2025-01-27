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


  // user input string. we will use the same one and then parase
  // into seperate length, value arrays
  char userInput[400];
  int length[100];
  int value[100];

  //int comma = ',';


  // keeps track of # of cuts
  int cut_counter = 0;


  printf("Enter the list of piece prices \"length, value\":\n");
  
  //KEEP LOOPING UNITL control + D IS PRESSED

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