#include "cal.h"

/**
 * get_date - checks the number of given parts of the date
 * @date: array 
 *
 * Return: number of items in date
 * otherwise 0 if array is empty
 */

unsigned int get_date(char **date)
{
	unsigned int count = 0;

	if (date == NULL)
		return (0);

	while (date[count] != NULL)
	{
		count++;
	}

	return (count);
}

