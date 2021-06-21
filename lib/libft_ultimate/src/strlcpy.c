#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	const size_t	dstlen = ft_strnlen(src, dstsize);

	if (!dstsize)
		return (srclen);
	ft_stpncpy(dst, src, dstlen);
	dst[dstlen - (dstlen == dstsize)] = '\0';
	return (srclen);
}
