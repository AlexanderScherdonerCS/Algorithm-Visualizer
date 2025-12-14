#ifndef DATAMANGEMENT_H_
#define DATAMANGEMENT_H_

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// enums

// structs
typedef struct _POINT_
{
    int x_;
    int y_;
} Point;

// Point functions
void setPoints(Point* points);

int *getXValues(Point *points, size_t size);
int *getYValues(Point *points, size_t size);

int max(int *numbers, size_t size);
int maxY(Point *points, size_t size);
int maxX(Point *points, size_t size);

int min(int *numbers, size_t size);
int minY(Point *points, size_t size);
int minX(Point *points, size_t size);

bool doesXContainInPoints(int search_number, Point *points, size_t size);
bool doesYContainInPoints(int search_number, Point *points, size_t size);

#endif /*DATAMANGEMENT_H_*/