void *ft_memmove(void *dst, const void *src, int size)
{
	int i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src >= dst)
		while (i < size)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	else if (src < dst)
		while (size)
		{
			size--;
			((unsigned char *)dst)[size] = ((unsigned char *)src)[size];
		}
	return (dst);
}

void *ft_memcpy(void *dst, const void *src, int num)
{
	unsigned char *dest;
	unsigned char *source;
	int i;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}


int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (1);
		++ptr;
	}
	if (*ptr == '\0' && c == '\0')
		return (1);
	return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int s1_len;
	int s2_len;
	char *str;
	int i;
	int j;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

int ft_atoi(const char *str)
{
	int sign;
	long result;
	int i;

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
		return ((sign == 1) ? -1 : 0);
	return (sign * result);
}

int ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int i;
	int len;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	if (!dst)
		return (ft_strlen(src));
	if (dstsize)
	{
		len = (i >= dstsize) ? dstsize - 1 : i;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (i);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char *ft_strdup(const char *s1)
{
	int i;
	int len;
	char *dup;

	len = 0;
	while (s1[len])
		len++;
	dup = malloc(len + 1);
	if (dup)
	{
		i = 0;
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char *ft_substr(char const *s, unsigned int start, int len)
{
	int s_len;
	char *str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int ft_delimiter(char const *s, char c)
{
	int count;
	int i;

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

static void *free_word(char **word)
{
	int i;
	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (0);
}

char **ft_split(char const *s, char c)
{
	char **src;
	int end;
	int j;
	int start;

	j = 0;
	end = 0;
	if (!s)
		return (0);
	if (!(src = (char **)malloc(sizeof(char *) * (ft_delimiter(s, c) + 1))))
		return (0);
	while (s[end] == c)
		++end;
	while (s[end] && j < ft_delimiter(s, c))
	{
		start = end;
		while (s[end] != c && s[end])
			end++;
		if (!(src[j++] = ft_substr(s, start, end - start)))
			return (free_word(src));
		while (s[end] == c)
			end++;
	}
	src[j] = 0;
	return (src);
}

int ft_strncmp(const char *s1, const char *s2, int n)
{
	int i;
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && str1[i] != 0 && str2[i] != 0)
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	else if (str1[i] > str2[i])
		return (1);
	return (-1);
}
