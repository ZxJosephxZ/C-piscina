int	ft_sqrt(int nb)
{
	int	number;

	number = 1;
	if (nb > 0)
	{
		while (number * number <= nb)
		{
			if (number * number == nb)
				return (number);
			else if (number >= 46341)
				return (0);
			number++;
		}
	}
	return (0);
}