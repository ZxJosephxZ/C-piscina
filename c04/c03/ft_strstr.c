char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;
    i = 0;
    j = 0;
    if (!to_find)
    {
        return str;
    }
    while (str[i])
    {
        if (str[i] == to_find[0])
        {
            while (str[j] == to_find[j])
            {
                j++;
            }
        }
        if (j)
        {
            return str + (i+j);
        }
        i++;
    }
    return 0;
}