#include "shell.h"

/**
 * interactive - checks if shell is in interactive mode
 * @add: arg struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *add)
{
	return (add->readfd <= 2 && isatty(STDIN_FILENO));
}


/**
 * delimeter - checks if character is a delimeter
 * @c: the char to check
 * @str: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delimeter(char c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: arg, character to check
 *Return: 1 if true, 0 if false
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - fn to convert a str arg into an int
 *@s: the str arg to be converted
 *Return: 0 if err(not convertable), converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, checker_flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && checker_flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			checker_flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (checker_flag == 1)
			checker_flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
