/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/28 02:16:18 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

typedef struct s_data
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_info;

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	is_ready;
}	t_global;

extern t_global	g_server;

void	validate_arguments(int argc, char **argv);
int		check_server_status(int pid);

void	init_client_data(char **argv, t_info *data);
void	send_signal(pid_t pid, int signal);
void	send_message_bits(void *data, size_t bit_length, t_info *info);
void	client_signal_handler(int signum, siginfo_t *info, void *context);
void	transmit_message_to_server(char *str, t_info *data);

#endif
