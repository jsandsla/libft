/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:50:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:13:56 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ainit(t_a *a, size_t sz, void *mem, size_t len, size_t cap)
{
	a->m = &a->_m;
	ft_minit(a->m, sz, mem, len, cap);
}

void			ft_ainitm(t_a *a, t_m *m)
{
	a->m = m;
}
