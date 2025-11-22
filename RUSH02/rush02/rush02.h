#ifndef RUSH02_H
# define RUSH02_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

/* Estructuras */
typedef struct s_entry
{
    char *key;
    char *value;
} t_entry;

/* Utils */
int     ft_strlen2(const char *str);
char    *ft_trim(char *str);
int ft_strlen(char *str);
char *ft_strdup(const char *src);
char *ft_strchr(const char *s, char c);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcat(char *dest, const char *src);

/* Diccionario */
t_entry *load_dict(const char *file, int *out_size);
char    *dict_get(t_entry *dict, int dict_size, const char *key);

/* Impresión */
void    print_number(t_entry *dict, int dict_size, const char *num);

#endif
