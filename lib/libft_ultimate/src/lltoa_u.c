#include <libft.h>size_t	nb_size_u(unsigned long long n){	size_t	size;	size = 0;	while (n)	{		size++;		n /= 10ULL;	}	return (size);}char	*ft_lltoa_u(unsigned long long n){	char			*s;	const size_t	len = nb_size_u(n);	s = (char *)calloc(len + 1, sizeof(char));	if (!s)		return (NULL);	s += len;	while (n)	{		*(--s) = (char)(n % 10ULL) + '0';		n /= 10ULL;	}	return (s);}