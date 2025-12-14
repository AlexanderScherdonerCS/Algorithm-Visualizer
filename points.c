#include "points.h"

int *getXValues(Point *points, size_t size)
{
    int *result = malloc(size * sizeof(int));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        result[i] = points[i].x_;
    }
    return result;
}
int *getYValues(Point *points, size_t size)
{
    int *result = malloc(size * sizeof(int));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        result[i] = points[i].y_;
    }
    return result;
}

int max(int *numbers, size_t size)
{
    int max = *numbers;
    for (int i = 0; i < size; i++)
    {
        if (max < numbers[i])
            max = numbers[i];
    }
    return max;
}
int maxY(Point *points, size_t size)
{
    int *y_numbers = getYValues(points, size);
    int result = max(y_numbers, size);
    free(y_numbers);
    return result;
}
int maxX(Point *points, size_t size)
{
    int *x_numbers = getXValues(points, size);
    int result = max(x_numbers, size);
    free(x_numbers);
    return result;
}

int min(int *numbers, size_t size)
{
    int min = *numbers;
    for (int i = 0; i < size; i++)
    {
        if (min > numbers[i])
            min = numbers[i];
    }
    return min;
}
int minY(Point *points, size_t size)
{
    int *y_numbers = getYValues(points, size);
    int result = min(y_numbers, size);
    free(y_numbers);
    return result;
}
int minX(Point *points, size_t size)
{
    int *x_numbers = getXValues(points, size);
    int result = min(x_numbers, size);
    free(x_numbers);
    return result;
}

bool doesXContainInPoints(int search_number, Point *points, size_t size)
{
    for (int i = 0; i < size; i++)
        if (points[i].x_ == search_number)
            return true;

    return false;
}
bool doesYContainInPoints(int search_number, Point *points, size_t size)
{
    for (int i = 0; i < size; i++)
        if (points[i].x_ == search_number)
            return true;

    return false;
}