#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char			*s;
	const size_t	len = ft_strlen(s1);

	if (len < n)
		n = len;
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	s[n] = '\0';
	return ((char *)ft_memcpy(s, s1, n));
}
