/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/10/18 15:06:40 by ddania-c         ###   ########.fr       */
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
	struct s_token	*prev;
}		t_token;


typedef struct s_data
{
	struct s_token	*token;
}		t_data;

//FUNTIONS____________________________________________________________

//	lexer
int			ft_lexer(t_data *data, char *line);

// lexer_utils
int			ft_set_status_quote(int quote, char *line, int i);
void		ft_add_sep(t_token **token, char *line, int i, int len, int type);
void		ft_add_word(t_token **token, char *line, int i, int start);

//	lexer_var
void		ft_lexer_var(t_token **token);

//	INIT

//	PRINT

//	EXIT

#endif
