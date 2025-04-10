#include "cal.h"

/**
 * is_4_digits - checks if string is 4 chars long
 * @str: pointer to string
 *
 * Return: 0 on success
 * else return 1
 */

int is_4_digits(char *str)
{
	size_t i;

	if (strlen(str) != 4)
		return (1);

	for (i = 0; i < 4; i++)
	{
		if (!isdigit((unsigned char)str[i]))
			return (1);
	}

	return (0);
}

/**
 * is_month - checks if string is a valid month
 * @str: month string
 *
 * Return: 0 if valid month, 1 otherwise
 */

int is_month(char *str)
{
	unsigned int i;
	int month;

	if (strlen(str) < 1 || strlen(str) > 2)
		return (1);

	for (i = 0; i < strlen(str); i++)
	{
		if (!isdigit((unsigned char)str[i]))
			return (1);
	}

	month = atoi(str);

	if (month < 1 || month > 12)
		return (1);
	return (0);
}

/**
 * get_current_year - returns current month
 *
 * Return: current year 
 */

int get_current_year(void)
{
	time_t t = time(NULL);
	struct tm date = *localtime(&t);
	int year = date.tm_year + 1900;

	return (year);
}

/**
 * error_msg - prints an error message and exits
 * @message: Error message
 *
 */

void error_msg(const char *message)
{
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}

/**
 * validate - validates the input args for the date
 * tokens: arrays of strings
 *
 * Return: Array of integers
 */

int *validate(char **tokens)
{
	int i, year = -1, month = -1;
	int *date = (int *)malloc(2*sizeof(int));
	unsigned int token_count = get_date(tokens);
	char *month_str;

	if (date == NULL)
		error_msg("Error: Memory allocation failed\n");

	if (token_count == 2)
	{
		for (i = 0; i < 2; i++)
		{
			if (is_4_digits(tokens[i]) == 0)
			{
				year = atoi(tokens[i]);
				month_str = tokens[1 - i];

				if (is_month(month_str) != 0)
					error_msg("Error: Invalid month format\n");
				month = atoi(month_str);
				break;
			}
		}
		if (year == -1)
			error_msg("Error: Year must be 4 digits\n");
	}
	else if (token_count == 1)
	{
		if (is_4_digits(tokens[0]) == 0)
		{
			year = atoi(tokens[0]);
			month = 0;
		}
		else
		{
			if (is_month(tokens[0]) != 0)
				error_msg("Error: Invalid month\n");

			year = get_current_year();
			month = atoi(tokens[0]);
		}
	}
	else
		error_msg("Error: Invalid token count\n");

	date[0] = month;
	date[1] = year;

	return (date); 
}

