/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:52:40 by amarquet          #+#    #+#             */
/*   Updated: 2014/04/24 09:53:12 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define VALID_FORMATS "%Xcdiopsux"
# define NUM_FORMATS 10
# define VALID_FLAGS " #*+-.0123456789"
# define NUM_FLAGS 16

typedef struct		s_printf
{
	int				index;
	int				count;
	const char		*fmt;
	va_list			ap;
	void			(*f)(struct s_printf *);
	void			**ftab;
	char			format;
	int				alternate;
	int				left_adjust;
	int				sign;
	int				space;
	int				zero_pad;
	int				width;
	int				is_precision;
	int				precision;
}					t_printf;

int					ft_printf(const char *fmt, ...);
int					ft_specifier(t_printf *params);
void				ft_reset_params(t_printf *params);
int					ft_parse_specifier(t_printf *params);

int					ft_get_width(t_printf *params);
void				ft_get_star(t_printf *params);
void				ft_left_adjust(t_printf *params, int strlen);
void				ft_right_adjust(t_printf *params, int strlen);
void				ft_zero_pad(t_printf *params, int strlen);

int					ft_plus_flag(t_printf *params);
int					ft_dash_flag(t_printf *params);
int					ft_dot_flag(t_printf *params);

void				ft_c_fmt(t_printf *params);
void				ft_d_fmt(t_printf *params);
void				ft_o_fmt(t_printf *params);
void				ft_p_fmt(t_printf *params);
void				ft_percent_fmt(t_printf *params);
void				ft_s_fmt(t_printf *params);
void				ft_u_fmt(t_printf *params);
void				ft_x_fmt(t_printf *params);

size_t				ft_strlen(const char *s);
int					ft_toupper(int c);
int					ft_atoi(char const *str);
char				*ft_itoa(long long int n);
char				*ft_otoa(unsigned long long int n);
char				*ft_utoa(unsigned long long int n);
char				*ft_xtoa(unsigned long long int n);

#endif

