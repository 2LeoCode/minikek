#include <libft.h>

int	ft_strreplace_first(char **dst_ptr, char *before, char *after,
		void (*destructor)(void *))
{
	const size_t	dst_len = ft_strlen(*dst_ptr);
	const size_t	bef_len = ft_strlen(before);
	const size_t	aft_len = ft_strlen(after);
	char			*new_s;
	char			*first_occurence;

	if (!*before)
		return (0);
	first_occurence = ft_memfind(*dst_ptr, before, dst_len, bef_len);
	if (!first_occurence)
		return (1);
	new_s = (char *)malloc(sizeof(char) * (dst_len + aft_len - bef_len + 1));
	if (!new_s)
		return (-1);
	ft_memcpy(new_s, *dst_ptr, (size_t)first_occurence - (size_t)(*dst_ptr));
	ft_memcpy(new_s + (size_t)first_occurence - (size_t)(*dst_ptr), after,
		aft_len);
	ft_memcpy(new_s + (size_t)first_occurence - (size_t)(*dst_ptr) + aft_len,
		first_occurence + bef_len, ft_strlen(first_occurence + bef_len) + 1);
	if (destructor)
		(*destructor)(*dst_ptr);
	*dst_ptr = new_s;
	return (0);
}
