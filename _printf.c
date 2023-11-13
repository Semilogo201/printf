#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	cprint_t  cprint = CPRINT_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_cprint(&cprint, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &cprint)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &cprint, ap);
		p = get_precision(p, &cprint, ap);
		if (get_modifier(p, &cprint))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
				cprint.l_modifier || cprint.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &cprint);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}

