
//Global Headers
#include <stdio.h>
#include <stdlib.h>

//Local Headers
#include "visualization.h"
#include "algorithms.h"
#include "data_management.h"

int main(void)
{
    Point* points;
    for(int i = 0; i <= 10; i++)
    {
        points[i].x_ = i;
        points[i].y_ = i;
    }

    DisplayDiagramm(points,10);
    return 0;
}