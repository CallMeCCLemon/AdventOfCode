#include <stdio.h>                                                                                     
#include <stdlib.h>

const int LINE_LENGTH = 31;
// const int LINE_LENGTH = 11; // For debugging with the provided solution.
const int X_INCREMENT_PER_ROW = 3;
const char TREE_CHAR = '#';
char getCharAtIndex(FILE* inputFile, int targetIndex);

int main() 
{
    FILE *inputFile = fopen("../input.txt", "r");
    // FILE *inputFile = fopen("tmp.txt", "r"); // For debugging with the provided solution.
    char firstLineChar[1];

    int numberOfTreesHit = 0;
    int currentX = 0;
    int lineNumber = 1;
    char lastCharacter;

    while (lastCharacter != EOF)
    {
        lastCharacter = getCharAtIndex(inputFile, currentX);
        currentX = (currentX + X_INCREMENT_PER_ROW) % LINE_LENGTH;
        
        if (lastCharacter == TREE_CHAR)
        {
            numberOfTreesHit++;
        }
        lineNumber++;
    }

    fclose(inputFile);

    printf("Number of trees hit: %d\n", numberOfTreesHit);
    return 0;
}

/**
 * Reads a line of a file and returns the desired character at the index.
 * If the end of file was reached, returns EOF.
 */
char getCharAtIndex(FILE* inputFile, int targetIndex) 
{
    // Read the entire line.
    char currentChar;
    char targetChar;
    int currentIndex = 0;

    while (currentChar != '\n' && currentChar != EOF)
    {
        currentChar = fgetc(inputFile);

        if (currentIndex == targetIndex)
        {
            targetChar = currentChar;
        }

        currentIndex++;
    }
    
    // Return just the one character.
    if (currentChar == EOF)
    {
        return EOF;
    }
    else
    {
        return targetChar;
    }
}