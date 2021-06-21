#include <libft.h>

long	ft_atol(const char *s)
{
	const long long	n = ft_atoll(s);

	if ((n >= LLONG_MAX) || (n < LLONG_MIN))
		return (-1L);
	if ((n > LONG_MAX) || (n < LONG_MIN))
		return (0L);
	return ((long)n);
}
