#include "ft_printf.h"

static t_flags	get_emtpy_str(void)
{
	t_flags	data;

	data.code = 0;
	data.is_minus = 0;
	data.is_zero = 0;
	data.prec = 0;
	data.is_prec = 0;
	data.width = 0;
	data.is_width = 0;
	return (data);
}

static int	get_precision(char *s, t_flags *data, va_list args)
{
	int	len;
	int	val;

	if (*(s + 1) == '*')
	{
		val = va_arg(args, int);
		len = 1;
	}
	else
	{
		val = ft_atoi(s + 1);
		len = get_num_str_len(s + 1);
	}
	if (val < 0)
	{
		data->prec = 0;
		data->is_prec = 0;
	}
	else
	{
		data->prec = val;
		data->is_prec = 1;
	}
	return (len);
}

static int	get_width(char *s, t_flags *data, va_list args)
{
	int	len;
	int	val;

	if (*s == '*')
	{
		val = va_arg(args, int);
		len = 0;
	}
	else
	{
		val = ft_atoi(s);
		len = get_num_str_len(s) - 1;
	}
	if (val < 0)
	{
		data->width = -val;
		data->is_minus = 1;
	}
	else
		data->width = val;
	data->is_width = 1;
	return (len);
}

t_flags	get_struct(char *s, va_list args)
{
	size_t	i;
	t_flags	data;

	i = 1;
	data = get_emtpy_str();
	while (i < ft_strlen(s))
	{
		if (s[i] == '-')
			data.is_minus = 1;
		else if (s[i] == '0')
			data.is_zero = 1;
		else if (s[i] == '.')
			i += get_precision(s + i, &data, args);
		else if (s[i] == '*' || ft_isdigit(s[i]))
			i += get_width(s + i, &data, args);
		i++;
	}
	data.code = s[i - 1];
	if (data.is_minus)
		data.is_zero = 0;
	return (data);
}
