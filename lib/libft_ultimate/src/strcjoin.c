#include <libft.h>

char	*ft_strcjoin(const char *s1, const char *s2, int c)
{
	char			*s;
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	const size_t	len_tot = len1 + len2 + 1;

	s = (char *)malloc(sizeof(char) * (len_tot + 1));
	if (!s)
		return (NULL);
	s[len_tot] = '\0';
	s[len1] = c;
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1 + 1, s2, len2);
	return (s);
}
