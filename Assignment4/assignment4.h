/*
* File: assignment4.h
* Owner: Hojun Kwak
* Date: 4.11.2024
* Description: Implementing a shell program in C
*/
#ifndef ASSIGNMENT4
#define ASSIGNMENT4

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void command_line_parse(char *input, char *command, char **arguments);
void command_line_execute(char *command, char **arguments);

#endif
