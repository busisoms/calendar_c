#include "../cal.h"
#include <assert.h>
#include <sys/wait.h>
#include <unistd.h>

void test_is_4_digits()
{
	assert(is_4_digits("2023") == 0);
	assert(is_4_digits("0000") == 0);

	assert(is_4_digits("202") == 1);
	assert(is_4_digits("20230") == 1);
	assert(is_4_digits("20a3") == 1);
	assert(is_4_digits("") == 1);
}

void test_is_month()
{
	assert(is_month("1") == 0);
	assert(is_month("12") == 0);
	assert(is_month("01") == 0);

	assert(is_month("0") == 1);
	assert(is_month("13") == 1);
	assert(is_month("foo") == 1);
	assert(is_month("1a") == 1);
	assert(is_month("100") == 1);
}

void test_validate()
{
	char *valid1[] = {"10", "2023", NULL};
	int *res1 = validate(valid1);
	assert(res1[0] == 10 && res1[1] == 2023);
	free(res1);

	char *valid2[] = {"2024", NULL};
	int *res2 = validate(valid2);
	assert(res2[0] == 0 && res2[1] == 2024);
	free(res2);

	char *valid3[] = {"3", NULL};
	int *res3 = validate(valid3);
	assert(res3[0] == 3 && res3[1] == get_current_year());
	free(res3);
}

void test_get_current_year()
{
	time_t now = time(NULL);
	struct tm t = *localtime(&now);
	int expected = t.tm_year + 1900;
	assert(get_current_year() == expected);
}


void test_error_condition(void (*test_func)(void))
{
	if (fork() == 0)
	{
		test_func();
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}

int main(void)
{
	test_is_4_digits();
	test_is_month();
	test_validate();
	test_get_current_year();

	printf("All tests passed!\n");
	return 0;
}
