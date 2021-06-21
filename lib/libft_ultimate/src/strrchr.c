#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*found;
	unsigned char	*tmp;

	c = (unsigned char)c;
	if (!c)
		return ((char *)s + ft_strlen(s));
	found = NULL;
	tmp = (unsigned char *)ft_strchr((char *)s, c);
	while (tmp)
	{
		found = tmp;
		tmp = (unsigned char *)ft_strchr((char *)tmp + 1, c);
	}
	return ((char *)found);
}
