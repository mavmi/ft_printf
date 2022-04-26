#include "libft.h"

void	print_null_str(int fd)
{
	write(fd, "(null)\n", 7);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
		write(fd, s, ft_strlen(s));
	else
		print_null_str(fd);
}
