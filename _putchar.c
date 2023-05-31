#include "main.h"
int _putchar(char c)
{
	return (buffer(c));
}
int buffer(char c)
{
	static char buff[BUFFER_SIZE];
	static int i;

	if (c == -1 || i == BUFFER_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}

	if (c != -1)
	{
		buff[i++] = c;
	}

	return (1);
}
