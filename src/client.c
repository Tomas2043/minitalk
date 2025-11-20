/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:56:03 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/20 12:55:15 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	check_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		exit(1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error: Process %d not found or cannot receive signals.\n", pid);
		exit(1);
	}
}

static void	send_char(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		usleep(1000);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*string;
	int		i;

	if (ac != 3)
	{
		ft_printf("Error: Wrong amount of arguments");
		return (1);
	}
	pid = ft_atoi(av[1]);
	string = av[2];
	check_pid(pid);
	i = 0;
	while (string[i])
	{
		send_char(string[i], pid);
		i++;
	}
	send_char('\0', pid);
}
