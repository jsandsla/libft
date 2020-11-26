/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:30:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 15:31:32 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_identity_m3(t_m3 *m)
{
	ft_bzero(m, sizeof(*m));
	m->r0.x = 1;
	m->r1.y = 1;
	m->r2.z = 1;
}

void	ft_identity_m4(t_m4 *m)
{
	ft_bzero(m, sizeof(*m));
	m->r0.x = 1;
	m->r1.y = 1;
	m->r2.z = 1;
	m->r3.w = 1;
}
