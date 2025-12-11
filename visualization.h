
#ifndef VISUALIZATION_H_
#define VISUALIZATION_H_

//Global Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Local Header Files
#include "data_management.h"

//Constants
#define MAX_CHART_LENGTH 20

//Functions:

void DisplayDiagramm(Point* chart, size_t number_of_values);
void addChar(int act_row, int highest_y, char character);


#endif /*VISUALIZATION_H_*/