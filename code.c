#include "kangdroid.h"

int main(void) {
    int menu_case;
    //Clear CMD First
    clearScreen();
    do {
        menu_case = showMenu();
    } while (menu_case < 1 || menu_case > 6);

    printf("GoodBye!\n");

    //TODO: File default extension
    //TODO2: Hex Dump
    //IDEA: File hex string in file, search for spc file_extension_hex
    return 0;
}

int showMenu() {
    int menu_input, dummy, i, is_extension_from_now = 0;
    static char input_location[512] = "", output_location[512] = "";

    static char enter_input_no_stored[] = "1. Enter input file location(path).\n";
    static char enter_output_no_stored[] = "2. Enter output file location(path).\n";
    char change_input[] = "1. Edit input file location(path)\n";
    char change_output[] = "2. Edit output file location(path)\n";

    printf("%s", enter_input_no_stored);
    printf("%s", enter_output_no_stored);
    printf("3. View hex file in terminal.\n");
    printf("4. Dump hex file to output file location.\n");
    printf("5. Find file default extension\n");
    printf("6. EXIT\n");
    if (strlen(input_location) != 0) {
        printf("\nCurrent input info: %s\n", input_location);
    } else {
        printf("\nCurrent input info: NOT SET\n");
    }
    if (strlen(output_location) != 0) {
        printf("Current output info: %s\n", output_location);
    } else {
        printf("Current output info: NOT SET\n");
    }
    printf("\nEnter menu you want to use: ");
    if (scanf("%d", &menu_input) == 0) {
        while(getchar() != '\n');
        menu_input = 0;
    }

    switch (menu_input) {
        case 1:
            printf("Enter input location: ");
            scanf("%s", input_location);
            strncpy(enter_input_no_stored, change_input, sizeof(enter_input_no_stored) - 1);
            clearScreen();
            return 0;
        break;
        case 2:
            printf("Enter output location: ");
            scanf("%s", output_location);
            strncpy(enter_output_no_stored, change_output, sizeof(enter_output_no_stored) - 1);
            clearScreen();
            return 0;
        break;
        case 3:
            if (strlen(input_location) != 0) {
                showHex(input_location);
            } else {
                printf("Input location is NOT SET.\nPlease set input location by using menu no.1\n");
                printf("Press 1 to continue...  ");
                scanf("%d", &dummy);
                clearScreen();
            }
            return 0;
        break;
        case 4:
            if (strlen(output_location) != 0 && strlen(input_location) != 0) {
                dumpHex(input_location, output_location);
            } else {
                printf("Output location is NOT SET.\nPlease set output location by using menu no.2\n");
                printf("Press 1 to continue...  ");
                scanf("%d", &dummy);
            }
            clearScreen();
            return 0;
        break;
        case 5:
            printf("File Extension is: ");
            for (i = 0; i < strlen(input_location) + 1; i++) {
                if (input_location[i] == '.') {
                    is_extension_from_now = 1;
                    //break;
                }
                if (is_extension_from_now == 1) {
                    printf("%c", input_location[i]);
                }
            }
            printf("\n");
            return 0;
        break;
        case 6:
            return 6;
        break;
        default:
            return 0;
        break;
    }
}

// Global: Determine file size. --> char = 1
int determineSize(FILE *file_input, long offset_seek) {
    fseek(file_input, offset_seek, SEEK_END); // Roll back to offset from END(offset = 0)
    return ftell(file_input);   
}

void clearScreen() {
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    // Clear Console for Windows
    system("cls");
    #else
    system("clear && printf '\e[3J'");
    #endif
}