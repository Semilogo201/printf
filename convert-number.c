#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @cprint: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, cprint_t *cprint)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (cprint->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (cprint->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, cprint);
	if (cprint->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	cprint->unsign = 1;
	return (c += print_number(str, cprint));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @cprint: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, cprint_t *cprint)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (cprint->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (cprint->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, cprint);
	if (cprint->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	cprint->unsign = 1;
	return (c += print_number(str, cprint));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @cprint: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, cprint_t *cprint)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, cprint);
	int c = 0;

	if (cprint->hashtag_flag && n)
		*--str = '0';
	cprint->unsign = 1;
	return (c += print_number(str, cprint));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @cprint: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, cprint_t *cprint)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (cprint->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (cprint->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, cprint);

	if (cprint->hashtag_flag && l)
		*--str = '0';
	cprint->unsign = 1;
	return (c += print_number(str, cprint));
}

