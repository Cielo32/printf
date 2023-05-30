#include "main.h"

/**
 * _puts - Prints a string with newline
 * @str: String to print
 * Return: void
 */
int _puts(char *str)
{
	char *z = str;
	while (*str)
		_putchar(*str++);
	return (str - z);
}

/**
 * _putchar _ Character c to stdout
 * @c: Character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int a;
	static char buf[OUTPUT_BUF_SIZE];
	if (c == BUF_FLUSH || a >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c !=BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
