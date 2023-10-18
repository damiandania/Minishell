#include "minishell.h"

void	ft_print_lexer(t_data *data)
{
	t_token	*current;

	current = data->token;
	while (current)
	{
		printf("[%u__%s__]", current->type, current->str);
		current = current->next;
	}
	printf("\n");
}

t_token	*ft_new_token(char *str, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token) * 1);
	if (!(new))
		return (NULL);
	new->str = str;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*temp;

	if (!new)
		return ;
	if (!lst || !*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_add_sep(t_token **token, char *line, int i, int len, int type)
{
	int		index;
	char	*str;

	index = 0;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (ft_putstr_fd("error: malloc\n", 2)); //Look for a better exit way
	while (index < (len - 1))
	{
		str[index] = line[i];
		index++;
		i++;
	}
	str[index] = '\0';
	ft_lstadd_back_token(token, ft_new_token(str, type));
}

void	ft_add_word(t_token **token, char *line, int i, int start)
{
	int		index;
	char	*str;

	index = 0;
	str = malloc(sizeof(char) * (i - start + 1));
	if (!str)
		return (ft_putstr_fd("error: malloc\n", 2)); //Look for a better exit way
	while (start < i)
	{
		str[index] = line[start];
		index++;
		start++;
	}
	str[index] = '\0';
	ft_lstadd_back_token(token, ft_new_token(str, WORD));
}

int	ft_set_sep_type(char *line, int i)
{
	if (((line[i] > 8 && line[i] < 14) || line[i] == 32))
		return (SPACES);
	else if (line[i] == '|')
		return (PIPE);
	else if (line[i] == '<' && line[i + 1] == '<')
		return (LESS_LESS);
	else if (line[i] == '>' && line[i + 1] == '>')
		return (GREAT_GREAT);
	else if (line[i] == '<')
		return (LESS);
	else if (line[i] == '>')
		return (GREAT);
	else if (line[i] == '\0')
		return (END);
	return (9);
}

int	ft_token(int *i, char *line, int start, t_data *data)
{
	int	sep_type;

	sep_type = ft_set_sep_type(line, (*i));
	if (sep_type != 9)
	{
		if ((*i) != 0 && ft_set_sep_type(line, (*i) - 1) == 9)
			ft_add_word(&data->token, line, (*i), start);
		else if (sep_type == PIPE || sep_type == LESS || sep_type == GREAT
			|| sep_type == END)
			ft_add_sep(&data->token, line, (*i), 2,sep_type);
		else if (sep_type == LESS_LESS || sep_type == GREAT_GREAT)
		{
			ft_add_sep(&data->token, line, (*i), 3,sep_type);
			(*i)++;
		}
		start = 1 + (*i);
	}
	return (start);
}

int	ft_set_status_quote(int quote, char *line, int i)
{
	if (line[i] == '\'' && quote == N_QUOTE)
		quote = S_QUOTE;
	else if (line[i] == '\"' && quote == N_QUOTE)
		quote = D_QUOTES;
	else if (line[i] == '\'' && quote == S_QUOTE)
		quote = N_QUOTE;
	else if (line[i] == '\"' && quote == D_QUOTES)
		quote = N_QUOTE;
	return (quote);
}

int	ft_lexer(t_data *data, char *line)
{
	int	i;
	int	quote;
	int	start;
	int	end;

	end = ft_strlen(line);
	start = 0;
	i = 0;
	quote = N_QUOTE;
	while (i <= end)
	{
		quote = ft_set_status_quote(quote, line, i);
		if (quote == N_QUOTE)
			start = ft_token(&i, line, start, data);
		i++;
	}
	if (quote != N_QUOTE)
	{
		ft_putstr_fd("error: unclosed quotes\n", 2);
		return (1);
	}
	ft_print_lexer(data);
	return (0);
}
