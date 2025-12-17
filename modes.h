#ifndef MODES_H_
#define MODES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "File_IO.h"

#include "algorithms.h"

typedef enum _COMMAND_
{
    NO_COMMAND,
    SET_BY_HAND,
    SET_RANDOM,
    BUBBLE_SORT,
    INSERTION_SORT,
    LINEAR_SEARCH,
    TREE_DATASTRUCTURE,
    QUIT,
    HELP,
    NUMBER_OF_MODES
}Command;

typedef enum _USER_ERROR_CODE_
{
    UNKNOWN_COMMAND,
    WRONG_FORMAT,
    NO_ERROR = -1
}User_Error_Code;

Command getMode();
Command convertToMode(int user_input);
void printModeDescription();
int convertToNumber(char number);
void printError(User_Error_Code error);

User_Error_Code executeCommand(Command command, int* points);
User_Error_Code setNumbersByHand(int *output_points);
void setNumbersRandom(int *output_points, int in_number_of_values);


int getNumber();

#endif