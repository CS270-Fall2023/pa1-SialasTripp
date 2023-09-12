/**
 * @file functions.h
 * @author Sialas Tripp
 * @brief Function header file
 * @date 2023-09-11
 * 
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getTokens(char *s, char ***args);  // or int getTokens(char s[], char **args[]);

#endif // FUNCTIONS_H