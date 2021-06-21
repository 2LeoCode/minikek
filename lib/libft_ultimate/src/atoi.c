#include <libft.h>

int	ft_atoi(const char *s)
{
	const long long	n = ft_atoll(s);

	if ((n >= LONG_MAX) || (n < LONG_MIN))
		return (-1);
	if ((n > INT_MAX) || (n < INT_MIN))
		return (0);
	return ((int)n);
}
