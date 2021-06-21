#include <libft.h>

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (n--)
		if (*(s++) == c)
			return ((void *)s - 1);
	return (NULL);
}

/*
**static void	*__ft_memchr(const unsigned char *char_ptr,
**				unsigned char c, size_t n)
**{
**	if (n && char_ptr[0] == c)
**		return ((void *)char_ptr);
**	if ((n > 1) && char_ptr[1] == c)
**		return ((void *)char_ptr + 1);
**	if ((n > 2) && char_ptr[2] == c)
**		return ((void *)char_ptr + 2);
**	if ((n > 3) && char_ptr[3] == c)
**		return ((void *)char_ptr + 3);
**	if ((n > 4) && char_ptr[4] == c)
**		return ((void *)char_ptr + 4);
**	if ((n > 5) && char_ptr[5] == c)
**		return ((void *)char_ptr + 5);
**	if ((n > 6) && char_ptr[6] == c)
**		return ((void *)char_ptr + 6);
**	if ((n > 7) && char_ptr[7] == c)
**		return ((void *)char_ptr + 7);
**	return (NULL);
**}
**
**static void	*_ft_memchr(const unsigned long *long_ptr,
**				unsigned long c,
**				size_t n)
**{
**	unsigned long		long_word;
**	unsigned long		repeated_c;
**
**	repeated_c = c | (c << 8);
**	repeated_c |= (repeated_c << 16);
**	if (sizeof(long) == 8)
**		repeated_c |= ((repeated_c << 16) << 16);
**	if (HIMAGIC == -1)
**		return (ft_memchr_basic((unsigned char *)long_ptr, (unsigned char)c,
**				n));
**	while (n >= sizeof(long))
**	{
**		long_word = *long_ptr ^ repeated_c;
**		if (((long_word - LOMAGIC) & ~long_word) & HIMAGIC)
**			break ;
**		long_ptr++;
**		n -= sizeof(long);
**	}
**	return (__ft_memchr((unsigned char *)long_ptr, (unsigned char)c, n));
**}
**
**void	*ft_memchr(const void *s, int c, size_t n)
**{
**	const unsigned char	*char_ptr = (unsigned char *)s;
**	const unsigned char	dataref = (unsigned char)c;
**
**	if (n < sizeof(long))
**		return (__ft_memchr(char_ptr, dataref, n));
**	return (_ft_memchr((unsigned long *)char_ptr, dataref, n));
**}
*/