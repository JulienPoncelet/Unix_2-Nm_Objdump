/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:15:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/26 17:04:35 by vgedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strdup(const char *src)
{
	char			*dst;

	dst = NULL;
	if (src != NULL)
	{
		dst = (char*)malloc(sizeof(*dst) * (ft_strlen(src) + 1));
		if (dst != NULL)
			ft_strcpy(dst, src);
	}
	return (dst);
}
