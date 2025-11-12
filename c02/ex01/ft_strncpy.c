#include <string.h>
#include <stdio.h>
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while(i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

int main()
{
	char a[50];
	printf("%s", strncpy(a, "h3dsdsd",3));
	return 0;
}
