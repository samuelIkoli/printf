#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct directive - new type defining directive struct
 * @identifier - char e.g. 'c' or 's' specifying format directive
 * @printer - func pointer to handle directive appropriately
 */
typedef struct directive {
    char identifier;
    int (*printer)();
} Directive;


/**
 * _putchar - prints a char to stdout
 * @c: char to be printed
 *
 * Return: 1 for success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _print_int - recursive helper for print_int
 * @n: integer to be printed 
 * @bytecount: tracks number of bytes printed
 * 
 * Return: number of bytes printed
 */
int _print_int(int n, int bytecount)
{
    if (n < 10)
    {
        _putchar('0' + n);
        return bytecount + 1;
    }
    
    bytecount = _print_int(n / 10, bytecount + 1);
    _putchar(n % 10 + '0');

    return (bytecount);
}
/**
 * print_char - prints a char to stdout from next arg
 * @args: yields next arg
 * 
 * Return: 1 for success
 */
int print_char(va_list *args)
{
    char c;

    c = va_arg(*args, int);

    return (_putchar(c));
}

/**
 * print_string - prints a string to stdout
 * @str: yields next argument(string) to be printed
 *
 * Return: int count of number of bytes printed
 */
int print_string(va_list *args)
{
    int i, count;
    char *str;
    
    str = va_arg(*args, char *);

    count = 0;

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i]; i++)
        count += _putchar(str[i]);

    return (count);
}

/**
 * print_int - prints integer to stdout from args
 * @args: yields next arg (int)
 * 
 * Return: number of bytes that were printed by the function
 */
int print_int(va_list *args)
{
    int n, count = 0;

    n = va_arg(*args, int);

    if (n < 0)
    {
        _putchar('-');
        count++;
        n *= -1;
    }

    count += _print_int(n, 0);

    return (count);
}
