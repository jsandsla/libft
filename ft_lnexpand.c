/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnexpand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:26:34 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 13:13:52 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_lnexpand(t_line *ln, size_t required)
{
	size_t	new_max_len;
	char	*new_ptr;
	t_err	error;

	new_max_len = (ln->max_len) ? (ln->max_len * 2) : (16);
	while (new_max_len < required)
		new_max_len *= 2;
	new_ptr = malloc(new_max_len + 1);
	error = E_MALLOC;
	if (new_ptr)
	{
		error = E_SUCCESS;
		if (ln->ptr)
		{
			ln->len = FT_min(ln->len, new_max_len);
			ft_memcpy(new_ptr, ln->ptr, ln->len);
			free(ln->ptr);
		}
		new_ptr[ln->len] = '\0';
		ln->ptr = new_ptr;
		ln->max_len = new_max_len;
	}
	return (error);
}
