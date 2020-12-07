/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comparev3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:21:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/03 19:22:32 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_max_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = FT_MAX(l[0], r[0]);
	out[1] = FT_MAX(l[1], r[1]);
	out[2] = FT_MAX(l[2], r[2]);
}

void			ft_min_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = FT_MIN(l[0], r[0]);
	out[1] = FT_MIN(l[1], r[1]);
	out[2] = FT_MIN(l[2], r[2]);
}
