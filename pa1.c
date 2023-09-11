/**
 * @file pa1.c
 * @author Sialas Tripp
 * @brief 
 * @date 2023-09-06
 * 
 */

#include <stdio.h>

int getTokens(char *s, char ***args);  // or int getTokens(char s[], char **args[]);

main()
{
    char *cptr;
    char str2[50];
    printf("Please, enter the string: ");
    cptr = fgets(str2,256, stdin);
    printf("You typed: %s\n", cptr);
    char **arrayOfTokens, str[] = "ls -l file";
    int numberOfTokens;
    numberOfTokens = getTokens(str, &arrayOfTokens);
    return 0;
}

int getTokens(char *s, char ***args)  // or int getTokens(char s[], char **args[]);
{


}