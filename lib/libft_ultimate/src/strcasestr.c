#include <libft.h>

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	const unsigned char	*h_u = (unsigned char *)haystack;
	const unsigned char	*n_u = (unsigned char *)needle;
	const size_t		needle_len = ft_strlen(needle);

	while (*h_u)
	{
		if (((*h_u == *n_u) || (((*h_u < *n_u) && (*h_u == ft_toupper(*n_u)))
					|| ((*h_u > *n_u) && (*h_u == ft_tolower(*n_u)))))
			&& !ft_strncasecmp((char *)h_u, (char *)n_u, needle_len))
			return ((char *)h_u);
		h_u++;
	}
	return (NULL);
}
