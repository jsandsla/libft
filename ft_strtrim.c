/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:24:21 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/29 14:35:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ch;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && (ch = ft_strchr(set, s1[i])) != NULL)
		i += 1;
	s1 += i;
	len -= i;
	i = 0;
	while (i < len && (ch = ft_strchr(set, s1[len - i - 1])) != NULL)
		i += 1;
	ch = malloc(len + 1 - i);
	if (ch != NULL)
		ft_strlcpy(ch, s1, len + 1 - i);
	return (ch);
}
