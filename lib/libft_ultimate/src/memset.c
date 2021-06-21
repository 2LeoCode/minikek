#include <libft.h>

static void	*__ft_memset(unsigned char *b,
				unsigned char c,
				size_t len,
				void *begin)
{
	if (len)
		b[0] = c;
	if (len > 1)
		b[1] = c;
	if (len > 2)
		b[2] = c;
	if (len > 3)
		b[3] = c;
	if (len > 4)
		b[4] = c;
	if (len > 5)
		b[5] = c;
	if (len > 6)
		b[6] = c;
	return (begin);
}

static void	*_ft_memset(unsigned long *qword,
			unsigned long c,
			size_t len,
			void *begin)
{
	unsigned long	repeated_c;

	repeated_c = c | (c << 8);
	repeated_c |= (repeated_c << 16);
	if (sizeof(long) == 8)
		repeated_c |= ((repeated_c << 16) << 16);
	while (len >= sizeof(long))
	{
		*(qword++) = repeated_c;
		len -= sizeof(long);
	}
	return (__ft_memset((unsigned char *)qword, (unsigned char)c, len,
			begin));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*s;
	const unsigned char	dataref = (unsigned char)c;

	s = (unsigned char *)b;
	while (((unsigned long)b % sizeof(long)) && len--)
		*(s++) = dataref;
	return (_ft_memset((unsigned long *)s, (unsigned long)dataref, len, b));
}
