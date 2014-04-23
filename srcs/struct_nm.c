/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_nm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 16:02:14 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/23 18:33:06 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

t_nm					**init_nm(uint32_t size)
{
	t_nm				**nm;
	t_nm				*first;

	nm = (t_nm **)malloc(sizeof(t_nm *) * size);
	first = (t_nm *)malloc(sizeof(t_nm));
	first->offset = 0;
	first->type = 0;
	first->str = 0;
	first->next = 0;
	*nm = first;
	return (nm);
}

void					add_to_nm(t_nm **nm, struct nlist_64 *nl, void *start)
{
	t_nm				*add;
	t_nm				*current;

	current = *nm;
	add = (t_nm *)malloc(sizeof(t_nm));
	while (current->next)
		current = current->next;
	add->offset = nl->n_value;
	add->type = change_type(nl->n_type);
	add->str = (char *)start + nl->n_un.n_strx;
	current->next = add;
}

void					print_nm(t_nm **nm)
{
	t_nm				*current;

	sort_nm(nm);
	current = *nm;
	current = current->next;
	while (42)
	{
		if (current->offset)
			ft_printf("0000000%x ", current->offset);
		else
			ft_printf("                 ");
		ft_printf("%c %s\n", current->type, current->str);
		if (!(current->next))
			break ;
		current = current->next;
	}
}

void					sort_nm(t_nm **nm)
{
	int					change;
	t_nm				*current;
	t_nm				*tmp;

	change = 1;
	while (change)
	{
		change = 0;
		current = *nm;
		current = current->next;
		while (current->next)
		{
			ft_printf("%s - %s - %d\n", current->str, current->next->str, ft_strcmp(current->str, current->next->str));
			if (ft_strcmp(current->str, current->next->str) > 0)
			{
				change = 1;
				tmp = current;
				current-
				current->next = tmp;
			}
			current = current->next;
		}
	}
}
