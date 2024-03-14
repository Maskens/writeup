#include <stdio.h>

void readFile(char words[][10]) {
  FILE *fPtr;
  fPtr = fopen("assets/words.txt", "r");

  int wordIndex = 0;
  while(fgets(words[wordIndex], 255, fPtr) != NULL) {
    wordIndex++;
  }

  for(int i = 0; i < 1000; i++) {
    printf("%s", words[i]);
  }

  fclose(fPtr);
}

