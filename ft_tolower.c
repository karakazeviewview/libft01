
#include "libft.h"

int	ft_tolower(int c)
{
	return (c - ('A' <= c && c <= 'Z') * ('A' - 'a'));
}
