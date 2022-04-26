#include "ft_printf.h"

static char	get_char(int pos, int lower)
{
	if (lower)
		return ("0123456789abcdef"[pos]);
	return ("0123456789ABCDEF"[pos]);
}

char	*hex_convert(uintptr_t num, int lower)
{
	int		i;
	int		arr[16];
	int		counter;
	char	*res;

	counter = 0;
	while (num >= 16)
	{
		arr[counter++] = num % 16;
		num /= 16;
	}
	arr[counter] = num;
	res = (char *)malloc(counter + 2);
	if (res)
	{
		i = 0;
		while (counter >= 0)
			res[i++] = get_char(arr[counter--], lower);
		res[i] = '\0';
	}
	return (res);
}

size_t	max_of(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*join_str2(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*str_sub(char *s1, unsigned int start, size_t len)
{
	char	*substr;

	substr = ft_substr(s1, start, len);
	free(s1);
	return (substr);
}
