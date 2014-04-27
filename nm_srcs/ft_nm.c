/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 13:40:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/27 16:38:02 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void	ft_nm(char *filename, int ac)
{
	struct mach_header_64		*start;

	if (!(start = set_map(filename)))
		return ;
	if (start->magic == MH_MAGIC_64 || start->magic == MH_CIGAM_64)
	{
		if (ac != 1)
			ft_printf("\n%s:\n", filename);
		nm_print(start);
	}
	else
		ft_printf("ft_nm: %s is not a valid file\n", filename);
}

void	nm_print(void *start)
{
	struct mach_header_64		*mh64;
	void						*cur;
	uint32_t					i;
	struct load_command			*lc;

	mh64 = start;
	cur = mh64 + sizeof(*start);
	i = 0;
	while (i < mh64->ncmds)
	{
		lc = (struct load_command *)cur;
		if (lc->cmd == LC_SYMTAB)
		{
			print_symtab(cur, start);
			break ;
		}
		cur = cur + lc->cmdsize;
		i++;
	}
}

void	print_symtab(struct mach_header_64 *cur, void *start)
{
	struct symtab_command		*sc;
	uint32_t					i;
	void						*a;
	t_nm						**nm;
	struct nlist_64				*nl;

	sc = (struct symtab_command *)cur;
	a = start + sc->symoff;
	start = start + sc->stroff;
	nm = init_nm(sc->nsyms);
	i = 0;
	while (i < sc->nsyms)
	{
		nl = (struct nlist_64 *)a;
		if (nl->n_type <= 15)
			add_to_nm(nm, nl, start);
		i++;
		a = a + sizeof(struct nlist_64);
	}
	print_nm(nm);
}

char	change_type(uint8_t type, uint8_t sect)
{
	if (type == 1)
		return ('U');
	if (type == 14)
	{
		if (sect == 1)
			return ('t');
		if (sect == 8)
			return ('s');
		if (sect == 9)
			return ('d');
		if (sect == 11)
			return ('b');
	}
	if (type == 15)
	{
		if (sect == 1)
			return ('T');
		if (sect == 8)
			return ('D');
		if (sect == 9 || sect == 11)
			return ('S');
		if (sect == 10)
			return ('D');
	}
	return ('X');
}
