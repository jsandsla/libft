/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_da.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:34:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 21:01:14 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_da(t_da *arr, size_t i)
{
	void	*ptr;

	ptr = NULL;
	if (i < arr->len)
		ptr = (t_byte *)arr->ptr + arr->sz * i;
	return (ptr);
}
