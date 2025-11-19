#include<unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == 43 || base[i] == 45)
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	result[256];
	int	i;

	i = 0;
	size = 0;
	if (ft_check(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size])
			size++;
		while (nbr)
		{
			result[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[result[i]]);
	}
}