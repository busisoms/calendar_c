#include "cal.h"

/**
 * tokenize - tokenizes a string
 * @string: string
 *
 * Return: Array of strings
 */

char **tokenize(char *string)
{
	char **tokens = malloc(4 * sizeof(char*));
	int token_count = 0;
	char *token;
	char *delimit = "/";

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed");
		return (NULL);
	}

	token = strtok(string, delimit);
	while (token != NULL && token_count < 3)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, delimit);
	}

	tokens[token_count] = NULL;

	if (token != NULL)
	{
		fprintf(stderr, "Error: Invaild date (too many parts)\n");
		free(tokens);
		return (NULL);
	}

	return (tokens);
}

