/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:32:12 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 13:57:19 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_blen(void *ptr)
{
	int		*iptr;

	iptr = ptr;
	return (iptr ? iptr[-1] : 0);
}

int		ft_bcap(void *ptr)
{
	int		*iptr;

	iptr = ptr;
	return (iptr ? iptr[-2] : 0);
}

int		ft_bexpand(void *pptr, int req)
{
	void	*ptr;
	void	*nptr;
	int		cap;
	int		len;
	int		ncap;

	ptr = *(void **)pptr;
	cap = ft_bcap(ptr);
	len = ft_blen(ptr);
	ncap = cap ? cap * 2 : ft_to_powof2(req);
	if (ncap < req)
		ncap = ft_to_powof2(req);
	nptr = (int *)malloc(ncap + 2 * sizeof(int)) + 2;
	if ((int *)nptr - 2)
	{
		if (ptr)
		{
			ft_memcpy(nptr, ptr, ft_blen(ptr));
			free(ptr);
		}
		*(void **)pptr = nptr;
		((int *)nptr)[-1] = len;
		((int *)nptr)[-2] = ncap;
	}
	return (!!nptr);
}

int		ft_bappend(void *pptr, void *elem, int sz)
{
	int		success;
	void	*ptr;

	success = 1;
	if (ft_blen(*(void **)pptr) + sz > ft_bcap(*(void **)pptr))
		success = ft_bexpand(pptr, ft_blen(*(void **)pptr) + sz);
	if (success && sz)
	{
		ptr = *(void **)pptr;
		if (elem)
			ft_memcpy((t_byte *)ptr + ft_blen(ptr), elem, sz);
		else
			ft_memset((t_byte *)ptr + ft_blen(ptr), 0, sz);
		((int *)ptr)[-1] += sz;
	}
	return (success);
}

void	*ft_bnew(void *pptr, int sz)
{
	void	*ptr;

	ptr = 0;
	if (ft_bappend(pptr, 0, sz) && sz)
		ptr = (t_byte *)*(void **)pptr + ft_blen(*(void **)pptr) - sz;
	return (ptr);
}
