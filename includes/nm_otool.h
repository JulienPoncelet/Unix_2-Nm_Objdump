/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 11:31:06 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/23 15:50:20 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

#include <stdio.h>

# include		<libft.h>
# include		<ft_printf.h>
# include		<fcntl.h>
# include		<sys/stat.h>
# include		<sys/mman.h>
# include		<mach-o/loader.h>
# include		<mach-o/nlist.h>

typedef struct	s_nm
{
	uint64_t	offset;
	char		type;
	char		*str;
}				t_nm;

/*
**				ft_nm.c
*/

void			ft_nm(char *filename, int ac);
void			nm_print(void *start);
void			print_symtab(struct mach_header_64 *addr, void *start);
char			change_type(uint64_t value);

/*
**				setters.c
*/

void			*set_map(char *filename);

#endif
