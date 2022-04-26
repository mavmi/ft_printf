#include "ft_printf.h"

static int	is_code(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd'
		&& c != 'i' && c != 'u' && c != 'x' && c != 'X'
		&& c != '%')
		return (0);
	return (1);
}

static int	print_code_str(const char *s, size_t *i, va_list args)
{
	t_flags	data;
	char	*sub_str;
	int		begin;
	int		val;

	begin = (*i)++;
	while (!is_code(s[*i]))
		(*i)++;
	sub_str = ft_substr(s, begin, (*i) - begin + 1);
	if (!sub_str)
		return (-1);
	data = get_struct(sub_str, args);
	val = printer(data, args);
	free(sub_str);
	(*i)++;
	return (val);
}

static int	print_def_str(const char *s, size_t *i)
{
	int		begin;
	int		res;
	char	*sub_str;

	begin = *i;
	res = 0;
	while (s[*i] != '%' && s[*i])
		(*i)++;
	sub_str = ft_substr(s, begin, (*i) - begin);
	if (!sub_str)
		return (-1);
	ft_putstr_fd(sub_str, 1);
	res += ft_strlen(sub_str);
	free(sub_str);
	return (res);
}

int	string_handler(const char *s, va_list args)
{
	size_t	i;
	int		res;
	int		val;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
			val = print_code_str(s, &i, args);
		else
			val = print_def_str(s, &i);
		if (val < 0)
			return (-1);
		res += val;
	}
	return (res);
}
