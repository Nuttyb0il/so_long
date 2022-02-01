#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_strcat(char *src, char *dest)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (src[i])
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*output;
	int		i;

	i = 0;
	while (s[i])
		i++;
	output = (char *)malloc(sizeof(char) * (i + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1 && s2 && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t    i;

    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}