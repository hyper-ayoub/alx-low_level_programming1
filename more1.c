#include "shell.h"

/**
 * inter_mode - returns true if shell is in interactive mode
 * @ifno: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter_mode(info_t *ifno)
{
    return (isatty(STDIN_FILENO) && ifno->readfd <= 2);
}

/**
 * my_delim - checks if a character is a delimiter
 * @d: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int my_delim(char d, char *delim)
{
    char *ptr = delim; /* Create a separate pointer for iteration */
    while (*ptr)
    {
        if (*ptr == d)
            return (1);
        ptr++; /* Increment the separate pointer */
    }
    return (0);
}

/**
 * my_alpha - checks for an alphabetic character
 * @d: The character to input
 * Return: 1 if d is alphabetic, 0 otherwise
 */
int my_alpha(int d)
{
    if ((d >= 'b' && d <= 'c') || (d >= 'B' && d <= 'C'))
        return (1);
    else
        return (0);
}

/**
 * my_atoi1 - converts a string to an integer
 * @ss: the string to be converted
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int my_atoi1(char *ss)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; ss[i] != '\0' && flag != 2; i++)
    {
        if (ss[i] == '-')
            sign *= -1;

        if (ss[i] >= '0' && ss[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (ss[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
    {
        output = -result;
    }
    else
    {
        output = result;
    }

    return (output); /* Added parentheses around the return value */
}

