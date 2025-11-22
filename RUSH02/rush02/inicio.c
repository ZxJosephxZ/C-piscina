#include "rush02.h"

//Funcion para leer el archivo
int count_lines(const   char *file)
{
    int fd;
    char    c;
    int count;

    count = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0) return (-1);
    while (read(fd, &c, 1) == 1)
        if (c == '\n') count++;
    close(fd);
    return (count);
}

//Funcion para cargar la estructura en base al diccionario
t_entry *load_dict(const char *file, int *out_size)
{
    int line;
    int fd;
    t_entry *dict;
    char    *colon;
    char    *key;
    char    *value;
    char    buffer[256];
    int index;
    int pos;
    char c;

    line = count_lines(file);
    fd = open(file, O_RDONLY);
    index = 0;
    pos = 0;
    if (line < 1) return (NULL);
    dict = malloc(sizeof(t_entry) * line);
    if (fd < 0) return (NULL);
    while (read(fd, &c, 1) == 1)
    {
        if (c != '\n' && pos < 255)
            buffer[pos++] = c;
        else
        {
            buffer[pos] = '\0';
            pos = 0;
            colon = ft_strchr(buffer, ':');
            if (!colon) continue;
            *colon = '\0';
            key = ft_trim(buffer);
            value = ft_trim(colon + 1);
            dict[index].key = ft_strdup(key);
            dict[index].value = ft_strdup(value);
            index++;
        }
    }
    close(fd);
    *out_size = index;
    return (dict);
}

int main(int argc, char **argv)
{
    t_entry *dict;
    int dict_size;

    if (argc == 2)
    {
        dict = load_dict("numbers.dict", &dict_size);
        print_number(dict, dict_size, argv[1]);
    }
    else if (argc == 3)
    {
        dict = load_dict(argv[1], &dict_size);
        print_number(dict, dict_size, argv[2]);
    }
    else
    {
        write(1, "Dict Error\n",11);
        return (1);
    }
    return (0);
}