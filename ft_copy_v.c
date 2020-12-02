/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:56:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/30 12:53:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copy_v3(t_v3 l, t_v3 out)
{
	out[0] = l[0];
	out[1] = l[1];
	out[2] = l[2];
}

void	ft_copy_v4(t_v4 l, t_v4 out)
{
	out[0] = l[0];
	out[1] = l[1];
	out[2] = l[2];
	out[3] = l[3];
}

void	ft_copy_m3(t_m3 l, t_m3 out)
{
	ft_memcpy(out, l, sizeof(t_m3));
}

void	ft_copy_m4(t_m4 l, t_m4 out)
{
	ft_memcpy(out, l, sizeof(t_m4));
}
