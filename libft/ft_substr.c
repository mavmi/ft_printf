#include "libft.h"

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
	{
		return (NULL);
	}
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		counter;
	size_t		sub_str_size;
	char		*result;

	if (!s)
		return (NULL);
	counter = 0;
	if (start >= ft_strlen(s) || !len)
		return (get_empty_str());
	sub_str_size = ft_strlen(s) - start;
	if (sub_str_size >= len)
		sub_str_size = len;
	sub_str_size++;
	result = (char *)malloc(sub_str_size);
	if (!result)
		return (NULL);
	s += start;
	while (*s && len--)
		result[counter++] = *s++;
	result[counter] = '\0';
	return (result);
}
