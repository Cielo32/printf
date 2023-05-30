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
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int a = 0;

	while (specifiers[a].specifier)
	{
		if (*s == specifiers[a].specifier[0])
		{
			return (specifiers[a].f);
		}
		a++;
	}
	return (NULL);
}
/**
 * get_print_flag - Find the flag function
 * @s: Format string
 * @params: Parameters struct
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int a = 0;

	switch (*s)
	{
		case '+':
			a = params->plus_flag = 1;
			break;
		case ' ':
			a = params->space_flag = 1;
			break;
		case '#':
			a = params->hashtag_flag = 1;
			break;
		case '-':
			a = params->minus_flag = 1;
			break;
		case '0':
			a = params->zero_flag = 1;
			break;
	}
	return (a);
}
/**
 * get_print_func - Find format function
 * @s: Format string
 * @args: argument pointer
 * @params: Parameters struct
 * Return: Number of bytes printed
 */
int get_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list args, params_t *) = get_specifier(s);

	if (f)
		return (f(args, params));
	return (0);
}
/**
 * get_modifier - Find modifier func
 * @s: Format string
 * @params: Parameters struct
 * Return: If modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int a = 0;

