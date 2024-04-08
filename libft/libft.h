#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

void    bzero(void *s, size_t n);

void    *ft_memchr(const void *str, int c, size_t n);

void    *ft_memcpy(void *dest, const void * src, size_t n);

void    *ft_memmove(void *str1, const void *str2, size_t n);

void    *ft_memset(void *s, int c, size_t n);

int     ft_memcmp(const void *str1, const void *str2, size_t n);

int     ft_isalpha(int arg);

int     ft_isdigit(int arg);

int     ft_isalnum(int arg);

int     ft_isascii(int arg);

int     ft_isprint(int arg);

int     ft_strlen(char *str);

int     ft_tolower(int ch);

int     ft_toupper(int ch);

int     ft_strncmp(const char *str1, const char *str2, size_t n);

char    *ft_strchr(char *str, int c);

char    *ft_strnstr(const char *big,	const char *little, size_t len);

char    *ft_strrchr(char *str, int c);

size_t  ft_strlcpy(char *dst, const char *src, size_t size);

size_t  ft_strlcat(char *dst, const char *src, size_t size);

#endif