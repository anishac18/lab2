#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 100
#define MAX_WORD_LENGTH 20

int main(int argc, char* argv[]) {
  //printf("hii");
   
  /*if (argc != 2) {
    printf("Error: Input again\n");
    return 1;
  }*/
  //printf("hi");
  char* filename = argv[1];
  FILE* fp = fopen(filename, "r");

  //if (fp == NULL) {
  //  printf("Error opening file %s\n", filename);
  //  return 1;
  //}

 
  char buffer[MAX_STR];
  int words = 0; 
  int lines = 0; 
  int wordCountSize = 0; 
  int* wordCount = NULL; 

  // Read each line of the file
  while (!feof (fp)) { 
    if (strlen(buffer) > 100) {
      printf("Error: line too long on line %d\n", lines + 1);
      return 1;
    }
  lines++;
    
    int currentLineWords = 0; 
    int currentWordLength = 0; 

   
    for (int i = 0; i < strlen(buffer); i++) {
      if (buffer[i] == ' ') {
        if (currentWordLength <= MAX_WORD_LENGTH) {
          currentLineWords++;
        }
        currentWordLength = 0;
      } else {
        currentWordLength++;
      }

      
      if (currentWordLength > MAX_WORD_LENGTH) {
        printf("Error: word too long on line %d\n", lines);
        return 1;
      }
    }
   
    if (currentWordLength <= MAX_WORD_LENGTH) {
      currentLineWords++;
    }

    words += currentLineWords; 
    if (lines > wordCountSize) {
      wordCountSize = lines;
      wordCount = realloc(wordCount, wordCountSize * sizeof(int));
    }
   
    wordCount[lines - 1] = currentLineWords; }
        
  // Close the file 
  fclose(fp);
  free(wordCount);

 
  const char* chooselineWord;
  if (words == 1) {
    chooselineWord = "word";
  } else {
    chooselineWord = "words";
  }

  const char* chooseline;
  if (lines == 1) {
    chooseline = "line";
  } else {
    chooseline = "lines";
  }

  printf("%d %s on %d %s\n", words, chooselineWord, lines, chooseline);
  for (int i = 0; i < lines; i++) { 
    printf("%d ", wordCount[i]);
  }
  printf("\n");


  return 0;
}