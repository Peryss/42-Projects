/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:20:47 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 18:22:41 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>

/*printf*/

int		ft_putpointer(uintptr_t ptr);

int		ft_putunsigned(unsigned int nbr);

int		ft_hex(unsigned int nbr, char c);

int		ft_putnbr2(int nbr);

int		ft_putstr2(char *ptr);

int		ft_printf(const char *format, ...);

#endif