#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);

/* Function prototypes for helper functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_int(va_list args);

#endif /* MAIN_H */
