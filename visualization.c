#include "visualization.h"

/*
    wanted result:
    5 |     #       #
    4 |     #       #   #
    3 | #   #   #   #   #
    2 | #   #   #   #   #
    1 | #   #   #   #   #
    ---------------------
    0   1   2   3   4*/

void DisplayDiagramm(Point *chart, size_t number_of_values)
{
    // Scale:
    // Get the greatest y - Number:
    int highest_y = maxY(chart, number_of_values);
    int lowest_y = minY(chart, number_of_values);

    int highest_x = maxX(chart, number_of_values);
    int lowest_x = minX(chart, number_of_values);
   
    // Display positive y - values

    for (int row = highest_y; row >= 0; row--)
    {
        printf("%d | ", row);
        for (int x_value = lowest_x; x_value <= highest_x; x_value++)
        {
            if (doesXContainInPoints(x_value, chart, number_of_values) && chart[x_value].y_ >= row)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
    int lowest_x_visual = lowest_x > 0 ? 0 : lowest_x;
    for (int x_value = lowest_x_visual; x_value <= 7 + highest_x; x_value++)
        printf("-");
    printf("\n");
    for (int x_value = lowest_x_visual; x_value <= highest_x + 3; x_value++)
    {
        printf(" ");
        if (x_value >= 3)
            printf("%d", x_value - 3);
    }

    printf("\n");
}
