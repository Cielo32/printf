#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int _printf(const char *format, ...);
void init_params(params_t *params, va_list args);

#endif
