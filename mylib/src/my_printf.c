/*
** my_printf.c for draft_nov in /home/flay/works/draft_nov
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 05 12:58 PM 2017 SCHRIEVER Flavien
** Last update Nov 05 12:58 PM 2017 SCHRIEVER Flavien
*/
#include "my.h"

static const t_print    prints[] =
        {
                {'s', &print_str},
                {'d', &print_nbr},
                {'i', &print_nbr},
                {'p', &print_nbr},
                {'c', &print_char},
                {0, NULL}
        };

void        print_str(va_list list)
{
    char    *string;

    string = va_arg(list, char*);
    my_putstr(string);
}

void        print_nbr(va_list list)
{
    int     dec;

    dec = va_arg(list, int);
    my_put_nbr(dec);
}

void        print_char(va_list list)
{
    char    c;
    c = (char) va_arg(list, int);
    my_putchar(c);
}

void                inter_arg(va_list list, char c)
{
    const t_print   *print;

    print = prints;
    while (print->c != 0)
    {
        if (print->c == c)
            print->call(list);
        print++;
    }
}

void        my_printf(const char* fmt, ...)
{
    va_list list;

    va_start(list, fmt);
    while (*fmt != '\0')
    {
        if (*fmt == '%')
            inter_arg(list, *(++fmt));
        else
            my_putchar(*fmt);
        fmt++;
    }
    va_end(list);
}
