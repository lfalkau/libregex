/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.nfa.build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:37:02 by lfalkau           #+#    #+#             */
/*   Updated: 2021/02/13 10:11:14 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.nfa.h>
#include <stdlib.h>

int		nfa_surruond(t_ns *b, t_ns *e, t_ns **nb, t_ns **ne)
{
	t_pattern	epsilon;

	if (!(*nb = state_new()))
		return (-1);
	if (!(*ne = state_new()))
	{
		free(*nb);
		return (-1);
	}
	links_cpy(*nb, b);
	links_destroy(b);
	pattern_epsilon(&epsilon);
	link_add(b, epsilon, *nb);
	link_add(e, epsilon, *ne);
	return (0);
}

t_ns	*nfa_create(t_ns *beg, t_alphabet **alphabet, const char **ptr, t_bool nested)
{
	t_ns		*end;
	t_ns		*tmp;

	if (!beg)
		return (NULL);
	end = beg;
	while (nested ? **ptr && **ptr != ')' : **ptr)
	{
		tmp = end;
		if (**ptr == '(' && (*ptr)++)
		{
			if (!(end = nfa_create(end, alphabet, ptr, true)) || **ptr != ')')
				return (NULL);
			(*ptr)++;
		}
		else if (!(end = nfa_add_pattern(end, alphabet, ptr)))
			return (NULL);
		if (!(end = nfa_build_quantifier(tmp, end, ptr)))
			return (NULL);
		if (**ptr == '|' && !(end = nfa_build_or(beg, alphabet, end, ptr, nested)))
			return (NULL);
	}
	return (end);
}

t_nfa	*str_to_nfa(const char *str, t_alphabet **alphabet)
{
	t_nfa		*nfa;
	const char	*ptr;
	t_ns		*final;

	if (!(nfa = nfa_new(str)))
		return (NULL);
	ptr = nfa->re_expr;
	if (!(final = nfa_create(nfa->entrypoint, alphabet, &ptr, false)))
	{
		nfa_free(nfa);
		return (NULL);
	}
	final->is_final = true;
	return (nfa);
}
