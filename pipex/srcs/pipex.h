/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:19:52 by pvass             #+#    #+#             */
/*   Updated: 2024/06/16 13:44:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
#include <sys/types.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_all
{
	int		stdin_copy;
	int		stdout_copy;
}	t_all;



#endif