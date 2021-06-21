#include <libft.h>

char	*ft_rplchr(char *s, int before, int after)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = ft_strchr(s, before);
	if (!ptr)
		return (NULL);
	*ptr = after;
	return (ptr);
}
