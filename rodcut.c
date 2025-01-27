#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Rod length exists
    if (argc != 2) {
        printf("USAGE: rod_length<int>\n");
        return 1;
    }

    // convert rod length into int
    int rod_length = atoi(argv[1]);
    if (rod_length == 0) {
        printf("INVALID ROD LENGTH.");
        return 1;
    }
    int current_rod_length = rod_length;
    int length[100];
    int value[100];

    char user_input[25];

    int cut_counter = 0;
    printf(
        "Enter the length of rod cuts and their prices \"length, value\":\n");
    while (fgets(user_input, 400, stdin) != NULL) { // EOF is NULL
        int comma_pos = 0;
        for (int i = 0; i < 100; i++) {
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
        strncpy(str_value, user_input + comma_pos + 1, 5);
        str_length[5] = '\0';

        // Check if length is too long
        if (atoi(str_length) > current_rod_length) {
            printf("The cut is too long for rod. Program will exit.\n");
            return 1;
        }

        // Converts to int & appends arrays
        length[cut_counter] = atoi(str_length);
        value[cut_counter]  = atoi(str_value);

        current_rod_length -= length[cut_counter];
        cut_counter++;
    }

    printf("\n\nCut List:\n");
    for (int i = 0; i < cut_counter; i++)
        printf("1 @ %d = %d\n", length[i], value[i]);

    printf("\nRemainder: %d\n", current_rod_length);
    int total_value = 0;
    for (int i = 0; i < cut_counter; i++)
        total_value += value[i];
    printf("Value: %d\n\n", total_value);
}