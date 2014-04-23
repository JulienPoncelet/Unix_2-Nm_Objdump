/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:11:28 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/26 17:04:35 by vgedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strrchr(const char *src, int value)
{
	size_t			index;
	char			*res;

	index = 0;
	res = NULL;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			res = (char*)&src[index];
		index++;
	}
	if ((char)value == '\0')
		return ((char*)&src[index]);
	return (res);
}
