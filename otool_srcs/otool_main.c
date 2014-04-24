/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 10:11:21 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/24 10:40:50 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int						main(int ac, char **av)
{
	int					i;

	ac--;
	av++;
	if (ac == 0)
	{
		ft_printf("otool: at least one file must be specified\n");
		return (1);
	}
	else
	{
		i = 0;
		while (i < ac)
		{
			ft_otool(av[i]);
			i++;
		}
	}
	return (0);
}
