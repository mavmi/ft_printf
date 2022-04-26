#include "libft.h"

int	ft_numlen(long int n)
{
	unsigned int	num;
	int				counter;
	int				is_minus;

	is_minus = 0;
	if (n < 0)
	{
		num = -n;
		is_minus = 1;
	}
	else
		num = n;
	counter = 1;
	while (num > 9)
	{
		num /= 10;
		counter++;
	}
	return (counter + is_minus);
}
