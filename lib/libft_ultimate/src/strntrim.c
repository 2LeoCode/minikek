#include <libft.h>

char	*ft_strntrim(const char *s, const char *set, size_t n)
{
	char			*trimmed;
	const size_t	len = ft_strlen(s);
	size_t			trim_len;
	size_t			cnt_left;
	size_t			cnt_right;

	if (!len)
		return (ft_strdup(""));
	cnt_left = 0;
	cnt_right = 0;
	while (cnt_left < n && s[cnt_left] && ft_strchr(set, s[cnt_left]))
		cnt_left++;
	while (cnt_right < n && len - cnt_left > cnt_right
		&& ft_strchr(set, s[len - 1 - cnt_right]))
		cnt_right++;
	trim_len = len - cnt_left - cnt_right;
	trimmed = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s + cnt_left, trim_len);
	trimmed[trim_len] = 0;
	return (trimmed);
}
