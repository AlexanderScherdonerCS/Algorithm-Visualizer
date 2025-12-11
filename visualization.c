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
        printf("%d ", row);
        addChar(row, highest_y, ' ');
        printf("|");
        for (int x_value = lowest_x; x_value <= highest_x; x_value++)
        {
            addChar(0, highest_x, ' ');
            if (doesXContainInPoints(x_value, chart, number_of_values) && chart[x_value].y_ >= row)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
    int lowest_x_visual = lowest_x > 0 ? 0 : lowest_x;
    printf("----");
    for (int i = 0; i <= number_of_values * 3; i++)
    {
        addChar(0, highest_x, '-');
    }
    printf("\n");
    for (int x_value = lowest_x_visual; x_value <= highest_x + 3; x_value++)
    {
        printf(" ");
        if (x_value >= 3)
        {
            addChar(x_value - 3, highest_x, ' ');
            printf("%d", x_value - 3);
        }
    }

    printf("\n");
}

void addChar(int act_row, int highest_y, char character)
{
    int row_digits = 0;
    int highest_number_digits = 0;

    if (act_row != 0)
        row_digits = log10((double)abs(act_row));
    if (highest_y != 0)
        highest_number_digits = log10((double)abs(highest_y));

    int num_iteration = highest_number_digits - row_digits;
    for (int i = 0; i < num_iteration; i++)
    {
        printf("%c", character);
    }
}
