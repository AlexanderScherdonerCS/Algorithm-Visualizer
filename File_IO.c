#include "File_IO.h"

FILE *FileOpen(char filename[])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("No %s in the local folder!", filename);
    }
    return file;
}

File_Error setCurserToLine(FILE *file, int line, char *filename)
{
    for (int i = 0; i < line; i++)
    {
        int file_output;
        while ((file_output = fgetc(file)) != '\n')
        {
            if (file_output == EOF)
            {
                printf("This line is not existing in %s", filename);
                fclose(file);
                return END_OF_FILE;
            }
        }
    }
    return NO_FILE_ERROR;
}
