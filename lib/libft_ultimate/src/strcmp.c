#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1_u = (unsigned char *)s1;
	const unsigned char	*s2_u = (unsigned char *)s2;

	while ((*s1_u || *s2_u) && (*s1_u == *s2_u))
	{
		s1_u++;
		s2_u++;
	}
	return (*s1_u - *s2_u);
}
