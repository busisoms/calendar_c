#include "cal.h"

/**
 * months - determines the month
 * @mon: month
 *
 * Return: string form of month
 */

char *months(int mon)
{
	switch (mon)
	{
		case 1:
			return ("January ");
		case 2:
			return ("February ");
		case 3:
			return ("March ");
		case 4:
			return ("April ");
		case 5:
			return ("May ");
		case 6:
			return ("June ");
		case 7:
			return ("July ");
		case 8:
			return ("August ");
		case 9:
			return ("September ");
		case 10:
			return ("October "); 
		case 11:
			return ("November ");
		case 12:
			return ("December ");
		default:
			return (" ");
	}
}

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
	int start = day_of_week(yr, mon);
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
	char str_month[50];
	char year[20];

	strcpy(str_month, months(mon));
	sprintf(year, "%d", yr);
	strcat(str_month, year);

	printf("%*s\n", (int)((20 + strlen(str_month)) / 2), str_month);
	printf("Su Mo Tu We Th Fr Sa\n");
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (days[i * 7 + j] == -1)
			{
				printf("   ");
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

/**
 * print_year - prints a full year
 * @yr: year
 *
 */

void print_year(int yr)
{
	int i, j, k, m;
	int *grids[12];
	int *days;
	char *month_names[12], *name;
	char year_str[20];
	int name_len, pad, val;

	sprintf(year_str, "%d", yr);
	printf("%*s\n\n", (int)((64 + strlen(year_str)) / 2), year_str);

	for (i = 0; i < 12; i++)
	{
		grids[i] = calendar_grid(yr, i + 1);
		month_names[i] = months(i + 1);
	}

	for (i = 0; i < 12; i += 3)
	{
		for (j = 0; j < 3; j++)
		{
			name = month_names[i + j];
			name_len = strlen(name);
			pad = (20 - name_len) / 2;
			printf("%*s%*s", pad + name_len, name, (20 - pad - name_len), "");
			if (j < 2)
				printf("  ");
		}
		printf("\n");

		for (j = 0; j < 3; j++)
		{
			printf("Su Mo Tu We Th Fr Sa ");
			printf(" ");
		}
		printf("\n");

		for (j = 0; j < 6; j++)
		{
			for (k = 0; k < 3; k++)
			{
				days = grids[i + k];
				for (m = 0; m < 7; m++)
				{
					val = days[j * 7 + m];
					if (val == -1)
					{
						printf("   ");
					}
					else
					{
						printf("%-3d", val);
					}
				}
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}

	for (i = 0; i < 12; i++)
		free(grids[i]);
}

