#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char			*tmp;
	const char		*end_ptr = haystack + ft_strlen(haystack);
	const size_t	needle_len = ft_strlen(needle);

	if (!*needle)
		return ((char *)haystack);
	tmp = ft_strchr(haystack, *needle);
	n -= ((size_t)tmp - (size_t)haystack);
	haystack = tmp;
	while (haystack && (n >= needle_len))
	{
		if (((size_t)end_ptr - (size_t)haystack) < needle_len)
			break ;
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		tmp = ft_strchr(haystack + 1, *needle);
		n -= ((size_t)tmp - (size_t)haystack);
		haystack = tmp;
	}
	return (NULL);
}
