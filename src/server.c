/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:55:59 by toandrad          #+#    #+#             */
/*   Updated: 2025/10/13 11:48:33 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int				g_bit_count;
unsigned char	g_current_char;

static void	handle_signal(int signal)
{
	if (signal == SIGUSR2)
		g_current_char |= (1 << g_bit_count);
	g_bit_count++;
	if (g_bit_count == 8)
	{
		write(1, &g_current_char, 1);
		g_bit_count = 0;
		g_current_char = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
