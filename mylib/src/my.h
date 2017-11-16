/*
** file.c for draft_nov in /home/flay/works/draft_nov
**
** Made by Schriever Flavien
** Login   <schrie_f@etna-alternance.net>
**
** Started on  Nov 05 11:57 AM 2017 SCHRIEVER Flavien
** Last update Nov 05 11:57 AM 2017 SCHRIEVER Flavien
*/
#ifndef _DRAFT_NOV_MY_H_
#define _DRAFT_NOV_MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

typedef struct      s_print
{
    char            c;
    void            (*call)(va_list);
}                   t_print;

int			        my_getnbr(char *str);
int			        my_is_char(char c);
int                 my_isneg(int n);
int 		        my_nb_len(int n);
int			        my_nbr_word(char *str);
void		        my_put_nbr(int n);
void	            my_putchar(char c);
void                my_putstr(char *str);
char		        **my_str_to_wordtab(char *str);
char		        *my_strcat(char *str1, char *str2);
int                 my_strcmp(char *s1, char *s2);
char                *my_strcpy(char *dest, char *src);
char		        *my_strdup(char *str);
int                 my_strlen(char *str);
char		        *my_strncat(char *str1, char *str2, int n);
int                 my_strncmp(char *s1, char *s2, int n);
char                *my_strncpy(char *s1, char *s2, int n);
void                my_swap(int *a, int *b);
int			        my_word_size(char *str);
void                my_printf(const char* fmt, ...);
char                *my_init_str(char *str, int len, char c);
int                 my_readin(char *str, int len);
void                my_set_readin_noblock();
void                print_str(va_list list);
void                print_nbr(va_list list);
void                print_char(va_list list);
char 		        *my_get_nbr(int n);

#endif // _DRAFT_NOV_MY_H_
