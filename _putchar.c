#include "main.h"
<<<<<<< HEAD
=======


/**
 * _putchar - stdout the char via write
 * @c: char to print
 * Return: 1 if (Success) and -1 if (UnSuccess)
 **/

>>>>>>> 0b066b44c23954bce0ee2fcf5a817955a72622ae
int _putchar(char c)
{
	return (buffer(c));
}
<<<<<<< HEAD
=======


/**
 * buffer - save char in the buffer
 * @c: char
 *
 * Return: 1
 **/

>>>>>>> 0b066b44c23954bce0ee2fcf5a817955a72622ae
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
