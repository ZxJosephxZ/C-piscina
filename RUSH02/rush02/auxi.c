#include "rush02.h"

char *ft_strdup(const char *src)
{
    int i;
    char *dup;

    i = 0;
    dup = (char *)malloc(ft_strlen2(src) + 1);
    if (!dup)
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char *ft_strchr(const char *s, char c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *) &s[i]);
        i++;
    }
    if (c == '\0')
        return ((char *) &s[i]);
    return (NULL);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;

    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *ft_strcat(char *dest, const char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;

    while (src[j])
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i + j] = '\0';
    return (dest);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i]) i++;
    return (i);
}

int ft_strlen2(const char *str)
{
    int i;
    
    i = 0;
    while (str[i]) i++;
    return (i);
}

char *ft_trim(char *str)
{
    char    *end;

    while (*str == ' ' || *str == '\t') str++;
    end = str + ft_strlen(str) - 1;
    while (end > str && (*end == '\t' || *end == '\n' || *end == 32))
    {
        *end = '\0';
        end--;
    }
    return (str);
}