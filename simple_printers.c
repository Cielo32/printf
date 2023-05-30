#include "main.h"

/**
 * print_from_to - Prints a range of char addresses
 * @start: Starting adress
 * @stop: Stopping address
 * @except: Except adress
 * Return: Except adress
 */
int print_from_to(char *start, char *stop, char *except)
{
	int s = 0;

	while (start <= stop)
	{
		if (stat != except)
			s += _putchar(*start);
		start++;
	}
	return (s);
}
/**
 * print_rev - prints string in reverse
 * @args: String
 * @params: Parameters struct
 * Return: Number bytes printed
 */
int print_rev(va_list args, params_t *params)
{
	int l, s = 0;
	char *str = va_arg(args, char *);
	(void)params;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; l--; str--)
			s += _putchar(*str);
	}
	return (s);
}
/**
 * print_rot13 - Prints string in rot13
 * @args: String
 * @params: Parameters struct
 * Return: Number bytes printed
 */
int print_rot13(va_list args, params_t *params)
{
	int d = 0, b = 0;
	int c = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzqbcdefghijklm";
	char *a = va_arg(args, char *);
	(void)params;

	while (a[d])
	{
		if ((a[d] >= 'A' && a[d] <= 'Z')
			|| (a[d] >= 'a' && a[d] <= 'z'))
	{
		b = a[d] - 65;
		c += _putchar(arr[b]);
	}
	else
		c += _putchar(a[d]);
	d++;
	}
	return (c);
}
