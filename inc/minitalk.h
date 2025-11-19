/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:56:11 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/19 12:07:44 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_server
{
	int				bit_count;
	unsigned char	current_char;
}	t_server;

#endif