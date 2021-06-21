#include <libft.h>

size_t	ft_strlen(const char *s)
{
	const char	*begin = s;

	while (*s)
		s++;
	return (s - begin);
}

/*
**static size_t	__ft_strlen(const unsigned char *s, const char *begin)
**{
**	const size_t	len_already = (size_t)s - (size_t)begin;
**
**	if (!s[0])
**		return (len_already);
**	if (!s[1])
**		return (len_already + 1LL);
**	if (!s[2])
**		return (len_already + 2LL);
**	if (!s[3])
**		return (len_already + 3LL);
**	if (!s[4])
**		return (len_already + 4LL);
**	if (!s[5])
**		return (len_already + 5LL);
**	if (!s[6])
**		return (len_already + 6LL);
**	if (!s[7])
**		return (len_already + 7LL);
**	return (0);
**}
**
**static size_t	_ft_strlen(const unsigned long *long_ptr, const char *begin)
**{
**	if (HIMAGIC == -1)
**		return (ft_strlen_basic((char *)long_ptr, begin));
**	while (1)
**	{
**		if ((*long_ptr - LOMAGIC) & ~(*long_ptr) & HIMAGIC)
**			break ;
**		long_ptr++;
**	}
**	return (__ft_strlen((unsigned char *)long_ptr, begin));
**}
**
**size_t	ft_strlen(const char *s)
**{
**	const char	*char_ptr = s;
**
**	while (*char_ptr && ((size_t)char_ptr % sizeof(long)))
**		char_ptr++;
**	return (_ft_strlen((unsigned long *)char_ptr, s));
**}
*/