#include <libft.h>

int	ft_strislower(const char *s)
{
	while (ft_islower(*s))
		s++;
	return (!*s);
}
