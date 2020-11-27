/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:22:31 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 15:57:39 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vs_skip_ws(t_vs *vs)
{
	char	c;

	while ((c = ft_vs(vs, 0)) && IS_SPACE(c))
		ft_vs_inc(vs, 1);
}

void			ft_vs_skip_word(t_vs *vs)
{
	char	c;
	int		bit;

	c = ft_vs(vs, 0);
	if (IS_ALPHA(c) || c == '_')
		while ((c = ft_vs(vs, 0)) && (IS_ALPHA(c) || c == '_'))
			ft_vs_inc(vs, 1);
	else if (IS_DIGIT(c) || ((c == '-' || c == '+') && IS_DIGIT(ft_vs(vs, 1))))
	{
		bit = 4;
		if (c == '0' && (ft_vs(vs, 1) == 'x' || ft_vs(vs, 1) == 'X'))
		{
			bit = 128;
			ft_vs_inc(vs, 2);
		}
		if (c == '-' || c == '+')
			ft_vs_inc(vs, 1);
		while ((c = ft_vs(vs, 0)) && g_ctype_char_info[(unsigned char)c] & bit)
			ft_vs_inc(vs, 1);
	}
	else if (ft_strchr("!@#$%^&*()-+=~/[];,.'\":`{}\\", c))
		ft_vs_inc(vs, 1);
	ft_vs_skip_ws(vs);
}
