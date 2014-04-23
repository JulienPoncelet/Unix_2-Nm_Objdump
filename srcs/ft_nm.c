/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 13:40:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/23 15:56:11 by jponcele         ###   ########.fr       */
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
	struct nlist_64				*nl;

	sc = (struct symtab_command *)cur;
	i = 0;
	a = start + sc->symoff;
	start = start + sc->stroff;
	while (i < sc->nsyms)
	{
		nl = (struct nlist_64 *)a;
		if (nl->n_type <= 15)
		{
			if (nl->n_value)
				ft_printf("0000000%x", nl->n_value);
			else
				ft_printf("                ");
			ft_printf(" %c ", change_type(nl->n_type));
			ft_printf("%s\n", (char *)start + nl->n_un.n_strx);
		}
		i++;
		a = a + sizeof(struct nlist_64);
	}
}

char	change_type(uint64_t value)
{
	if (value == 1)
		return ('U');
	if (value == 14)
		return ('d');
	if (value == 15)
		return ('T');
	return ('X');
}