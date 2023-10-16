/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:06:07 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/16 15:35:43 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>



bool	prompt(t_data *data)
{
	while (1)
	{
		data->input = readline("minishell$ ");
		printf("input = %s\n", data->input);
		if (data->input == NULL)
		{
			return (false);
		}
		free (data->input);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac == 1)
	{
		if(prompt(&data) == 0)
			return (1);
	}
	return (0);
}
