/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:20:47 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 12:21:39 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*printf*/

int	ft_putpointer (unsigned long long ptr);

int	ft_putunsigned (unsigned int nbr);

int	ft_hex (long long nbr, char c);

int	ft_putnbr2(int nbr);

int ft_putstr2(char *ptr);

#endif