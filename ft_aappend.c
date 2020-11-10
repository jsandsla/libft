/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:53:06 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:06:15 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_aappend(t_a *a, void *elems, size_t count)
{
	size_t	result;

	result = ft_mappend(a->m, elems, count);
	return (result);
}

size_t			ft_aappendm(t_a *a, t_m *m)
{
	size_t	result;

	result = ft_mappendm(a->m, m);
	return (result);
}
