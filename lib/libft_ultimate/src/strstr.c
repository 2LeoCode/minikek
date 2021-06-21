#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const unsigned char	*end_ptr = (unsigned char *)haystack
		+ ft_strlen(haystack);
	unsigned char		*tmp;
	const size_t		n_len = ft_strlen(needle);

	if (!*needle)
		return ((char *)haystack);
	tmp = (unsigned char *)ft_strchr(haystack, *needle);
	while (tmp)
	{
		if (((size_t)end_ptr - (size_t)tmp) < n_len)
			break ;
		if (!ft_memcmp(tmp, needle, n_len))
			return ((char *)tmp);
		tmp = (unsigned char *)ft_strchr((char *)tmp + 1, *needle);
	}
	return (NULL);
}
