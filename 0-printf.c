#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - an implementation of printf
 * @format: format string
 *
 * Return: (int) number of bytes that were printed by the function
 */
int _printf(const char *format, ...)
{
	int i, byte_count;
	va_list character;

	byte_count = 0;
	
	va_start(character, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
			byte_count += _putchar(format[i]);

		else
		{
			do {
				i++;
			} while (format[i] == ' ');

			if (format[i] == 'c')
				byte_count += print_char(&character);

			else if (format[i] == 's')
				byte_count += print_string(&character);

			else if (format[i] == 'd' || format[i] == 'i')
				byte_count += print_int(&character);

			else if (format[i] == '%')
				byte_count += _putchar('%');

			else if (format[i] == 0)
				return (-1);

			else
			{
				_putchar('%');
				_putchar(format[i]);
				byte_count += 2;
			}
		}
	}

	va_end(character);

	return (byte_count);
}
