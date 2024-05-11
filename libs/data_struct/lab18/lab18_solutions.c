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

int getWord(char *beginSearch, WordDescriptor* word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0') {
        return 0;
    }

    word->end = findSpace(word->begin);

    return 1;
}

int getWordReverse(char* searchEnd, char* searchStart, WordDescriptor* word) {
    word->end = findNonSpaceReverse(searchEnd, searchStart) + 1;

    if (word->end == searchEnd + 1) {
        word->begin = searchStart + 1;
        return 0;
    }

    word->begin = findSpaceReverse(searchEnd, word->end - 1) + 1;

    return 1;
}
