#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

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
			if (*p == '\0')
			{
				write(1, "%", 1);
				count++;
				break;
			}
			switch (*p)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent();
					break;
				default:
					write(1, "%", 1);
					write(1, p, 1);
					count += 2;
					break;
			}
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
 * print_char - Prints a character.
 * @args: The va_list containing the character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: The va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}

	return (count);
}

/**
 * print_percent - Prints a percent sign.
 *
 * Return: The number of characters printed (always 1).
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}
