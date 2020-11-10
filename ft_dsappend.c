/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:44:14 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:04:15 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsappend(t_ds *ds, const char *str, size_t n)
{
	t_m		*m;
	t_err	error;
	size_t	len;

	m = ds->s.m;
	len = ft_strnlen(str, n);
	error = E_OK;
	if (m->len >= m->cap || m->cap - m->len - 1 < len)
		error = ft_dsexpand(ds, len);
	if (error == E_OK && len)
	{
		len = ft_strncpy((char *)m->ptr + m->len, str, len);
		m->len += len;
		m->ptr[m->len] = '\0';
	}
	return (error);
}

t_err			ft_dsappendstr(t_ds *ds, const char *str)
{
	t_m		*m;
	t_err	error;
	size_t	len;

	m = ds->s.m;
	len = ft_strlen(str);
	error = E_OK;
	if (m->len >= m->cap || m->cap - m->len - 1 < len)
		error = ft_dsexpand(ds, len);
	if (error == E_OK && len)
	{
		len = ft_strncpy((char *)m->ptr + m->len, str, len);
		m->len += len;
		m->ptr[m->len] = '\0';
	}
	return (error);
}
