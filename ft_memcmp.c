#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (s1 == s2)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

//man memcmp | col -bx | fold -77 | sed -e "s/^/\/\/ /g" | pbcopy
//
// DESCRIPTION
//      The memcmp() function compares byte string s1 against byte string s2.
//      Both strings are assumed to be n bytes long.
// 
// RETURN VALUES
//      The memcmp() function returns zero if the two strings are identical, oth
//      erwise returns the difference between the first two differing bytes
//
//      (treated as unsigned char values, so that `\200' is greater than `\0',
//      for example).
//			----->	str = (const unsigned char *)s;
//
//       Zero-length strings are always identical.
//			-----> if (s1 == s2) return (0);
//
//       This behavior is not required by C and portable code should only
//      depend on the sign of the returned value.