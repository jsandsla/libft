/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_danew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:29:35 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 11:33:44 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_danew(t_da *da)
{
	void	*ptr;

	ptr = 0;
	if (ft_daappend(da, 0, 1) == E_OK)
		ptr = ft_da(da, da->a.m->len - 1);
	return (ptr);
}
