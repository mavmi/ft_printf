#include "ft_printf.h"

int	printer(t_flags data, va_list args)
{
	if (data.code == 'c')
		return (print_char(data, (char)va_arg(args, int)));
	else if (data.code == 's')
		return (print_str(data, (char *)va_arg(args, char *)));
	else if (data.code == 'p')
		return (print_ptr(data, va_arg(args, void *)));
	else if (data.code == 'd')
		return (print_num(data, va_arg(args, int)));
	else if (data.code == 'i')
		return (print_num(data, va_arg(args, int)));
	else if (data.code == 'u')
		return (print_num(data, va_arg(args, unsigned int)));
	else if (data.code == 'x' || data.code == 'X')
		return (print_hex(data, va_arg(args, unsigned int)));
	else if (data.code == '%')
		return (print_char(data, '%'));
	return (0);
}
