/**
 * @file functions.c
 * @author Sialas Tripp
 * @brief Definition file
 * @date 2023-09-11
 * 
 */
#include "functions.h"

/**
 * @brief takes user inputted string and finds/returns the number of tokens.
 * 
 * @param s c type string 
 * @param args a pointer to an array to char
 * @return int number of tokens counted
 */
int getTokens(char *s, char ***args)  // or int getTokens(char s[], char **args[]);
{
    int start = 0;
    int end = 0;
    int tokenCount = 0;
    int length = strlen(s);
    char **tokens = malloc(sizeof(char*) * length);
    
    // Checks if allocation worked, if not returns 1.
    if (tokens == NULL)
    {
        return -1;
    }

    // loops through end of string
    while (start < length)
    {
        //skips over space infront of next word/token
        while (start < length && isspace(s[start]))
        {
            start++;
        }

        //checks if end of string has reached, if so breaks out of loop
        if (start == length) 
        {
            break;
        }
       
       // finds end of current token
        end = start;
        while (end < length && !isspace(s[end])) 
        {
            end++;
        }

        // allocates memory for a new token
        tokens[tokenCount] = malloc(end - start + 1);
       
        //Checks if allocation worked, if not returns -1
        if (tokens[tokenCount] == NULL) 
        {
            return -1;
        }

        // copies token into memory
        strncpy(tokens[tokenCount], s + start, end - start);
        
        // adds null terminator  
        tokens[tokenCount][end - start] = '\0';
        
        //increases count of tokens
        tokenCount++;
        
        // starts on next string/token
        start = end;
    }

    // adds a null terminator to end of array
    tokens[tokenCount] = NULL;
    *args = tokens;

    // returns number of tokens counted
    return tokenCount;

}