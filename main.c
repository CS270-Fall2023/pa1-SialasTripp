/**
 * @file pa1.c
 * @author Sialas Tripp
 * @brief Program that asks user to enter a string, 
 *        it then takes said string and parses it to get
 *        a count of the number of tokens in the string entered.
 * @date 2023-09-06
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
const int SIZE = 256;


int main()
{
    char **arrayOfTokens = NULL;
    char str[SIZE];
    int numberOfTokens = 0;

    // Get users string input
    printf("Please, enter the string: ");
    fgets(str, 256,stdin);

    //Gets number of tokens from user inputted string
    numberOfTokens = getTokens(str, &arrayOfTokens);

    // Print out results 
    printf("Number of tokens: %d\n", numberOfTokens);
    for (int i = 0; i <= numberOfTokens; i++)
    {
        printf("token %d: %s\n", i + 1, (arrayOfTokens)[i]);
    }

    //free memory allocated
    free(arrayOfTokens);

    return 0;
}
