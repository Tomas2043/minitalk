/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:55:59 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/21 14:15:42 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_server	g_server;

static void	handle_signal(int signal)
{
	g_server.current_char = g_server.current_char << 1;
	if (signal == SIGUSR2)
		g_server.current_char = g_server.current_char | 1;
	else
		g_server.current_char = g_server.current_char | 0;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		write(1, &g_server.current_char, 1);
		g_server.bit_count = 0;
		g_server.current_char = 0;
	}
}

int	main(void)
{
	g_server.bit_count = 0;
	g_server.current_char = 0;
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
