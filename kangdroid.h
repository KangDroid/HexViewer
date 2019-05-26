#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int determineSize(FILE *file_input, long offset_seek);
void showHex(char *input_path);
void dumpHex(char *input_path, char *output_path);
int showMenu();
void clearScreen();