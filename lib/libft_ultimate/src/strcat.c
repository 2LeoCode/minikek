#include <libft.h>

char	*ft_strcat(char *dst, const char *src)
{
	ft_stpcpy(dst + ft_strlen(dst), src);
	return (dst);
}
