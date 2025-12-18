// Global Headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Local Headers
#include "visualization.h"
#include "algorithms.h"
#include "points.h"
#include "modes.h"

#define NUMBER_OF_POINTS 20

// main functions
void printWelcomeMessage();
void printModeDescription();

int main(void)
{
    printWelcomeMessage();
    Command mode;
    Point points[NUMBER_OF_POINTS];
    int y_values[NUMBER_OF_POINTS];
    setNumbersRandom(y_values, NUMBER_OF_POINTS);

    convertIntegerToPoint(y_values,points,NUMBER_OF_POINTS);
    DisplayDiagramm(points, NUMBER_OF_POINTS);
    do
    {
        mode = getMode();
        printError(executeCommand(mode, y_values));
        convertIntegerToPoint(y_values, points, NUMBER_OF_POINTS);
        DisplayDiagramm(points, NUMBER_OF_POINTS);
    } while (mode != QUIT);

    return 0;
}

void printWelcomeMessage()
{
    printf("-----------------WELCOME to the Algorithm Visualizer-----------------\n");
}



