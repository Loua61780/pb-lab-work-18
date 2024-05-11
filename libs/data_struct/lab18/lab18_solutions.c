#include "lab18_solutions.h"
#include "../string/string.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void removeExtraSpaces(char* source) {
    char* writePointer = source;
    while (*source != '\0') {
        if (*source != *(source + 1)) {
            *writePointer = *source;
            writePointer++;
        }
        source++;
    }
    *writePointer = '\0';
}
