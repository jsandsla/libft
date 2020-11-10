/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:59:17 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:11:46 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_m(t_m *m, size_t offset)
{
	void	*ptr;

	ptr = NULL;
	if (offset < m->len)
		ptr = m->ptr + offset * m->sz;
	return (ptr);
}
