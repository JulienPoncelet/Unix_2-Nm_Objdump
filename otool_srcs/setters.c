/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 10:37:20 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/24 10:38:47 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void						*set_map(char *filename)
{
	int						fd;
	struct stat				stat_buf;
	size_t					size;
	void					*map;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_printf("ft_otool: can't open file: %s\n", filename);
		return (NULL);
	}
	if (fstat(fd, &stat_buf) == -1)
	{
		ft_printf("ft_otool: can't fstat file: %s\n", filename);
		return (NULL);
	}
	size = stat_buf.st_size;
	map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED)
	{
		ft_printf("ft_otool: can't map file: %s\n", filename);
		return (NULL);
	}
	return (map);
}
