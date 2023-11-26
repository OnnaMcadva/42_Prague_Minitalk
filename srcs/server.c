/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:32:13 by annavm            #+#    #+#             */
/*   Updated: 2023/11/26 19:32:16 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	ft_handle_signal(int signal, siginfo_t *siginfo, void *cont)
{
	static int	bit = 0;
	static int	i = 0;

	(void)siginfo;
	(void)cont;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		if (i == '\n')
			ft_putstr_fd(S_END_TRANS, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putendl_fd_v(S_WLC, 1);
	ft_putstr_fd(S_PID, 1);
	ft_putnbr_fd_v(pid, 1);
	ft_putstr_fd(S_END_TRANS, 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
