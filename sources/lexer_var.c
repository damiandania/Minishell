#include "minishell.h"

void	ft_lexer_var(t_token **token)
{
	t_token	*temp;
	int		i;

	temp = *token;
	while (temp)
	{
		i = 0;
		while (temp->str[1])
		{
			if (temp->str[i] == '$')
				temp->type = VAR;
			i++;
		}
		temp = temp->next;
	}
}
