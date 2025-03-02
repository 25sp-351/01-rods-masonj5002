#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

// TODO: ALLOW FUNCTION TO EXIT PROGRAM CLEANLY
void userInput(int *length, int *value, int *rod_length, int *cut_list_size) {
    int cut_length, cut_value = 0;

    while (scanf("%d,%d", &cut_length, &cut_value) == 2) {
        if (*cut_list_size >= MAX_SIZE) {
            printf("MAXIMUM INPUT SIZE EXCEEDED - PROGRAM WILL EXIT.\n");
            break;
        }

        if (cut_length > *rod_length) {
            printf("The cut is too long for this rod. Program will exit\n");
            return;
        }

        length[*cut_list_size] = cut_length;
        value[*cut_list_size]  = cut_value;
        (*cut_list_size)++;
    }
}

int shortestLength(int length[], int cut_list_size) {
    int shortest = length[0];
    for (int ix = 1; ix < cut_list_size; ix++)
        if (shortest > length[ix])
            shortest = length[ix];
    return shortest;
}

// RETURNS HIGHEST VALUE
int recursiveRodcut(int length[], int value[], int *rod_length,
                    int *cut_list_size, int *cuts, int *num_cuts) {
    printf("HELLO FROM recursiveRodcut\n");
    printf("CUTLIST SIZE: %d\n", *cut_list_size);
    printf("NUMBER OF CUTS: %d\n", *num_cuts);

    // BASE CASE
    if (*rod_length < shortestLength(length, *cut_list_size)) {
        printf("BASE CASE REACHED, returning: %d\n", 0);
        return 0;
    }

    int highest_value_for_length       = 0;
    int highest_value_for_length_index = -1;

    // ITERATING THROUGH EACH VALUE AND CHOOSING THE HIGHEST ONE
    for (int iw = 0; iw < *cut_list_size; iw++) {
        if (value[iw] > highest_value_for_length && length[iw] <= *rod_length) {
            highest_value_for_length       = value[iw];
            highest_value_for_length_index = iw;
        }
    }

    if (highest_value_for_length_index == -1) {
        printf("NO VALID CUT FOUND\n");
        return 0;
    }

    // making the cut
    *rod_length -= (length[highest_value_for_length_index]);
    cuts[*num_cuts] = length[highest_value_for_length_index];
    *num_cuts += 1;

    // Recursive call
    int recursive_result = recursiveRodcut(length, value, rod_length,
                                           cut_list_size, cuts, num_cuts);
    return (value[highest_value_for_length_index] + recursive_result);
}

const char *outputCuts(int length[], int value[], int *rod_length, int *cuts,
                       int *num_cuts) {
}

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
    int *length       = (int *)malloc(MAX_SIZE * sizeof(int));
    int *value        = (int *)malloc(MAX_SIZE * sizeof(int));

    if (length == NULL || value == NULL) {
        printf("MEMORY ALLOCATION FAILED.");
        return 1;
    }

    userInput(length, value, &rod_length, &cut_list_size);

    // DEBUGGING OUTPUT
    printf("\nYOU ENTERED:\n");
    for (int i = 0; i < cut_list_size; i++) {
        if (length[i] == 0 && value[i] == 0)
            break;
        printf("Length: %d, Value: %d\n", length[i], value[i]);
    }

    printf("\nSTARTING RECURSIVE RODCUT...\n");
    int *cuts     = (int *)malloc(MAX_SIZE * sizeof(int));
    int *num_cuts = (int *)malloc(sizeof(int));
    *num_cuts     = 0;
    printf("Profit: %d\n", recursiveRodcut(length, value, &rod_length,
                                           &cut_list_size, cuts, num_cuts));

    // DUBUGGING CUT LENGTHS
    printf("\n");
    for (int iv = 0; iv < *num_cuts; iv++)
        printf("Cut #%d: %d\n", iv + 1, cuts[iv]);

    // launch function output

    free(length);
    free(value);
    free(cuts);
    free(num_cuts);
    return 0;
}
