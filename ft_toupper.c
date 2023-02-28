#include "libft.h"

int	ft_toupper(int c)
{
	return (c + ('a' <= c && c <= 'z') * ('A' - 'a'));
}
