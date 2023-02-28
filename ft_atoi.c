#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int			s;
	long long	result;
	size_t		i;

	result = 0;
	s = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	s -= (str[i] == '-') * 2;
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == (LONG_MAX / 10)
				&& ((str[i] - '0') > (LONG_MAX % 10))))
			return ((s == 1) * ((int)LONG_MAX) + (s == -1) *((int)LONG_MIN));
		result = result * 10 + (str[i++] - '0');
	}
	return (result * s);
}

//#include<stdio.h>
//int	main(int argc, char **argv)
//{
//	if (argc == 2)
//		printf("%d\n", ft_atoi(argv[1]));
//	return (0);
//}
//
//DESCRIPTION
//     The atoi() function converts the initial portion of the string pointed
//	  to by str to int representation.
//
//     It is equivalent to:
//
//           (int)strtol(str, (char **)NULL, 10);
//
//     While the atoi() function uses the current locale, the atoi_l() function
//     may be passed a locale directly. See xlocale(3) for more information.
//
//IMPLEMENTATION NOTES
//     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
//
//     The strtol() and strtol_l() functions are recommended instead of atoi()
//     and atoi_l() functions, especially in new code.
//
//ERRORS
//     The function atoi() need not affect the value of errno on an error.
//
//
//STRTOL(3)                BSD Library Functions Manual                STRTOL(3
//)
//
//NAME
//     strtoimax, strtol, strtoll, strtoq -- convert a string value to a long,
//     long long, intmax_t or quad_t integer`
//
//LIBRARY
//     Standard C Library (libc, -lc)
//
//SYNOPSIS
//     #include <inttypes.h>
//
//     intmax_t
//     strtoimax(const char *restrict str, char **restrict endptr, int base);
//
//     #include <stdlib.h>
//
//     long
//     strtol(const char *restrict str, char **restrict endptr, int base);
//
//     long long
//     strtoll(const char *restrict str, char **restrict endptr, int base);
//
//     #include <sys/types.h>
//     #include <stdlib.h>
//     #include <limits.h>
//
//     quad_t
//     strtoq(const char *str, char **endptr, int base);
//
//DESCRIPTION
//     The strtol() function converts the string in str to a long value.  The
//     strtoll() function converts the string in str to a long long value.  The
//     strtoimax() function converts the string in str to an intmax_t value.
//     The strtoq() function converts the string in str to a quad_t value.  The
//     conversion is done according to the given base, which must be between 2
//     and 36 inclusive, or be the special value 0.
//
//     The string may begin with an arbitrary amount of white space (as deter-
//     mined by isspace(3)) followed by a single optional `+' or `-' sign.  If
//     base is zero or 16, the string may then include a ``0x'' prefix, and the
//     number will be read in base 16; otherwise, a zero base is taken as 10
//     (decimal) unless the next character is `0', in which case it is taken as
//     8 (octal).
//
//     The remainder of the string is converted to a long, long long, intmax_t
//     or quad_t value in the obvious manner, stopping at the first character
//     which is not a valid digit in the given base.  (In bases above 10, the
//     letter `A' in either upper or lower case represents 10, `B' represents
//     11, and so forth, with `Z' representing 35.)
//
//     If endptr is not NULL, strtol() stores the address of the first invalid
//     character in *endptr.  If there were no digits at all, however, strtol()
//     stores the original value of str in *endptr.  (Thus, if *str is not `\0'
//     but **endptr is `\0' on return, the entire string was valid.)
//
//     Extended locale versions of these functions are documented in
//     strtol_l(3).  See xlocale(3) for more information.
//
//RETURN VALUES
//     The strtol(), strtoll(), strtoimax(), and strtoq() functions return the
//     result of the conversion, unless the value would underflow or overflow.
//     If no conversion could be performed, 0 is returned and the global vari-
//     able errno is set to EINVAL (the last feature is not portable across all
//     platforms).  If an overflow or underflow occurs, errno is set to ERANGE
//     and the function return value is clamped according to the following ta-
//     ble.
//
//           Function       underflow     overflow
//           strtol()       LONG_MIN      LONG_MAX
//           strtoll()      LLONG_MIN     LLONG_MAX
//           strtoimax()    INTMAX_MIN    INTMAX_MAX
//           strtoq()       LLONG_MIN     LLONG_MAX
