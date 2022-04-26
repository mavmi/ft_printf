#include "libft.h"

int	ft_isdigit(int value)
{
	if (value >= 48 && value <= 57)
	{
		return (1);
	}
	return (0);
}
