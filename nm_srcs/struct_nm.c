/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_nm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 16:02:14 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/24 11:12:48 by jponcele         ###   ########.fr       */
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
			ft_printf("%0.16x ", current->offset);
		else
			ft_printf("                 ");
		ft_putchar(current->type);
		ft_printf(" %s\n", current->str);
		if (!(current->next))
			break ;
		current = current->next;
	}
}

void					sort_nm(t_nm **nm)
{
	int					change;
	t_nm				*p;
	t_nm				*q;
	t_nm				*tmp;

	change = 1;
	tmp = (t_nm *)malloc(sizeof(t_nm));
	tmp->next = *nm;
	while (change)
	{
		change = 0;
		q = tmp->next;
		p = tmp->next->next;
		while (p->next)
		{
			if (ft_strcmp(p->str, p->next->str) > 0)
			{
				change = 1;
				q->next = nm_swap(p, p->next);
			}
			q = p;
			if (p->next)
				p = p->next;
		}
	}
}

t_nm					*nm_swap(t_nm *a, t_nm *b)
{
	a->next = b->next;
	b->next = a;
	return (b);
}
