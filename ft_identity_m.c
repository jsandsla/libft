/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:30:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 19:56:27 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_identity_m3(t_m3 m)
{
	ft_bzero(m, sizeof(t_m3));
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
}

void	ft_identity_m4(t_m4 m)
{
	ft_bzero(m, sizeof(t_m4));
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
}

void	ft_up_vector(t_v3 up)
{
	up[0] = 0;
	up[1] = 1;
	up[2] = 0;
}
