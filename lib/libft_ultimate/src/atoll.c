#include <libft.h>

long long	ft_atoll(const char *s)
{
	long long	n;
	long long	sign;

	while (ft_isspace(*s))
		s++;
	sign = 1LL;
	if ((*s == '+') || (*s == '-'))
		sign -= 2LL * (*(s++) == '-');
	n = 0LL;
	while (ft_isdigit(*s))
		n = 10LL * n + (*(s++) - '0');
	return (n * sign);
}
