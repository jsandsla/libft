/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:09:47 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:29:09 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_daremove(t_da *da, size_t index)
{
	ft_aremove(&da->a, index);
	da->d->len = da->a.len * da->a.sz;
}
