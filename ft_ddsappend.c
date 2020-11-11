/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddsappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:08:41 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/11 17:02:45 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddsappend(t_dds *dds, const char *str, size_t n)
{
	t_d		*d;
	t_s		s;
	size_t	res;
	t_err	error;

	error = E_OK;
	if (!dds->dd.len)
		error = ft_ddnewinit(&dds->dd, &d, NULL, dds->rate);
	if (error == E_OK)
	{
		ft_sinitm(&s, dds->dd.ptr[dds->dd.len - 1].m);
		res = ft_sappendn(&s, str, n);
		while (error == E_OK && res < n && str[res] != '\0')
		{
			str += res;
			n -= res;
			error = ft_ddnewinit(&dds->dd, &d, NULL, s.m->cap * 2);
			if (error == E_OK)
			{
				ft_sinitm(&s, d->m);
				res = ft_sappendn(&s, str, n);
			}
		}
	}
	return (error);
}

t_err			ft_ddsappendstr(t_dds *dds, const char *str)
{
	t_err	error;

	error = ft_ddsappend(dds, str, ft_strlen(str));
	return (error);
}

t_err			ft_ddsappendc(t_dds *dds, char c)
{
	t_err	error;

	error = ft_ddsappend(dds, &c, 1);
	return (error);
}

t_err			ft_ddsappends(t_dds *dds, t_s *s)
{
	t_err	error;

	error = ft_ddsappend(dds, (char *)s->m->ptr, s->m->len);
	return (error);
}

t_err			ft_ddsappendvs(t_dds *dds, t_vs *vs)
{
	t_err	error;

	error = ft_ddsappend(dds, vs->ptr + vs->offset, vs->len - vs->offset);
	return (error);
}
