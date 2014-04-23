/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 13:07:47 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/23 14:23:32 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int				main(int ac, char **av)
{
	int			i;

	ac--;
	av++;
	if (!ac)
		ft_nm("a.out", ac);
	else if (ac == 1)
		ft_nm(av[0], ac);
	else
	{
		i = 0;
		while (i < ac)
		{
			ft_nm(av[i], ac);
			i++;
		}
	}
	return (0);
}
