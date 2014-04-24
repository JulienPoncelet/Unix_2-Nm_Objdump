/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 10:35:41 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/24 11:38:31 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void							ft_otool(char *filename)
{
	struct mach_header_64		*start;

	if (!(start = set_map(filename)))
		return ;
	if (start->magic == MH_MAGIC_64 || start->magic == MH_CIGAM_64)
		otool_print(start);
	else
		ft_printf("otool: is not an object file: %s\n", filename);
}

void							otool_print(void *start)
{
	struct mach_header_64		*mh64;
	void						*cur;
	uint64_t					i;
	struct load_command			*lc;
	struct segment_command_64	*sc;
	struct section_64			*s64;

	mh64 = start;
	cur = mh64 + sizeof(*start);
	i = 0;
	while (i < mh64->ncmds)
	{
		lc = (struct load_command *)cur;
		if (lc->cmd == LC_SEGMENT_64)
		{
			sc = (struct segment_command_64 *)cur;
			printf("%s\n", sc->segname);
			printf("%d\n", sc->nsects);
		}
		cur = cur + lc->cmdsize;
		i++;
	}
}
