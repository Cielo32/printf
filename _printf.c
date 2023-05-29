#include "main.h"

/**
 * _printf - printd anything
 * @format: Format string
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int s = 0;
	char *b, *z;
	va_list args;
	params_t params = PARAMS_INIT;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_params(&params, args);
		if (*b != '%')
		{
			s += _putchar(*b);
			continue;
		}
		z = b;
		b++;
		while (get_flag(b, &params))
		{
			b++;
		}
		b = get_width(p, &params, args);
		b = get_precision(b, &params, args);
		if (get_modifier(b, &params))
			b++;
		if (!get_specifier(b))
			s += print_from_to(z, b,
					params.l_modifier || params.h_modifier ? b - 1 : 0);
		else
			s += get_print_func(b, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (s);
}
