int	set_status_quote(int quote, char *line, int i)
{
	if (line[i] == '\'' && quote == N_QUOTE)
		quote = S_QUOTE;
	else if (line[i] == '\"' && quote == N_QUOTE)
		quote = D_QUOTES;
	else if (line[i] == '\'' && quote == S_QUOTE)
		quote = N_QUOTE;
	else if (line[i] == '\"' && quote == D_QUOTES)
		quote = D_QUOTES;
	// ft_lstadd_back_token(&data->tlist, ft_token(&line[i], quote));
	return (quote);
}

int	ft_lexer(t_data *data, char *line)
{
	int	i;
	int	quote;
	int	start;

	start = 0;
	i = 0;
	quote = N_QUOTE;
	while (line && line[i])
	{
		quote = set_status_quote(quote, line, i);
		if (quote == N_QUOTE)
			start = ft_token(&i, line, start, data);
		i++;
	}
	if (quote != N_QUOTE)
	{
		ft_putstr_fd("error: unclosed quotes\n", 2);
		return (1);
	}
	return (0);
}