#include "ft_printf.h"

static void	print(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		ft_putchar_fd(str[i++], 1);
}

int	print_char(t_flags data, char c)
{
	char	*str;

	if (data.is_width && data.width > 0)
	{
		str = (char *)malloc(data.width);
		if (!str)
			return (-1);
		if (data.is_zero)
			ft_memset(str, '0', data.width);
		else
			ft_memset(str, ' ', data.width);
		if (data.is_minus)
			*str = c;
		else
			str[data.width - 1] = c;
		print(str, data.width);
		free(str);
		return (data.width);
	}
	ft_putchar_fd(c, 1);
	return (1);
}
