/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:32:23 by jgim              #+#    #+#             */
/*   Updated: 2021/08/22 18:32:25 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define GREEN "\e[1;92m"
# define RED "\e[1;91m"
# define YELLOW "\e[1;93m"
# define CYAN "\e[1;96m"
# define PURPLE "\e[1;95m"
# define RESET "\033[0m"
# define HELLO "hello";

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	end_message(void);

#endif
