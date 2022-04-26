#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		val;
	va_list	args;

	if (!str)
		return (1);
	va_start(args, str);
	val = string_handler(str, args);
	va_end(args);
	return (val);
}
