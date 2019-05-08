#include "kangdroid.h"

// TODO: EXCEPTION MAINTANCE
void showHex(char *input_path) {
    FILE *input_file;
    int nFileSize, dummy;

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
        for (int i = 0; i < nFileSize; i++) {
            //Every count 8, puts backslash-n
            if (i != 0) {
                if (i % 4 == 0) {
                    printf("  ");
                }
                if (i % 32 == 0) {
                    printf("\n");
                }
            }
            printf("%02x ", c[i]);
        }
        printf("\n\n");

        // if we don't close it, memory leaks...
        fclose(input_file);
        free(c);
    }
}