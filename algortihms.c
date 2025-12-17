#include "algorithms.h"

void BubbleSort(int *points, int number_of_points)
{
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = 1; j < number_of_points; j++)
        {
            if (points[j-1] >= points[j])
            {
                int temp_y = points[j-1];
                points[j-1] = points[j];
                points[j] = temp_y;
            }
        }
    }
}
void insertionSort(int points[], int number_of_points)
{
    for (int i = 1; i < number_of_points; ++i)
    {
        int key = points[i];
        int j = i - 1;

        while (j >= 0 && points[j] > key)
        {
            points[j + 1] = points[j];
            j = j - 1;
        }
        points[j + 1] = key;
    }
}