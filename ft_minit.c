/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:58:49 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/13 21:07:55 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_minit(t_m *m, size_t sz, void *mem, size_t cap)
{
	m->sz = sz;
	m->ptr = mem;
	m->len = 0;
	m->cap = cap;
}
