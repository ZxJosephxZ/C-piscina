char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!nb)
    {
        return dest;
    }
    while (dest[i])
    {
        i++;
    }
    while ((j < nb) && src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}