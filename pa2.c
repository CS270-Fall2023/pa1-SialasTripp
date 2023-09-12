/**
 * @file pa1.c
 * @author Sialas Tripp
 * @brief 
 * @date 2023-09-06
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXTOKEN 256


int getTokens(char *s, char ***args);  // or int getTokens(char s[], char **args[]);

int main()
{
    char **arrayOfTokens = NULL;
    char str[256];
    int numberOfTokens = 0;
    printf("Please, enter the string: ");
    // scanf("%[^\n]%*c", str);
    fgets(str, 256,stdin);
    
    numberOfTokens = getTokens(str, &arrayOfTokens);
    printf("Number of tokens: %d\n", numberOfTokens);
    for (int i = 0; i <= numberOfTokens; i++)
    {
        printf("token %d: %s\n", i + 1, (arrayOfTokens)[i]);
    }
    free(arrayOfTokens);
    return 0;
}

int getTokens(char *s, char ***args)  // or int getTokens(char s[], char **args[]);
{
    int start = 0;
    int end = 0;
    int tokenCount = 0;
    int length = strlen(s);
    char **tokens = malloc(sizeof(char*) * length);
    if (tokens == NULL)
    {
        return -1;
    }
    while (start < length)
    {
        while (start < length && isspace(s[start]))
        {
            start++;
        }
        if (start == length) 
        {
            break;
        }
       
        end = start;
        while (end < length && !isspace(s[end])) 
        {
            end++;
        }
        tokens[tokenCount] = malloc(end - start + 1);
        if (tokens[tokenCount] == NULL) 
        {
            return -1;
        }
        strncpy(tokens[tokenCount], s + start, end - start);
        tokens[tokenCount][end - start] = '\0';
        tokenCount++;
        start = end;
    }
    tokens[tokenCount] = NULL;
    *args = tokens;
    return tokenCount;

}