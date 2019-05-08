#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int determineSize(FILE *file_input, long offset_seek);
void showHex(char *input_path);
void dumpHex(char *input_path, char *output_path);
int showMenu();
void clearScreen();