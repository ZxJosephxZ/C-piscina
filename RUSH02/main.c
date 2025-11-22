#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**dictionary;
	int	i;
//Comprobaciones de argumentos
	if (argc == 1)
	{
		write(1, "Dict Error\n", 11);
		exit(1);
	}
	else if (argc == 2)
	{
		dictionary = add();
		ft_atoi(argv[1]);
		start(argv[1]);
		return (0);
	}
	else if (argc == 3)
	{
		dictionary = addv2(argv[1]);
		ft_atoi(argv[2]);
		start(argv[2], dictionary);
		return (0);
	}
	else
	{
		write(1, "Dict Error\n", 11);
		exit(1);
	}
}