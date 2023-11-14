#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @param: the parameters structure
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, param_t *param, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	param->precision = d;
	return (p);
}
