/* Str module that contains versions of the most commonly used standard
string handling functions; uses array notation */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "str.h"

/* calculates and returns an int with the length of string pcSource*/
size_t Str_getLength(const char pcSource[]) {
    size_t length = 0;
    assert (pcSource != NULL);
    while (pcSource[length] != '\0') {
        length++;
    }
    return length;
}

/* copies string from pcToCopy to pcDestination and returns destination string*/
char* Str_copy(char pcDestination[], const char pcToCopy[]) {
    size_t counter = 0;
    assert (pcToCopy != NULL && pcDestination != NULL);
    while (pcToCopy[counter] != '\0') {
        pcDestination[counter] = pcToCopy[counter];
        counter++;
    }
    /* adds extra null character at the end */
    pcDestination[counter] = '\0';
    return pcDestination;
}

/* appends string from pcSource to the pcDestination and returns destination string */
char* Str_concat(char pcDestination[], const char pcSource[]) {
    size_t counter = 0;
    size_t counter2 = 0;
    assert (pcDestination != NULL && pcSource != NULL);

    while (pcDestination[counter] != '\0') {
        counter++;
    }
    while (pcSource[counter2] != '\0') {
        pcDestination[counter] = pcSource[counter2];
        counter++;
        counter2++;
    }
    /* adds extra null character at the end */
    pcDestination[counter] = '\0';
    return pcDestination;
}

/* compares two strings and returns an int less than 0 if pcStr1 is less than pcStr2, equal to 0
if pcStr1 matches s2, and an int greater than 0 if pcStr1 is greater than pcStr2 */
int Str_compare(const char pcStr1[], const char pcStr2[]) {
    int difference;
    size_t counter = 0;
    size_t min = Str_getLength(pcStr1);
    assert (pcStr1 != NULL && pcStr2 != NULL);
    if (min < Str_getLength(pcStr2)) {
        min = Str_getLength(pcStr2);
    }

    while (counter < min) {
        difference = (int) pcStr1[counter] - (int) pcStr2[counter];
        if (difference != 0) {
            return difference;
        } 
        counter++;
    }
    return 0;
}

/* finds first occurence of the pcSubstring in the pcMainString and returns a pointer
to the beginning of the located substring or null if it's not found */
char* Str_search(const char pcMainString[], const char pcSubstring[]) {
    const char* pcFirst;  /* keeps track of first occurence of substring */
    const char* pcStart; /* keeps track of start of main string */
    size_t counter = 0; /* counter for iterating main string */
    size_t check = 0; /* counter for iterating substring */
    size_t innerCounter = 0;    /* counter inside loop */

    assert (pcMainString != NULL && pcSubstring != NULL);
    pcFirst = pcMainString;
    pcStart = pcMainString;

    if (Str_getLength(pcSubstring) == 0) {
        return (char*) pcFirst;
    }

    while (pcMainString[counter] != '\0') {
        if (pcMainString[counter] == pcSubstring[check]) {
            counter++;
            check++;
            innerCounter = counter;
            while (pcSubstring[check] != '\0') {
                if (pcMainString[innerCounter] != pcSubstring[check]) {
                    check = 0;
                    pcFirst = pcStart;
                    pcFirst += counter;
                    break;
                }
                innerCounter++;
                check++;
            }
            if (check != 0) {
                return (char*) pcFirst;
            }
        } else {
            counter++;
            pcFirst++;
        }
    }
    return NULL;
}
