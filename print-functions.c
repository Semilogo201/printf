#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @cprint: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, cprint_t *cprint)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (cprint->minus_flag)
		sum += _putchar(ch);
	while (pad++ < cprint->width)
		sum += _putchar(pad_char);
	if (!cprint->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @cprint: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, cprint_t *cprint)
{
	long l;

	if (cprint->l_modifier)
		l = va_arg(ap, long);
	else if (cprint->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, cprint), cprint));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @cprint: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, cprint_t *cprint)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)cprint;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (cprint->precision < pad)
		j = pad = cprint->precision;

	if (cprint->minus_flag)
	{
		if (cprint->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < cprint->width)
		sum += _putchar(pad_char);
	if (!cprint->minus_flag)
	{
		if (cprint->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @cprint: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, cprint_t *cprint)
{
	(void)ap;
	(void)cprint;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @cprint: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, cprint_t *cprint)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, cprint);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
