#ifndef CAL_H
#define CAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char **tokenize(char *string);
unsigned int get_date(char **date);
int is_4_digits(char *str);
int get_current_year(void);
int is_month(char *str);
void error_msg(const char *message);
int *validate(char **tokens);

#endif

