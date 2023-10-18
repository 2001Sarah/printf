#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed
 * (excluding null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;

va_start(args, format);

if (format == NULL)
return (-1);

while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
count += print_char(args);
else if (format[i] == 's')
count += print_string(args);
else if (format[i] == '%')
count += print_percent();
else
return (-1);
}
else
{
putchar(format[i]);
count++;
}
i++;
}

va_end(args);

return (count);
}
