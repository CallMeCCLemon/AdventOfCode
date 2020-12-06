#include <stdio.h>                                                                                     
#include <stdlib.h>

// const int LINE_LENGTH = 31;
const int LINE_LENGTH = 11; // For debugging with the provided solution.
const int X_INCREMENT_PER_ROW = 3;
const char TREE_CHAR = '#';
char getCharAtIndex(FILE* inputFile, int targetIndex);

int run_toboggan_simulation(int x, int y) 
{
    // FILE *inputFile = fopen("../input.txt", "r");
    FILE *inputFile = fopen("tmp.txt", "r"); // For debugging with the provided solution.
    char firstLineChar[1];

    int numberOfTreesHit = 0;
    int currentX = 0;
    char lastCharacter;

    while (lastCharacter != EOF)
    {
        lastCharacter = getCharAtIndex(inputFile, currentX);
        currentX = (currentX + x) % LINE_LENGTH;

        if (lastCharacter == TREE_CHAR)
        {
            numberOfTreesHit++;
        }

        for (i = 1; i < y; i++)
        {
            // Adjust the row pointer if y > 1
            getCharAtIndex(inputFile, 0);
        }
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

int main()
{
    int x = 1;
    int y = 1;
    int trees = run_toboggan_simulation(1, 1);
    printf("Right 1, down 1: %d\n", trees);
}