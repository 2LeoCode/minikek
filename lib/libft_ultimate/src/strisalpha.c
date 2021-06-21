#include <libft.h>

int	ft_strisalpha(const char *s)
{
	while (ft_isalpha(*s))
		s++;
	return (!*s);
}
