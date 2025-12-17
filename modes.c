#include "modes.h"

void printModeDescription()
{
    printf("\n"
           "This programm contains the following Command:\n"
           "1: Set numbers by hand\n"
           "2: Set numbers random (not necessary at the start)\n"
           "3: Sort elements with Bubble Sort\n"
           "4: Sort elements with insertion Sort\n"
           "5: Sort elements with linear Search\n"
           "6: Sort elements with an tree Datastructure\n"
           "q: Quit\n");
}

Command getMode()
{
    int user_input;
    Command command = NO_COMMAND;
    do
    {
        printModeDescription();
        printf("> ");
        while ((user_input = getchar()) != '\n')
        {
            if (tolower(user_input) == 'q')
            {
                command = QUIT;
                break;
            }
            if (convertToNumber((char)user_input) >= 0 && convertToNumber((char)user_input) <= 6)
            {
                command = (Command)convertToNumber((char)user_input);
                break;
            }
        }
        if (user_input == '\n')
        {
            printError(UNKNOWN_COMMAND);
            continue;
        }
        else
        {
            while ((user_input = getchar()) != '\n')
            {
                if (!isspace(user_input))
                {
                    printError(UNKNOWN_COMMAND);
                    continue;
                }
            }
        }
    } while (0);
    return command;
}

int convertToNumber(char number)
{
    return tolower(number) - '0';
}

User_Error_Code executeCommand(Command command, int *points)
{
    int number_of_points = 20;
    User_Error_Code error_code = NO_ERROR;
    switch (command)
    {
    case SET_BY_HAND:
        error_code = setNumbersByHand(points);
        break;
    case SET_RANDOM:
        setNumbersRandom(points, number_of_points);
        break;
    case BUBBLE_SORT:
        BubbleSort(points, number_of_points);
        break;
    case INSERTION_SORT:
        insertionSort(points, number_of_points);
        break;
    case LINEAR_SEARCH:
        break;
    case TREE_DATASTRUCTURE:
        break;
    case HELP:
        printModeDescription(); // ka
        break;
    case QUIT:
        break;
    default:
        break;
    }
    return error_code;
}

void printError(User_Error_Code error)
{
    char filename[] = "Error_Codes.txt";
    if (error == UNKNOWN_COMMAND)
    {
        FILE *error_file = FileOpen(filename);
        int file_output;
        // put the curser in the correct line

        setCurserToLine(error_file, (int)error, filename);

        char *error_text = malloc(1);
        *error_text = '\0';
        while ((file_output = fgetc(error_file)) != '\n' && file_output != EOF)
        {
            int length = strlen(error_text);
            char *temp = realloc(error_text, (length + 1) * 2);
            if (!temp)
            {
                printf("Realloc not worked");
                free(error_text);
                fclose(error_file);
                return;
            }
            error_text = temp;
            error_text[length] = file_output;
        }

        error_text = realloc(error_text, strlen(error_text));

        printf("\nError Code: %s\n", error_text);
        free(error_text);
        fclose(error_file);
    }
}

User_Error_Code setNumbersByHand(int *output_points)
{
    int number_of_values = getNumber();

    output_points = malloc(number_of_values * sizeof(int *));
    if (!output_points)
    {
        printf("Allocoation Error");
    }
    for (int i = 0; i < number_of_values; i++)
    {
        output_points[i] = getNumber();
    }
    return NO_ERROR;
}
void setNumbersRandom(int *output_points, int in_number_of_values)
{
    for (int i = 0; i < in_number_of_values; i++)
    {
        output_points[i] = rand() % 20;
    }
}

int getNumber()
{

    printf("Please enter a number: ");
    int result = 0;
    int number_of_inputs = 0;
    do
    {
        int user_input = 0;

        while ((user_input = getchar()) == '\n')
        {
            if (isdigit(user_input))
            {
                result = user_input + (int)(pow(10, number_of_inputs));
            }
            else
            {
                printError(WRONG_FORMAT);
                number_of_inputs = 0;
            }
        }
    } while (number_of_inputs == 0);
    return result;
}
