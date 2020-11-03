/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lninit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:20:10 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 12:26:06 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err	ft_lninit(t_line *ln, char *str, size_t max_len)
{
	t_err	error;

	error = E_SUCCESS;
	ln->ptr = 0;
	ln->len = 0;
	ln->max_len = 0;
	if (max_len && error == E_SUCCESS)
		error = ft_lnexpand(ln, max_len);
	if (str && error == E_SUCCESS)
		error = ft_lnappend(ln, str, max_len);
	return (error);
}
