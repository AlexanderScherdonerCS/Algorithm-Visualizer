#ifndef IO_FILE_H_
#define IO_FILE_H_

#include <stdio.h>

typedef enum _FILE_ERROR_
{
    NO_FILE_ERROR,
    FILE_NOT_ACCESSABLE,
    END_OF_FILE
} File_Error;

FILE *FileOpen(char filename[]);
File_Error setCurserToLine(FILE *file, int line, char *file_name);
#endif