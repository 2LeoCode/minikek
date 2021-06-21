#include <libft.h>

int	ft_strisascii(const char *s)
{
	while (ft_isascii(*s))
		s++;
	return (!*s);
}
