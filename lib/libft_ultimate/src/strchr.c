#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != c))
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/*
**char	*___ft_strchr(const unsigned char *char_ptr, unsigned char c)
**{
**	if (char_ptr[4] == c)
**		return ((char *)char_ptr + 4);
**	if (!char_ptr[5])
**		return (NULL);
**	if (char_ptr[5] == c)
**		return ((char *)char_ptr + 5);
**	if (!char_ptr[5])
**		return (NULL);
**	if (char_ptr[6] == c)
**		return ((char *)char_ptr + 6);
**	if (!char_ptr[6])
**		return (NULL);
**	if (char_ptr[7] == c)
**		return ((char *)char_ptr + 7);
**	return (NULL);
**}
**
**char	*__ft_strchr(const unsigned char *char_ptr, unsigned char c)
**{
**	if (char_ptr[0] == c)
**		return ((char *)char_ptr);
**	if (!char_ptr[0])
**		return (NULL);
**	if (char_ptr[1] == c)
**		return ((char *)char_ptr + 1);
**	if (!char_ptr[1])
**		return (NULL);
**	if (char_ptr[2] == c)
**		return ((char *)char_ptr + 2);
**	if (!char_ptr[2])
**		return (NULL);
**	if (char_ptr[3] == c)
**		return ((char *)char_ptr + 3);
**	if (!char_ptr[3])
**		return (NULL);
**	return (___ft_strchr(char_ptr, c));
**}
**
**char	*_ft_strchr(const unsigned long *long_ptr, unsigned long c)
**{
**	unsigned long	repeated_c;
**	unsigned long	long_word;
**
**	if (HIMAGIC == -1)
**		return (ft_strchr_basic((unsigned char *)long_ptr, (unsigned char)c));
**	repeated_c = c | (c << 8);
**	repeated_c |= (repeated_c << 16);
**	if (sizeof(long) == 8)
**		repeated_c |= ((repeated_c << 16) << 16);
**	while (1)
**	{
**		long_word = *long_ptr ^ repeated_c;
**		if ((long_word - LOMAGIC) & ~long_word & HIMAGIC)
**			break ;
**		if ((*long_ptr - LOMAGIC) & ~(*long_ptr) & HIMAGIC)
**			return (NULL);
**		long_ptr++;
**	}
**	return (__ft_strchr((unsigned char *)long_ptr, (unsigned char)c));
**}
**
**char	*ft_strchr(const char *s, int c)
**{
**	const unsigned char	*char_ptr = (unsigned char*)s;
**	const unsigned char	dataref = (unsigned char)c;
**
**	if (!c)
**		return ((char *)s + ft_strlen(s));
**	while (((size_t)char_ptr % sizeof(long)) && *char_ptr
**		&& (*char_ptr != dataref))
**		char_ptr++;
**	return (_ft_strchr((unsigned long *)char_ptr, (unsigned long)dataref));
**}
*/