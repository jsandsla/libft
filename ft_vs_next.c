/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:31:41 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 16:01:42 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vs_next(t_vs *vs)
{
	int		prev;

	prev = ft_vs(vs, 0) != '\0';
	if (prev)
		ft_vs_skip_word(vs);
	return (prev);
}

int		ft_vs_next_if(t_vs *vs, char c)
{
	int		success;

	success = ft_vs(vs, 0) == c;
	if (success)
		ft_vs_skip_word(vs);
	return (success);
}

const char		*ft_vs_next_if_str(t_vs *vs, char *str)
{
	int		success;

	success = ft_vs_str(vs, str);
	if (success)
		ft_vs_skip_word(vs);
	return (success);
}
