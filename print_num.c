#include "ft_printf.h"

static char	*zero_prec_zero_val(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

static int	handler(t_flags data, char *num)
{
	size_t	len;

	len = ft_strlen(num);
	if (data.is_prec && data.prec > len
		&& add_zeros_num(&num, data.prec - len))
	{
		free(num);
		return (-1);
	}
	if (data.is_prec)
		len = max_of(len, data.prec);
	if (data.is_width && data.width > len)
	{
		if ((!data.is_zero && add_space(&num, data.width - len, data.is_minus))
			|| (data.is_zero && add_zeros_num(&num, data.width - len)))
		{
			free(num);
			return (-1);
		}
		else
			len += data.width - len;
	}
	ft_putstr_fd(num, 1);
	free(num);
	return (len);
}

int	print_num(t_flags data, long int n)
{
	char	*num;

	if (data.is_prec && !data.prec && !n)
		num = zero_prec_zero_val();
	else
		num = ft_itoa(n);
	if (!num)
		return (-1);
	if (n < 0)
		data.prec++;
	if (data.is_minus || data.is_prec)
		data.is_zero = 0;
	return (handler(data, num));
}

int	print_hex(t_flags data, unsigned int n)
{
	char			*num;

	if (data.is_prec && !data.prec && !n)
		num = zero_prec_zero_val();
	else
		num = hex_convert(n, data.code == 'x');
	if (!num)
		return (-1);
	if (data.is_minus || data.is_prec)
		data.is_zero = 0;
	return (handler(data, num));
}
