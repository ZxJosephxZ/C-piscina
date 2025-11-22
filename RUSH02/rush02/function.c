#include "rush02.h"

char    *dict_get(t_entry   *dict, int size, const char *key)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (ft_strcmp(dict[i].key, key) == 0)
            return (dict[i].value);
        i++;
    }
    return (NULL);
}

void    print_word(const char *str)
{
    write(1, str, ft_strlen2(str));
    write(1, " ", 1);
}

void print_single_digit(t_entry *dict, int dict_size, char c)
{
    char key[2] = {c, '\0'};
    char *w = dict_get(dict, dict_size, key);
    if (w)
    {
        write(1, w, ft_strlen2(w));
        write(1, "\n", 1);
    }
}

void    print_units(t_entry *dict, int dict_size, char c)
{
    char    *w;

    if (c == '0') return ;
    char key[2] = {c, '\0'};
    w = dict_get(dict, dict_size, key);
    if (w) print_word(w);
}

void    print_tens(t_entry *dict, int dict_size, char d, char u)
{
    char    key[3];
    char    *w;

    if (d == '1')
    {
        key[0] = d;
        key[1] = u;
        key[2] = '\0';
        w = dict_get(dict, dict_size, key);
        if (w) print_word(w);
        return ;
    }
    key[0] = d;
    key[1] = '0';
    key[2] = '\0';
    w = dict_get(dict, dict_size, key);
    if (w) print_word(w);
    if (u != '0') print_units(dict, dict_size, u);
}

void    print_hundreds(t_entry *dict, int dict_size, char c, char d, char u)
{
    char *hund = dict_get(dict, dict_size, "100"); /* debe existir "100": "hundred" */

    if (c != '0')
    {
        /* imprimimos "X" + "hundred" (ej: "two" "hundred") */
        print_units(dict, dict_size, c); /* print_units no imprime '0' */
        if (hund)
            print_word(hund);
    }

    /* Ahora decenas y unidades: si d=='0' imprimimos solo unidad (si no es '0') */
    if (d == '0')
    {
        if (u != '0')
            print_units(dict, dict_size, u);
    }
    else
    {
        print_tens(dict, dict_size, d, u);
    }
}

void    print_number(t_entry *dict, int dict_size, const char *num)
{
    int len;
    int start;
    int mod;

    len = ft_strlen2(num);

    /* caso especial: único dígito (incluyendo '0') */
    if (len == 1)
    {
        print_single_digit(dict, dict_size, num[0]);
        return ;
    }

    start = 0;
    mod = len % 3;
    if (mod == 0) mod = 3;

    while (start < len)
    {
        int block_size = (start == 0 ? mod : 3);
        int i;
        int block_nonzero = 0;

        /* comprobar si el bloque actual tiene algún dígito distinto de '0' */
        for (i = 0; i < block_size; i++)
            if (num[start + i] != '0') { block_nonzero = 1; break; }

        /* Procesar bloque */
        if (block_size == 3)
            print_hundreds(dict, dict_size, num[start], num[start + 1], num[start + 2]);
        else if (block_size == 2)
            print_tens(dict, dict_size, num[start], num[start + 1]);
        else
            print_units(dict, dict_size, num[start]);

        /* imprimir escala solo si el bloque NO es 000 y hay dígitos a la izquierda */
        int digits_left = len - (start + block_size);
        if (digits_left > 0 && block_nonzero)
        {
            /* construir clave "1" + digits_left zeros */
            char scale_key[40] = "1"; /* 40 es suficiente para tus escalas */
            for (i = 0; i < digits_left; i++) ft_strcat(scale_key, "0");

            char *w = dict_get(dict, dict_size, scale_key);
            if (w) print_word(w);
        }

        start += block_size;
    }

    write(1, "\n", 1);
}