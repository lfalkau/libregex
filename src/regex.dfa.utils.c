/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.dfa.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:51:56 by lfalkau           #+#    #+#             */
/*   Updated: 2021/02/10 12:59:55 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.dfa.c>

t_dfa	*dfa_new(void)
{
	t_dfa	*dfa;

	if (!(dfa = malloc(sizeof(t_dfa))))
		return (NULL);
	if (!(dfa->entrypoint = dfa_state_new()))
	{
		free(dfa);
		return (NULL);
	}
	dfa->re_expr = nfa->re_expr;
	return (dfa);
}
