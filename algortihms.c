#include "algorithms.h"

void BubbleSort(Point *points, int number_of_points)
{
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j=0; j < number_of_points + 1; j++)
        {
            if(points[j].y_ >= points[j+1].y_)
            {
                int temp_y = points[j].y_;
                points[j].y_ = points[j+1].y_ ;
                points[j+1].y_ = temp_y;
            }
        }
    }
}