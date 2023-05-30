#includ "main.h"

/**
 * get_specifier - finds the format function
 * @s: Format string
 * Return: Number of bytes printed
 */
int (*get_specifier(char *s))(va_list args, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", printint},
		{"s", print_string},
		{"%", print_percent},
