#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long	*qword;
	unsigned char	*byte;

	qword = (unsigned long *)s;
	while (n >= sizeof(long))
	{
		*(qword++) = 0L;
		n -= sizeof(long);
	}
	byte = (unsigned char *)qword;
	while (n--)
		*(byte++) = '\0';
}
