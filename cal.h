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
int is_leap_year(int year);
int day_of_week(int yr, int mon);
int number_of_days(int mon, int yr);
int *calendar_grid(int yr, int mon);
char *months(int mon);
void print_month(int yr, int mon);
void print_year(int yr);

#endif

