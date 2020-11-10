/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:58:49 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:12:33 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_minit(t_m *m, size_t sz, void *mem, size_t len, size_t cap)
{
	m->sz = sz;
	m->ptr = mem;
	m->len = len;
	m->cap = cap;
}
