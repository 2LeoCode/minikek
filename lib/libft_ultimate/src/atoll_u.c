#include <libft.h>

unsigned long long	ft_atoll_u(const char *s)
{
	unsigned long long	n;

	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	n = 0ULL;
	while (ft_isdigit(*s))
		n = 10ULL * n + (*s++ - '0');
	return (n);
}
