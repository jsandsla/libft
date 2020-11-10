/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:23:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:06:35 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_scut(t_s *s, size_t offset, size_t len)
{
	len = ft_mcut(s->m, offset, len);
	if (len)
		s->m->ptr[s->m->len] = '\0';
	return (len);
}
