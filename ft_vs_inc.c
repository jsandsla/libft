/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_inc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:00:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 14:03:17 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_vs_inc(t_vs *vs, size_t offset)
{
	char	prev;

	prev = ft_vs(vs, 0);
	offset = FT_MIN(offset, vs->len - vs->offset);
	vs->offset += offset;
	return (prev);
}

char			ft_vs_inc_if(t_vs *vs, char c)
{
	if (ft_vs(vs, 0) == c)
		c = ft_vs_inc(vs, 1);
	else
		c = 0;
	return (c);
}

char			ft_vs_inc_if_str(t_vs *vs, char *str)
{
	char	c;
	int		len;

	if ((len = ft_vs_str(vs, str)))
		c = ft_vs_inc(vs, len);
	else
		c = 0;
	return (c);
}

char			ft_vs_inc_if_word(t_vs *vs, char *str)
{
	char	c;
	int		wordlen;

	if ((wordlen = ft_vs_word(vs, str)))
		c = ft_vs_inc(vs, wordlen);
	else
		c = 0;
	return (c);
}
