#include <stdio.h>                                                                                     
#include <stdlib.h>

const int LINE_LENGTH = 31;
// const int LINE_LENGTH = 11; // For debugging with the provided solution.
const char TREE_CHAR = '#';
const int NUM_LINES = 324;
// const int NUM_LINES = 12;
FILE *inputFile;

char getCharAtIndex(FILE* inputFile, int targetIndex);

int run_toboggan_simulation(int x, int y) 
{
    FILE *localInput = fopen("../input.txt", "r");
    // FILE *localInput = fopen("tmp.txt", "r"); // For debugging with the provided solution.
    int numberOfTreesHit = 0;
    int currentX = 0;
    int line = 1;
    char lastCharacter;

    while (lastCharacter != EOF && line <= NUM_LINES)
    {
        printf("Line: %d\n", line);
        printf("x index: %d\n", currentX);
        
        lastCharacter = getCharAtIndex(localInput, currentX);
        printf("Last char: %c\n", lastCharacter);
        
        currentX = (currentX + x) % LINE_LENGTH;

        if (lastCharacter == TREE_CHAR)
        {
            printf("HIT!");
            numberOfTreesHit++;
        }

        for (int i = 1; i < y; i++)
        {
            line++;
            getCharAtIndex(localInput, LINE_LENGTH-1);
        }
        line++;
    }

    // printf("Number of trees hit: %d\n", numberOfTreesHit);
    return numberOfTreesHit;
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
    inputFile = fopen("../input.txt", "r");

    // int trees11 = run_toboggan_simulation(1, 1); // 84
    // printf("Right 1, down 1: %d\n", trees11);
    // int trees31 = run_toboggan_simulation(3, 1); // 198
    // printf("Right 3, down 1: %d\n", trees31);
    // int trees51 = run_toboggan_simulation(5, 1); // 72
    // printf("Right 5, down 1: %d\n", trees51);
    int trees71 = run_toboggan_simulation(7, 1); // 81
    printf("Right 7, down 1: %d\n", trees71);
    // int trees12 = run_toboggan_simulation(1, 2); // 53
    // printf("Right 1, down 2: %d\n", trees12);
    

    double long solution = 84L * 198L * 72L * 81L * 53L;
    printf("Final answer: %Lf\n", solution);
}