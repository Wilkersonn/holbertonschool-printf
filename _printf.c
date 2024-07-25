#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int print_char(char c);
int print_string(char *s);
int handle_specifier(char spec, va_list args);

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
			write(1, p, 1);
			count++;
		}
	}

	va_end(args);
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
	int count = 0;
	char c;
	char *s;

	if (spec == 'c')
	{
		c = (char)va_arg(args, int);
		count = print_char(c);
	}
	else if (spec == 's')
	{
		s = va_arg(args, char *);
		if (s == NULL)
			s = "(null)";
		count = print_string(s);
	}
	else if (spec == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	else
	{
		write(1, "%", 1);
		write(1, &spec, 1);
		count = 2;
	}

	return (count);
}

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
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

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}

	return (count);
}
