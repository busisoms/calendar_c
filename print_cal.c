#include "cal.h"

/**
 * calendar_grid - creates a 6 x 7 grid and fills it with days
 * of a month
 * @yr: year
 * @mon: month
 *
 * Return: grid
 */

int *calendar_grid(int yr, int mon)
{
	int i, j;
	int day = 1;
	int start = day_of_week(yr, mon)
		int num_of_days = number_of_days(mon, yr);
	int row, col;
	int *grid = (int*)malloc(6 * 7* sizeof(int));

	if (grid == NULL)
		error_msg("Error: memory allocation failed\n");

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			grid[i * 7 + j] = -1;
		}
	}

	row = 0;
	col = start;
	while (day <= num_of_days)
	{
		if (row >= 6)
			break;

		grid[row * 7 + col] = day++;
		col++;

		if (col >= 7)
		{
			col = 0;
			row ++;
		}
	}

	return (grid);
}

/**
 * print_month - prints a calendar month
 * @yr: year
 * @mon: month
 *
 */

void print_month(int yr, int mon)
{
	int *days = calendar_grid(yr, mon);
	int i, j;
	char *months = {
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"};
	char str_month[50];

	snprintf(str_month, sizeof(str_month), "%s %d", months[mon - 1], yr);
	printf("%*s\n", (20 + strlen(str_month)) / 2, str_month);
	printf("Su Mo Tu We Th Fr Sa  \n");
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (days[i * 7 + j] == -1)
			{
				printf("  ");
			}
			else
			{
				printf("%-3d", days[i * 7 + j]);
			}
		}
		printf("\n");
	}
	free(days);
}

