#include "../cal.h"
#include <assert.h>

void test_is_leap_year()
{
	assert(is_leap_year(2000) == 1);
	assert(is_leap_year(2023) == 0);
	assert(is_leap_year(1812) == 1);
	assert(is_leap_year(1975) == 0);
	assert(is_leap_year(2100) == 0);
}

void test_day_of_week()
{
	assert(day_of_week(1998, 10) == 4);
	assert(day_of_week(2032, 2) == 0);
	assert(day_of_week(1974, 5) == 3);
	assert(day_of_week(1723, 12) == 3);
	assert(day_of_week(2025, 4) == 2);
}

int main(void)
{
	test_is_leap_year();
	test_day_of_week();
	printf("All tests passed\n");
	return (0);
}
