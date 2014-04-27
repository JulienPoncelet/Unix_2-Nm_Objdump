/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 10:35:41 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/27 15:42:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void					ft_otool(char *filename)
{
	struct mach_header_64		*start;

	if (!(start = set_map(filename)))
		return ;
	if (start->magic == MH_MAGIC_64 || start->magic == MH_CIGAM_64)
	{
		ft_printf("%s:\n", filename);
		otool_print(start);
	}
	else
		ft_printf("otool: %s is not an object file\n", filename);
}

void					otool_print(void *start)
{
	struct mach_header_64		*mh64;
	void						*cur;
	uint64_t					i;
	struct load_command			*lc;
	struct segment_command_64	*sc;

	mh64 = start;
	cur = mh64 + sizeof(*start);
	i = 0;
	while (i < mh64->ncmds)
	{
		lc = (struct load_command *)cur;
		if (lc->cmd == LC_SEGMENT_64)
		{
			sc = (struct segment_command_64 *)cur;
			if (ft_strequ(sc->segname, "__TEXT") && sc->nsects)
				next(cur, sc, start);
		}
		cur = cur + lc->cmdsize;
		i++;
	}
}

void					next(void *cur, struct segment_command_64 *sc, void *s)
{
	uint32_t					i;
	struct section_64			*sect;
	uint64_t					start1;
	void						*start2;

	cur += sizeof(struct segment_command_64);
	i = 0;
	while (i < sc->nsects)
	{
		sect = (struct section_64 *)cur;
		if (ft_strequ(sect->sectname, "__text"))
		{
			ft_printf("(__TEXT,__text) section\n");
			start1 = sect->addr;
			start2 = s + sect->offset;
			nextnext(start1, start2, sect);
		}
		cur += sizeof(struct section_64);
		i++;
	}
}

void					nextnext(uint64_t s1, void *s2, struct section_64 *sect)
{
	uint64_t					j;

	j = 0;
	while (j < sect->size / 16)
	{
		ft_printf("%.16x ", s1 + j * 16);
		ft_dump_hexa((char *)(s2 + j * 16), 16);
		j++;
	}
	ft_printf("%.16x ", s1 + j * 16);
	ft_dump_hexa((char *)(s2 + j * 16), sect->size % 16);
}

void					ft_dump_hexa(char *dump, uint32_t len)
{
	uint32_t					i;

	i = 0;
	while (i < len)
	{
		ft_printf("%.2x ", 0xFF & dump[i]);
		i++;
	}
	ft_putchar('\n');
}
