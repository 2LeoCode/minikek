#include <libft.h>

int	ft_strisdigit(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (!*s);
}
