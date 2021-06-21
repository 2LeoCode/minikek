#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	dstlen = ft_strnlen(dst, dstsize);
	const size_t	srclen = ft_strlen(src);

	if (dstlen == dstsize)
		return (srclen + dstsize);
	if (srclen < (dstsize - dstlen))
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
