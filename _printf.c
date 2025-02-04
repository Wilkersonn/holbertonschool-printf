#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_int(va_list args);

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
			if (*p == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (*p == 'c')
				count += print_char(args);
			else if (*p == 's')
				count += print_string(args);
			else if (*p == 'd' || *p == 'i')
				count += print_int(args);
			else if (*p == '%')
				count += print_percent();
			else
			{
				write(1, "%", 1);
				write(1, p, 1);
				count += 2;
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

/**
 * print_int - Prints an integer.
 * @args: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
	long int n = va_arg(args, int);
	int count = 0;
	char buffer[12];
	int i = 0;
	int is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	if (is_negative)
		buffer[i++] = '-';

	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
