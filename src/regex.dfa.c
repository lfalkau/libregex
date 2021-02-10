/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.dfa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:12:34 by lfalkau           #+#    #+#             */
/*   Updated: 2021/02/10 13:56:51 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.nfa.h>
#include <regex.dfa.h>

t_dfa *nfa_to_dfa(t_nfa *nfa)
{
	t_dfa	*dfa;
	t_map	*map;

	map = NULL;
	if (!(dfa = dfa_new()))
		return (NULL);

	for (lettre in nfa's alphabet)
	{

	}
}