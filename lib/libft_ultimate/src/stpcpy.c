#include <libft.h>

char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
	return (dst);
}

/*
**static char	*_ft_stpcpy(char *dst, const char *src)
**{
**	dst[0] = src[0];
**	if (!dst[0])
**		return (dst);
**	dst[1] = src[1];
**	if (!dst[1])
**		return (dst + 1);
**	dst[2] = src[2];
**	if (!dst[2])
**		return (dst + 2);
**	dst[3] = src[3];
**	if (!dst[3])
**		return (dst + 3);
**	dst[4] = src[4];
**	if (!dst[4])
**		return (dst + 4);
**	dst[5] = src[5];
**	if (!dst[5])
**		return (dst + 5);
**	dst[6] = src[6];
**	if (!dst[6])
**		return (dst + 6);
**	dst[7] = src[7];
**	if (!dst[7])
**		return (dst + 7);
**	return (NULL);
**}
**
**char	*ft_stpcpy(char *dst, const char *src)
**{
**	unsigned long	*qword_dst;
**	unsigned long	*qword_src;
**
**	while (*src && ((size_t)src % sizeof(long)))
**		*(dst++) = *(src++);
**	if (HIMAGIC == -1)
**		return (ft_stpcpy_basic((char *)dst, (char *)src));
**	qword_dst = (unsigned long *)dst;
**	qword_src = (unsigned long *)src;
**	while (1)
**	{
**		if ((*qword_src - LOMAGIC) & ~(*qword_src) & HIMAGIC)
**			break ;
**		*(qword_dst++) = *(qword_src++);
**	}
**	return (_ft_stpcpy((char *)qword_dst, (char *)qword_src));
**}
*/