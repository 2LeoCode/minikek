#include <libft.h>

static int	_ft_memcmp(const unsigned char *s1, const unsigned char *s2)
{
	if (s1[0] != s2[0])
		return (s1[0] - s2[0]);
	if (s1[1] != s2[1])
		return (s1[1] - s2[1]);
	if (s1[2] != s2[2])
		return (s1[2] - s2[2]);
	if (s1[3] != s2[3])
		return (s1[3] - s2[3]);
	if (s1[4] != s2[4])
		return (s1[4] - s2[4]);
	if (s1[5] != s2[5])
		return (s1[5] - s2[5]);
	if (s1[6] != s2[6])
		return (s1[6] - s2[6]);
	if (s1[7] != s2[7])
		return (s1[7] - s2[7]);
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned long	*qword_s1 = (unsigned long *)s1;
	const unsigned long	*qword_s2 = (unsigned long *)s2;
	unsigned char		*byte_s1;
	unsigned char		*byte_s2;

	while (n >= sizeof(long))
	{
		if (*qword_s1 != *qword_s2)
			return (_ft_memcmp((unsigned char *)qword_s1,
					(unsigned char *)qword_s2));
		qword_s1++;
		qword_s2++;
		n -= sizeof(long);
	}
	byte_s1 = ((unsigned char *)qword_s1) - 1;
	byte_s2 = ((unsigned char *)qword_s2) - 1;
	while (n--)
		if (*(++byte_s1) != *(++byte_s2))
			return (*byte_s1 - *byte_s2);
	return (0);
}
