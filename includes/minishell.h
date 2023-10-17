/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/10/18 01:34:55 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//INCLUDES____________________________________________________________

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

//MACROS______________________________________________________________

# define SUCCES 0
# define FAILURE 1

//STRUCTURE___________________________________________________________

enum e_type
{
	WORD = 1,
	SPACES,
	PIPE,
	LESS,
	GREAT,
	LESS_LESS,
	GREAT_GREAT,
	END,
	VAR,
};

enum e_quote
{
	N_QUOTE,
	S_QUOTE,
	D_QUOTES,
};

typedef struct s_token
{
	enum e_type		type;
	char			*str;
	struct s_token	*next;
}		t_token;

typedef struct s_data
{
	struct s_token	*token;
}		t_data;

//FUNTIONS____________________________________________________________

//	LEXER
int	ft_lexer(t_data *data, char *line);
int	set_status_quote(int quote, char *line, int i);

//	UTILS

//	INIT

//	PRINT

//	EXIT

#endif
