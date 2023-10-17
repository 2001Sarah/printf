#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: character string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
count += puts(str);
break;
case '%':
count += putchar('%');
break;
default:
count += putchar('%');
count += putchar(format[i]);
}
}
else
count += putchar(format[i]);
i++;
}
va_end(args);
return (count);
}
