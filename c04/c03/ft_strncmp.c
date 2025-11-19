int ft_strncmp(char *s1, char *s2, unsigned int size)
{
    int i;
    i = 0;
    if (s1[i] || s2[i])
    {
        return 0;
    }
    while ((i < (size-1) && s1[i]==s2[i]) && s1[i] && s2[i])
    {
        i++;
    }
    return (s1[i] - s2[i]);
}