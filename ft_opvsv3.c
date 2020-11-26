/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opvsv3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:40:09 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 11:41:26 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mulvs_v3(t_v3 *l, float r, t_v3 *out)
{
	out->x = l->x * r;
	out->y = l->y * r;
	out->z = l->z * r;
}

void	ft_divvs_v3(t_v3 *l, float r, t_v3 *out)
{
	out->x = l->x / r;
	out->y = l->y / r;
	out->z = l->z / r;
}

void	ft_addvs_v3(t_v3 *l, float r, t_v3 *out)
{
	out->x = l->x + r;
	out->y = l->y + r;
	out->z = l->z + r;
}

void	ft_subvs_v3(t_v3 *l, float r, t_v3 *out)
{
	out->x = l->x - r;
	out->y = l->y - r;
	out->z = l->z - r;
}

void	ft_subsv_v3(float l, t_v3 *r, t_v3 *out)
{
	out->x = l - r->x;
	out->y = l - r->y;
	out->z = l - r->z;
}
