/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opvsv4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:24:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 18:04:38 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mulvs_v4(t_v4 l, float r, t_v4 out)
{
	out[0] = l[0] * r;
	out[1] = l[1] * r;
	out[2] = l[2] * r;
	out[3] = l[3] * r;
}

void	ft_divvs_v4(t_v4 l, float r, t_v4 out)
{
	out[0] = l[0] / r;
	out[1] = l[1] / r;
	out[2] = l[2] / r;
	out[3] = l[3] / r;
}

void	ft_addvs_v4(t_v4 l, float r, t_v4 out)
{
	out[0] = l[0] + r;
	out[1] = l[1] + r;
	out[2] = l[2] + r;
	out[3] = l[3] + r;
}

void	ft_subvs_v4(t_v4 l, float r, t_v4 out)
{
	out[0] = l[0] - r;
	out[1] = l[1] - r;
	out[2] = l[2] - r;
	out[3] = l[3] - r;
}

void	ft_subsv_v4(float l, t_v4 r, t_v4 out)
{
	out[0] = l - r[0];
	out[1] = l - r[1];
	out[2] = l - r[2];
	out[3] = l - r[3];
}
