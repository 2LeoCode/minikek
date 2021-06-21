#include <libft.h>

int	ft_strisprint(const char *s)
{
	while (ft_isprint(*s))
		s++;
	return (!*s);
}
