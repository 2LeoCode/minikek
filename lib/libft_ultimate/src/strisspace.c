#include <libft.h>

int	ft_strisspace(const char *s)
{
	while (ft_isspace(*s))
		s++;
	return (!*s);
}
