/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:19:28 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 14:07:54 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putfloat_fd(float n, int fd)
{
	char	buf[32];
	int		i;

	i = ft_dtostr(buf, sizeof(buf) - 1, n);
	buf[i] = 0;
	write(fd, buf, i);
}

void			ft_putfloat(float n)
{
	char	buf[32];
	int		i;

	i = ft_dtostr(buf, sizeof(buf) - 1, n);
	buf[i] = 0;
	write(STDOUT_FILENO, buf, i);
}
