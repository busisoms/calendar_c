#include "../cal.h"
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>

void test_tokenize_valid_date()
{
	char date[] = "10/2032";
	char **tokens = tokenize(date);
	assert(tokens != NULL);
	assert(strcmp(tokens[0], "10") == 0);
	assert(strcmp(tokens[1], "2032") == 0);
	assert(get_date(tokens) == 2);
	free(tokens);
}

void test_tokenize_invalid_date()
{
	char date[] = "10/2023/extra";
	char **tokens = tokenize(date);
	assert(tokens == NULL);
}

void test_tokenize_short_date()
{
	char date[] = "2023";
	char **tokens = tokenize(date);
	assert(tokens != NULL);
	assert(strcmp(tokens[0], "2023") == 0);
	assert(get_date(tokens) == 1);
	free(tokens);
}

void test_get_date_empty()
{
	char **empty = NULL;
	assert(get_date(empty) == 0);
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
	test_tokenize_valid_date();
	test_tokenize_invalid_date();
	test_tokenize_short_date();
	test_get_date_empty();
	printf("All tests passed!\n");
	return (0);
}
