#include "ft_printf.h"

static char	*get_0x(void)
{
	char	*res;

	res = (char *)malloc(3);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	res[2] = 0;
	return (res);
}

static char	*get_addr(t_flags data, uintptr_t num, int is_null)
{
	char	*prefix;
	char	*addr;
	size_t	addr_len;

	prefix = get_0x();
	addr = hex_convert(num, 1);
	if (!prefix || !addr)
	{
		free(prefix);
		free(addr);
		return (NULL);
	}
	addr_len = ft_strlen(addr);
	if (data.is_prec)
	{
		if (!data.prec && is_null)
			addr[0] = 0;
		else if (data.prec > addr_len)
			add_zeros(&addr, data.prec - addr_len);
	}
	return (join_str2(prefix, addr));
}

int	print_ptr(t_flags data, void *ptr)
{
	size_t	len;
	char	*addr;

	addr = get_addr(data, (uintptr_t)ptr, ptr == NULL);
	if (!addr)
		return (-1);
	len = ft_strlen(addr);
	if (data.is_width && data.width > len)
	{
		add_space(&addr, data.width - len, data.is_minus);
		len += data.width - len;
	}
	ft_putstr_fd(addr, 1);
	free(addr);
	return (len);
}
