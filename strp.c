/* Str module that contains versions of the most commonly used standard
string handling functions; uses pointer notation */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

/* calculates and returns an int with the length of string pcSource*/
size_t Str_getLength(const char *pcSource)
{
   const char *pcEnd;
   assert(pcSource != NULL);
   pcEnd = pcSource;
   while (*pcEnd != '\0') {
      pcEnd++;
   }
   return (size_t)(pcEnd - pcSource);
}

/* copies string from pcToCopy to pcDestination and returns destination string*/
char* Str_copy(char* pcDestination, const char* pcToCopy) {
   char* pcStart;
   assert(pcDestination != NULL && pcToCopy != NULL);
   pcStart = pcDestination;
   while (*pcToCopy != '\0') {
      *pcDestination = *pcToCopy;
      pcDestination++;
      pcToCopy++;
   }
   /* adds null character at the end */
   *pcDestination = '\0';
   return pcStart;
}

/* appends string from pcSource to the pcDestination and returns destination string */
char* Str_concat(char* pcDestination, const char* pcSource) {
   char* pcStart;
   assert(pcDestination != NULL && pcSource != NULL);
   pcStart = pcDestination;
   while (*pcDestination != '\0') {
      pcDestination++;
   }
   while (*pcSource != '\0') {
      *pcDestination = *pcSource;
      pcDestination++;
      pcSource++;
   }
   /* adds null character at the end */
   *pcDestination = '\0';
   return pcStart;
}

/* compares two strings and returns an int less than 0 if pcStr1 is less than pcStr2, equal to 0
if pcStr1 matches s2, and an int greater than 0 if pcStr1 is greater than pcStr2 */
int Str_compare(const char* pcStr1, const char* pcStr2) {
   int difference;
   size_t counter = 0;
   size_t min = Str_getLength(pcStr1);
   assert(pcStr1 != NULL && pcStr2 != NULL);
   
   if (min < Str_getLength(pcStr2)) {
      min = Str_getLength(pcStr2);
   }

   while (counter < min) {
      difference = (int) *pcStr1 - (int) *pcStr2;
      if (difference != 0) {
         return difference;
      }
      pcStr1++;
      pcStr2++;
      counter++;
   }
   return 0;
}

/* finds first occurence of the pcSubstring in the pcMainString and returns a pointer
to the beginning of the located substring or null if it's not found */
char* Str_search(const char* pcMainString, const char* pcSubstring) {
   const char *pcMainStart; /* keeps track of beginning of main string */
   const char *pcSubStart; /* keeps track of beginning of substring */
   const char *pcFirst; /* keeps track of first occurence of substring */
   const char *pcInner; /* pointer inside loop */

   assert(pcMainString != NULL && pcSubstring != NULL);
   pcMainStart = pcMainString;
   pcFirst = pcMainString;
   pcSubStart = pcSubstring;

   if (Str_getLength(pcSubstring) == 0) {
        return (char*) pcMainStart;
    }

   while (*pcMainString != '\0') {
        if (*pcMainString == *pcSubstring) {
            pcMainString++;
            pcSubstring++;
            pcInner = pcMainString;
            while (*pcSubstring != '\0') {
                if (*pcInner != *pcSubstring) {
                    pcSubstring = pcSubStart;
                    pcFirst = pcMainString;
                    break;
                }
                pcInner++;
                pcSubstring++;
            }
            if (pcSubstring != pcSubStart) {
                return (char*) pcFirst;
            }
        } else {
            pcMainString++;
            pcFirst++;
        }
    }
    return NULL;
}

