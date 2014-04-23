/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:20:40 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/26 16:58:48 by vgedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memalloc(size_t size)
{
	void			*mem;

	mem = NULL;
	mem = (void*)malloc(size);
	if (!mem)
		return (NULL);
	return (mem);
}
