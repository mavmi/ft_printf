#include "ft_printf.h"

int	add_zeros(char **str, int zeros_count)
{
	char	*zeros_str;

	if (!*str)
		return (1);
	zeros_str = (char *)malloc(zeros_count + 1);
	if (!zeros_str)
		return (2);
	ft_memset(zeros_str, '0', zeros_count);
	zeros_str[zeros_count] = 0;
	*str = join_str2(zeros_str, *str);
	if (!*str)
		return (3);
	return (0);
}

int	add_zeros_num(char **num, int zeros_count)
{
	int	is_neg;

	if (!*num)
		return (1);
	is_neg = 0;
	if (**num == '-')
		is_neg = 1;
	if (add_zeros(num, zeros_count))
		return (2);
	if (is_neg)
	{
		*ft_strchr(*num, '-') = '0';
		**num = '-';
	}
	return (0);
}

int	add_space(char **str, size_t len, int is_minus)
{
	char	*spaces;

	spaces = (char *)malloc(len + 1);
	if (!spaces)
		return (1);
	ft_memset(spaces, ' ', len);
	spaces[len] = 0;
	if (is_minus)
		*str = join_str2(*str, spaces);
	else
		*str = join_str2(spaces, *str);
	if (!*str)
		return (2);
	return (0);
}

int	get_num_str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	return (i);
}
