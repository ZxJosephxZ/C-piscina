#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	**add(void)
{
    char	c;
	char	**dictionary;
    int	countij[2];
	int	count[3];
	int	fd;
//w es count[3]
	if ((fd = open("numbers.dict", O_RDONLY)) < 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	count[1] = 0;
	count[3] = 0;
	while (read(fd, &c, 1) != 0)
	{
		count[0] = 0;
		while (c != '\n')
		{
			read(fd, &c, 1);
			count[0]++;
		}
		count[3]++;
		if (count[0] > count[1])
			count[1] = count[0];
		read(1, &c,1);
	}
	close(fd);
	dictionary = (char **) malloc(sizeof(char *) * (count[3] + 1));
	countij[0] = 0;
	while (countij[0] < count[3]+1)
	{
		dictionary[countij[0]] = (char *) malloc(sizeof(char) * count[1] + 2);
		countij[0]++; 
	}
	fd = open("numbers.dict", O_RDONLY);
	while (read(fd, &c, 1) != 0)
	{
		while (countij[0] < count[3])
		{
			countij[1] = -1;
			while (countij[1]++ < count[1] + 1)
			{
				if (c != '\n')
				{
					dictionary[countij[0]][countij[1]] = c;
					read(fd, &c, 1);
				}
				else
					dictionary[countij[0]][countij[1]] = 0;
			}
			dictionary[countij[0]][countij[1]] = '\n';
			dictionary[countij[0]][countij[1]+1] = 0;
			read(fd, &c, 1);
			countij[0]++;
		}
	}
	close(fd);
	return (dictionary);
}