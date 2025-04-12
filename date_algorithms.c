#include "cal.h"

/**
 * is_leap_year - checks if a year is a leap year
 * @year: year
 *
 * Return: 1 if year is a leap year
 * otherwise return 0
 */

int is_leap_year(int year)
{
	if (year % 400 == 0)
		return (1);

	if (year % 100 == 0)
		return (0);

	if (year % 4 == 0)
		return (1);

	return (0);
}


/**
 * day_of_week - calculates the day of the week using Zeller's
 * congruence
 * @yr: year
 * @mon: month (1 - 12)
 *
 * Return: 0 (sunday) to 6 (saturday)
 */

int day_of_week(int yr, int mon)
{
	int q = 1;
	int m = mon;
	int K, J, h;

	if (m < 3)
	{
		m += 12;
		yr -= 1;
	}
	K = yr % 100;
	J = yr / 100;

	h = (q + (13 * (m + 1) / 5) + K + (K / 4) + (J / 4) + 5 * J) % 7;

	return ((h + 6) % 7);
}
