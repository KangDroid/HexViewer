#include "kangdroid.h"

// TODO: EXCEPTION MAINTANCE
void dumpHex(char *input_path, char *output_path) {
    FILE *input_file, *output_file;
    int nFileSize, dummy;

    input_file = fopen(input_path, "r");
    output_file = fopen(output_path, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Cannot determine input file or output file. Check path again!\n");
        printf("Enter 1 to continue...   ");
        scanf("%d", &dummy);
        return;
    } else {
        // Determine File size
        nFileSize = determineSize(input_file, 0);
        unsigned char *c = malloc(nFileSize); // unsigned char c[nFileSize] <-- Hate windows: they don't support VLA

        // Roll back to offset from FRONT(offset = 0)
        fseek(input_file, 0, SEEK_SET);

        //Read char data
        fread(c, sizeof(unsigned char), nFileSize, input_file);

        //Save file data in hex
        for (int i = 0; i < nFileSize; i++) {
            if (i != 0) {
                if (i % 4 == 0) {
                    fprintf(output_file, "%s", "  ");
                }
                if (i % 16 == 0) {
                    fprintf(output_file, "%s", "\n");
                }
            }
            fprintf(output_file, "%02x", c[i]);
        }

        // if we don't close it, memory leaks...
        fclose(input_file); // This should be successful
        free(c);

        dummy = fclose(output_file);
        if (dummy == 0) {
            printf("Successful!\n");
            printf("Dump saved on %s\n", output_path);
        } else if (dummy == -1) {
            printf("Unsuccessful!\n");
            printf("Cannot save hex dump file on %s !\n", output_path);
        }
    }
    printf("Enter 1 to continue...   ");
    scanf("%d", &dummy);
}