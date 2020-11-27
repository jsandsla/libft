/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:09:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 16:13:49 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vs_str(t_vs *vs, const char *str)
{
	int		result;
	size_t	len;

	len = ft_strnlen(str, vs->len - vs->offset);
	result = 0;
	if (!str[len])
		result = ft_strncmp(vs->ptr + vs->offset, str, len);
	return (result);
}
