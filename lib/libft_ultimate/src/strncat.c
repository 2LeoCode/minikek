#include <libft.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	const char		*begin = dst;
	const size_t	cp_len = ft_strnlen(src, n);

	dst += ft_strlen(dst);
	ft_memcpy(dst, src, cp_len);
	dst[cp_len] = '\0';
	return ((char *)begin);
}
