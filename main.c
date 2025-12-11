
//Global Headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Local Headers
#include "visualization.h"
#include "algorithms.h"
#include "data_management.h"

int main(void)
{
    Point points[20];
    for(int i = 0; i < 20; i++)
    {
        points[i].x_ = i;
        points[i].y_ = rand() % 20+1;
    }

    DisplayDiagramm(points,20);
    return 0;
}