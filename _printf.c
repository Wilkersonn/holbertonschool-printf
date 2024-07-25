#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}

	return (count);
}

/**
 * handle_specifier - Handles the conversion specifiers.
 * @spec: The conversion specifier.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int handle_specifier(char spec, va_list args)
{
	if (spec == 'c')
		return (print_char(va_arg(args, int)));
	if (spec == 's')
		return (print_string(va_arg(args, char *)));
	if (spec == '%')
		return (write(1, "%", 1));

	write(1, "%", 1);
	return (write(1, &spec, 1) + 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *p;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			count += handle_specifier(*p, args);
		}
		else
		{
			count += write(1, p, 1);
		}
	}

	va_end(args);
	return (count);
}
