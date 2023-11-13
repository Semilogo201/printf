#include "main.h"

/**
 * init cprint - clears struct fields and reset buf
 * @cprint: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_cprint(cprint_t *cprint, va_list ap)
{
cprint->unsign = 0;
cprint->plus_flag = 0;
cprint->space_flag = 0;
cprint->hashtag_flag = 0;
cprint->zero_flag = 0;
cprint->minus_flag = 0;
cprint->width = 0;
cprint->precision = UINT_MAX;
cprint->h_modifier = 0;
cprint->l_modifier = 0;
(void)ap;
}

