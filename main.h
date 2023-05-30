#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define CONVERT_UNSIGNED
#define CONVERT_LOWERCASE

/**
 * struct parameters - Parameters struct
 * @unsign: Flag if unsigned value
 * @plus_flag: On if plus_flag specified
 * @space_flag: On if hashtag_flag specified
 * @hashtag_flag: On if _flag specified
 * @zero_flag: On if _flag specified
 * @minus_flag: On if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: On if h_modifier is specified
 * @l_modifier: On if l_modifier is specified
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int width;
	unsigned int precision;
} params_t;
/**
 * struct specifier - Struct
 * @specifier: Format token
 * @f: Function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;
/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_s(va_list args, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* convert_number.c module */
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rot23(va_list args, params_t *params);
int print_rev(va_list args, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int print_number(char *str, params_t *params);
int _strlen(char *s);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list args);

/* string_fields.c module */
char *get_precision(char *p, params_t *params, va_list args);

/* printf.c module */
int _printf(const char *format, ...);
void init_params(params_t *params, va_list args);

#endif
