/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:22:31 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 13:53:17 by jsandsla         ###   ########.fr       */
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
	int	len;

	len = ft_vs_word_len(vs);
	ft_vs_inc(vs, len);
	ft_vs_skip_ws(vs);
}
