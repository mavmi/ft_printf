#include "ft_printf.h"

static char	*get_null_str(void)
{
	char	*str;

	str = (char *)malloc(7);
	if (!str)
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = 0;
	return (str);
}

int	print_str(t_flags data, char *str)
{
	size_t	len;
	char	*s;

	if (str)
		s = ft_strdup(str);
	else
		s = get_null_str();
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (data.is_prec && data.prec < len)
	{
		s = str_sub(s, 0, data.prec);
		len = data.prec;
	}
	if (data.is_width && data.width > len)
	{
		if ((data.is_zero && add_zeros(&s, data.width - len)) || (!data.is_zero
				&& add_space(&s, data.width - len, data.is_minus)))
			return (-1);
		len += data.width - len;
	}
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
