#include "cal.h"

/**
 * main - entry point
 * @argc: number of args
 * @argv: pointer to args
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	char **tokens;
	int *vaild_date;


	if (argc < 2)
		error_msg("Error: No date provided\n");

	tokens = tokenize(argv[1]);
	vaild_date = validate(tokens);
	if (vaild_date[0] != 0)
	{
		print_month(vaild_date[1], vaild_date[0]);
	}
	else
	{
		print_year(vaild_date[1]);
	}

	free(tokens);
	free(vaild_date);
	return (0);
}

