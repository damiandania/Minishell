
#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

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

