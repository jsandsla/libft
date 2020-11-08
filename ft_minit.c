/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:58:49 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 20:59:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_minit(t_m *m, void *mem, size_t len, size_t cap)
{
	m->ptr = mem;
	m->len = len;
	m->cap = cap;
}
