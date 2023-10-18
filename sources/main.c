
#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	ft_print_lexer(t_data *data)
{
	t_token	*current;

	current = data->token;
	while (current)
	{
		printf("[%u__%s__]\n", current->type, current->str);
		current = current->next;
	}
	printf("\n");
}

bool	prompt(t_data *data)
{
	char	*line;

	(void)data;

	while (1)
	{
		line = readline("minishell$ ");
		printf("line = %s\n", line);
		if (line == NULL)
			break ;
		data->token = NULL;
		ft_lexer(data, line);
		// ft_lexer_var(&data->token);
		ft_lexer_error(data->token);

		ft_print_lexer(data);

		free (line);
		line = NULL;
		data->token = NULL;
	}
	return (true);
}

int	main()
{
	t_data	data;

	if(prompt(&data) == 0)
			return (1);

	return (0);
}

