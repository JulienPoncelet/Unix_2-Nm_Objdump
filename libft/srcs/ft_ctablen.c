/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctablen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 22:46:55 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/21 16:01:57 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_ctablen(char **ctab)
{
	size_t			index;

	index = 0;
	if (ctab)
	{
		while (ctab[index])
			index++;
	}
	return (index);
}
