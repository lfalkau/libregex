/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa.pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:40:33 by lfalkau           #+#    #+#             */
/*   Updated: 2021/02/02 13:54:30 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libregex.h"

t_pattern	pattern_epsilon()
{
	t_pattern p;

	p.start = NULL;
	p.end = NULL;
	return (p);
}