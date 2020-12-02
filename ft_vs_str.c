/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:09:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 15:03:31 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_vs_str(t_vs *vs, const char *str)
{
	int		result;
	size_t	len;

	len = ft_strnlen(str, vs->len - vs->offset);
	result = 0;
	if (!str[len])
		result = ft_strncmp(vs->ptr + vs->offset, str, len) == 0;
	return (result ? len : 0);
}

static	void	word_num(t_vs *vs, char c)
{
	int		bit;

	bit = ft_vs(vs, 1);
	bit = 4 + (c == '0' && (bit == 'x' || bit == 'X')) * 124;
	if (bit == 128)
		ft_vs_inc(vs, 2);
	if (c == '-' || c == '+')
		ft_vs_inc(vs, 1);
	while ((c = ft_vs(vs, 0)) && g_ctype_char_info[(unsigned char)c] & bit)
		ft_vs_inc(vs, 1);
	if (c == '.' && IS_DIGIT(ft_vs(vs, 1)))
	{
		ft_vs_inc(vs, 1);
		while ((c = ft_vs(vs, 0)) && g_ctype_char_info[(unsigned char)c] & bit)
			ft_vs_inc(vs, 1);
	}
}

int				ft_vs_word_len(t_vs *vs)
{
	char	c;
	int		start;

	start = vs->offset;
	c = ft_vs(vs, 0);
	if (IS_ALPHA(c) || c == '_')
		while ((c = ft_vs(vs, 0)) && (IS_ALPHA(c) || c == '_'))
			ft_vs_inc(vs, 1);
	else if (IS_DIGIT(c) || ((c == '-' || c == '+') && IS_DIGIT(ft_vs(vs, 1))))
		word_num(vs, c);
	else if (ft_strchr("!@#$%^&*()-+=~/[];,.'\":`{}\\", c))
		ft_vs_inc(vs, 1);
	start = vs->offset - start;
	vs->offset -= start;
	return (start);
}

int				ft_vs_word(t_vs *vs, const char *str)
{
	int		wordlen;
	t_vs	strvs;
	int		result;

	wordlen = ft_vs_word_len(vs);
	if (wordlen)
	{
		strvs = ft_vs_create(str, wordlen + 1);
		result = ft_vs_word_len(&strvs) == wordlen &&
			ft_strncmp(vs->ptr + vs->offset, str, wordlen) == 0;
		if (!result)
			wordlen = 0;
	}
	return (wordlen);
}
