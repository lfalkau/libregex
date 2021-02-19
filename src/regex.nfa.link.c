/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.nfa.link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:34:55 by lfalkau           #+#    #+#             */
/*   Updated: 2021/02/19 13:45:46 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.fa.h>
#include <libft.h>

void	link_add(t_ns *st, t_pattern pattern, t_ns *next)
{
	if (!st->left.next)
	{
		st->left.next = next;
		ft_memcpy(st->left.pattern, pattern, sizeof(t_pattern));
	}
	else
	{
		st->right.next = next;
		ft_memcpy(st->right.pattern, pattern, sizeof(t_pattern));
	}
}

void	links_destroy(t_ns *st)
{
	link_init(&st->left);
	link_init(&st->right);
}

void	links_cpy(t_ns *dst, t_ns *src)
{
	dst->left = src->left;
	dst->right = src->right;
}

void	link_init(t_link *ln)
{
	ft_memset(ln, 0, sizeof(t_link));
	ln->match = &pattern_match;
}

int	nfa_has_link(t_pattern *p, t_ns *state)
{
	return (!pattern_cmp(*p, state->left.pattern)
		|| !pattern_cmp(*p, state->right.pattern));
}
