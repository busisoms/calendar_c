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
 * number_of_days - returns number of day according to month
 * @mon: month
 * @yr: year
 *
 * Return: number of days in a month (MIN 28 - MAX 31)
 */

int number_of_days(int mon, int yr)
{
	switch (mon)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return (31);
		case 4:
		case 6:
		case 9:
		case 11:
			return (30);
		case 2:
			return ((is_leap_year(yr) == 1) ? 29 : 28);
		default:
			return (-1);
	}
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
