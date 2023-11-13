#include "main.h"

/**
 * _printf - mimics printf function
 * @format: identifier looks
 * Return: an integer
 */

int _printf(const char *format, ...)
{
	match m[] = {
	
	{"%c", printf_char}, {"%s", printf_string}, {"%%", 
	}

}
