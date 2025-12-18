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

FILE *openXMLFile(char fileplace[])
{
    FILE *xml_file = fopen(fileplace, "r");

    if (!xml_file)
    {
        printf("\nNo xml File at this file place: %s\n", fileplace);
        return NULL;
    }

    return xml_file;
}
File_Error getXMLPoints(char fileplace[], int out_points[])
{
    FILE *xml_file = openXMLFile(fileplace);

    if (!xml_file)
        return FILE_NOT_ACCESSABLE;

    setCurserTo(xml_file, "Y-Values");
    int point_counter = 0;
    while (point_counter < 20)
    {
        setCurserTo(xml_file, "Row");
        setCurserTo(xml_file, "Number");
        if (setCurserToNextInteger(xml_file) == END_OF_FILE)
            break;
        int next_number = getCurrentNumber(xml_file);
        out_points[point_counter++] = next_number;
    }
    fclose(xml_file);
    return NO_FILE_ERROR;
}

File_Error setCurserTo(FILE *xml_file, char *target_place)
{
    int character;
    int state_counter = 0;
    int length = strlen(target_place);
    while ((character = getc(xml_file)) != EOF)
    {
        if (character == target_place[state_counter])
        {
            state_counter++;
            if (state_counter == length)
            {
                break;
            }
        }
    }
    ungetc(character, xml_file);
    return state_counter == length ? NO_FILE_ERROR : END_OF_FILE;
}
File_Error setCurserToNextInteger(FILE *xml_file)
{
    int character;
    while ((character = getc(xml_file)) != EOF)
    {

        if (isInteger(character - '0'))
        {
            break;
        }
    }

    ungetc(character, xml_file);
    return character == EOF ? END_OF_FILE : NO_FILE_ERROR;
}

bool isInteger(int character)
{
    return 0 <= character && character <= 9;
}
int getCurrentNumber(FILE *xml_file)
{
    int result = 0;
    int input = 10;

    while ((input = fgetc(xml_file) - '0') != EOF && isInteger(input))
    {

        result = (result * 10) + (input);
    }

    return result;
}
