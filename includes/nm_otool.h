/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 11:31:06 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/24 09:51:32 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include			<libft.h>
# include			<ft_printf.h>
# include			<fcntl.h>
# include			<sys/stat.h>
# include			<sys/mman.h>
# include			<mach-o/loader.h>
# include			<mach-o/nlist.h>

typedef struct		s_nm
{
	uint64_t		offset;
	char			type;
	char			*str;
	struct s_nm		*next;
}					t_nm;

/*
**					ft_nm.c
*/

void				ft_nm(char *filename, int ac);
void				nm_print(void *start);
void				print_symtab(struct mach_header_64 *addr, void *start);
char				change_type(uint64_t value);

/*
**					setters.c
*/

void				*set_map(char *filename);

/*
**					struct_nm.c
*/

t_nm				**init_nm(uint32_t size);
void				add_to_nm(t_nm **nm, struct nlist_64 *nl, void *start);
void				print_nm(t_nm **nm);
void				sort_nm(t_nm **nm);
t_nm				*nm_swap(t_nm *a, t_nm *b);

#endif
