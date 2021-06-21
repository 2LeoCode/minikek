#include <libft.h>

int	ft_strisalnum(const char *s)
{
	while (ft_isalnum(*s))
		s++;
	return (!*s);
}
