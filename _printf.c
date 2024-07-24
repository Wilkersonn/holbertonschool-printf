#include <stdio.h>
#include <stdarg.h>

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
    char c;
    char *s;

    va_start(args, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'c')
            {
                c = (char)va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*p == 's')
            {
                s = va_arg(args, char *);
                while (*s)
                {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*p == '%')
            {
                putchar('%');
                count++;
            }
            else
            {
                putchar('%');
                putchar(*p);
                count += 2;
            }
        }
        else
        {
            putchar(*p);
            count++;
        }
    }

    va_end(args);
    return (count);
}