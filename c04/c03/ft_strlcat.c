unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int i;
    int j;
    int r;
    j = 0;
    r = 0;
    i = 0;
    while (dest[i])
    {
        i++;
    }
    while (src[j])
    {
        j++;
    }
    if (size <= i)
    {
        j += size;
    }
    else{
        j += i;
    }
    while (i+1 < size && src[r])
    {
        dest[i] = src[r];
        r++;
        i++;
    }
    dest[i] = '\0';
    return j;
}