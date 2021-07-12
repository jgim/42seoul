#include "push_swap.h"

int			delimiter(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void		*free_word(char **word)
{
	int	i;
	i = -1;
	while (word[++i])
		free(word[i]);
	free(word);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**src;
	int		end;
	int		j;
	int		start;

	if (!s)
		return (0);
	if (!(src = (char **)malloc(sizeof(char *) * (delimiter(s, c) + 1))))
		return (0);
	end = 0;
	while (s[end] == c)
		++end;
	j = 0;
	while (s[end] && j < delimiter(s, c))
	{
		start = end;
		while (s[end] != c && s[end])
			end++;
		src[j++] = ft_substr(s, start, end - start);
		while (s[end] == c)
			end++;
	}
	src[j] = 0;
	return (src);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		i++;
    }
    if (i > 20)
        return (-sign);
	return (sign * result);
}
