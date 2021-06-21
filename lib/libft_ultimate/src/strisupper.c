#include <libft.h>

int	ft_strisupper(const char *s)
{
	while (ft_isupper(*s))
		s++;
	return (!*s);
}
