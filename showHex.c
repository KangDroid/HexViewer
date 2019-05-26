#include "kangdroid.h"

// TODO: EXCEPTION MAINTANCE
void showHex(char *input_path) {
    FILE *input_file;
    int nFileSize, dummy;
    int co = 0, char_arr_counter = 0;
    char arr[60] = {0,};

    input_file = fopen(input_path, "r");
    if (input_file == NULL) {
        printf("Cannot determine input file or output file. Check path again!\n");
        printf("Enter 1 to continue...   ");
        scanf("%d", &dummy);
        return; //Force finish it
    } else {
        // Determine File size
        nFileSize = determineSize(input_file, 0);
        unsigned char *c = malloc(nFileSize); // unsigned char c[nFileSize] <-- Hate windows: they don't support VLA

        // Roll back to offset from FRONT(offset = 0) - cursor movement
        fseek(input_file, 0, SEEK_SET);

        //Read char data
        fread(c, sizeof(unsigned char), nFileSize, input_file);

        //Show file data in hex
        printf("\nHex data for: %s\n", input_path);
        printf("            ");
        for (int a = 0; a < 16; a++) {
            if (a % 4 == 0 && a != 0) {
                printf("  ");
            }
            printf(ANSI_COLOR_YELLOW"%02x ", a);
        }
        printf("\n");
        printf("%010x: "ANSI_COLOR_RESET, co);
        for (int i = 0; i < nFileSize; i++) {
            //Every count 8, puts backslash-n
            if (i != 0) {
                if (i % 4 == 0) {
                    printf("  ");
                }
                if (i % 16 == 0) {
                    printf("   %s\n", arr);
                    printf(ANSI_COLOR_YELLOW"%010x: "ANSI_COLOR_RESET, (co = co + 16));
                    resetArray(arr);
                    char_arr_counter = 0;
                }
            }
            printf("%02x ", c[i]);
            if (c[i] < 32 || c[i] > 126) {
                arr[char_arr_counter] = 46;
            } else {
                arr[char_arr_counter] = c[i];
            }
            char_arr_counter++;
        }
        printf("\n\n");

        // if we don't close it, memory leaks...
        fclose(input_file);
        free(c);
    }
}

void resetArray(char *array) {
    for (int i = 0; i < 60; i++) {
        array[i] = 0;
    }
}