#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @cprint: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, cprint_t *cprint)
{
	unsigned int i = _strlen(str);
	int neg = (!cprint->unsign && *str == '-');

	if (!cprint->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (cprint->precision != UINT_MAX)
		while (i++ < cprint->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!cprint->minus_flag)
		return (print_number_right_shift(str, cprint));
	else
		return (print_number_left_shift(str, cprint));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @cprint: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, cprint_t *cprint)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (cprint->zero_flag && !cprint->minus_flag)
		pad_char = '0';
	neg = neg2 = (!cprint->unsign && *str == '-');
	if (neg && i < cprint->width && pad_char == '0' && !cprint->minus_flag)
		str++;
	else
		neg = 0;
	if ((cprint->plus_flag && !neg2) ||
		(!cprint->plus_flag && cprint->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (cprint->plus_flag && !neg2 && pad_char == '0' && !cprint->unsign)
		n += _putchar('+');
	else if (!cprint->plus_flag && cprint->space_flag && !neg2 &&
		!cprint->unsign && cprint->zero_flag)
		n += _putchar(' ');
	while (i++ < cprint->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (cprint->plus_flag && !neg2 && pad_char == ' ' && !cprint->unsign)
		n += _putchar('+');
	else if (!cprint->plus_flag && cprint->space_flag && !neg2 &&
		!cprint->unsign && !cprint->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @cprint: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, cprint_t *cprint)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (cprint->zero_flag && !cprint->minus_flag)
		pad_char = '0';
	neg = neg2 = (!cprint->unsign && *str == '-');
	if (neg && i < cprint->width && pad_char == '0' && !cprint->minus_flag)
		str++;
	else
		neg = 0;

	if (cprint->plus_flag && !neg2 && !cprint->unsign)
		n += _putchar('+'), i++;
	else if (cprint->space_flag && !neg2 && !cprint->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < cprint->width)
		n += _putchar(pad_char);
	return (n);
}
