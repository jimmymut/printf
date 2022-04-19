#include"main.h"
/**
*_printf - a function that produces output according to a format.
*@format: is a character string and is composed of zero or more directives
*
*Return: the format on sucess
*/
int _printf(const char *format, ...)
{
	va_list var;
	int i = 0, j = 0;
	char *str;

	str = malloc(sizeof(char) * 1050);
	if (str == NULL)
	return (1);
	va_start(var, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			i++;
			str[j] = (char)va_arg(var, int);
			j++;
		}
		else
		{
			str[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, str, i++);
	va_end(var);
	free(str);
	return (i);
}
