/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:53 by jgim              #+#    #+#             */
/*   Updated: 2021/03/01 00:28:23 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH "*1234567890"
#define PREC "*1234567890"
#define TYPE "%cspdiuxX"

typedef struct s_factor
{
	int minus;
	int zero;
	int width;
	int dot;
	int prec;
	int str_len;
	int error;
	int sign;
	int prec_len;
	int rtn;
	int c_null;
	char type;
	char *str;
	char *format;
	char *tmp;
	va_list v_args;
} t_factor;

int ft_printf(const char *format, ...);
void factor_set(t_factor *factor);
int check_printf(t_factor *factor);
void ft_putstr(t_factor *factor);
int ft_putchar(char c);
int ft_strlen(const char *s);
int ft_strchr(const char *s, int c);
void ft_putstr(t_factor *factor);
int d_print(int d, t_factor *factor);
int s_print(char *s, t_factor *factor);
int c_print(int c, t_factor *factor);
void flag_prec(t_factor *factor, char flag);
void flag_width(t_factor *factor, char flag);
void flag_zero_minus(t_factor *factor, char flag);
void signal_printf(t_factor *factor, char flag);
void *ft_memcpy(void *dst, const void *src, size_t num);
char *ft_strdup(const char *s1);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strjoin_left(char const *s1, char const *s2);
char *ft_strjoin_right(char const *s1, char const *s2);
size_t n_len(unsigned int num);
size_t x_n_len(unsigned long long num);
char *ft_itoa(unsigned int n, t_factor *factor);
char *ft_upper_x_itoa(unsigned long long n, t_factor *factor);
char *ft_lower_x_itoa(unsigned long long n, t_factor *factor);
void join_width(t_factor *factor);
void join_prec(t_factor *factor);
void compare_flag(t_factor *factor);
int refine_type(t_factor *factor);
int check_printf(t_factor *factor);
void factor_set(t_factor *factor);
void join_zero_blank(int i, char *zb, t_factor *factor);
int ft_printf(const char *format, ...);
int p_print(unsigned long long p, t_factor *factor);
int upper_x_print(unsigned int x, t_factor *factor);
int lower_x_print(unsigned int x, t_factor *factor);
int u_print(unsigned int u, t_factor *factor);

#endif
