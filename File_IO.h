#ifndef IO_FILE_H_
#define IO_FILE_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef enum _FILE_ERROR_
{
    NO_FILE_ERROR,
    FILE_NOT_ACCESSABLE,
    NOT_SEEKABLE,
    END_OF_FILE
} File_Error;

FILE *FileOpen(char filename[]);
File_Error setCurserToLine(FILE *file, int line, char *file_name);

FILE *openXMLFile(char fileplace[]);
File_Error getXMLPoints(char fileplace[], int out_points[]);
File_Error setCurserTo(FILE *xml_file, char *target_place);
File_Error setCurserToNextInteger(FILE *xml_file);
bool isInteger(int character);
int getCurrentNumber(FILE *xml_file);


#endif