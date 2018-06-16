/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:27:39 by ycoutena          #+#    #+#             */
/*   Updated: 2017/10/02 14:45:02 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "limits.h"
# define LD intmax_t
# define ULD uintmax_t

typedef struct s_info	t_info;

typedef struct		s_fct
{
	char			type;
	void			(*fct)(t_info *e, va_list *);
	void			(*fct2)(t_info *e, va_list *, int);
}					t_fct;

struct				s_info
{
	char			*str;
	char			*str_f;
	char			*flag;
	int				width;
	int				precision;
	char			*modif;
	char			type;
	intmax_t		nb;
	int				ret;
	int				neg;
	int				octet[4];
	int				nb_o;
	char			**tab;
	char			**mask;
	int				s_alloc;
	t_fct			fct[15];
};

char				*ft_strjoin_char(char *str, char c);
void				*ft_check_flag(char *str);
char				*ft_check_width(char *str, int i);
char				*ft_check_precision(char *str, int i);
char				*ft_check_modif(char *str);
void				ft_format(char *str, va_list *ap, t_info *e);
void				ft_check(char *str, va_list *ap, t_info *e);
int					ft_size_int(intmax_t nb, t_info *e);
void				ft_type_d(t_info *e, va_list *ap);
void				ft_type_s(t_info *e, va_list *ap);
void				ft_type_c(t_info *e, va_list *ap);
void				ft_type_p(t_info *e, va_list *ap);
void				ft_type_x(t_info *e, va_list *ap);
void				ft_type_o(t_info *e, va_list *ap);
void				ft_type_u(t_info *e, va_list *ap);
void				ft_type_lc_ls(t_info *e, va_list *ap, int j);
char				*ft_itoa_base(intmax_t n, int b);
char				*ft_uitoa_base(uintmax_t n, int b);
void				ft_format_lc(t_info *e);
void				ft_putlc(t_info *e, int size);
void				ft_putnstr(char *str, int i);
void				ft_free(t_info *e);
int					ft_printf(char *str, ...);
void				ft_modif_convert(t_info *e, va_list *ap, LD *x, ULD *y);
int					ft_fill_z(t_info *e, char *str, int i);
int					ft_fill_sp(t_info *e, char *str, int i);
void				ft_check_size_x(t_info *e, int size);
int					ft_check_x(t_info *e, int size, char *n, uintmax_t nb);
int					ft_search_x(t_info *e, int i, char *str);
int					ft_fill_str(t_info *e, char *s, char *s2, int n);
int					ft_fill_z_p(t_info *e, char *s, int n);
char				*ft_check_d_nb_n(t_info *e, char *n, intmax_t nb, int *s);
int					ft_fill_search(char *s, int i, t_info *e);
int					ft_fill_sp_d(t_info *e, char *s, int i);
char				*ft_intochar(intmax_t i, t_info *e);
void				ft_format_d(t_info *e, char *n, intmax_t nb);
int					ft_format_d_next_neg(t_info *e, char **f, char *t, LD n);
void				ft_format_d_next(t_info *e, char **f, char *nb, LD n);
char				**ft_conver_lc(char *t, char *s, int i);
int					ft_btod(char *s, int i);
void				ft_lc_ls(t_info *e, wchar_t val, int j);
int					ft_nbr_wchar_t(wchar_t val);
void				ft_reinit(t_info *e);
t_info				*ft_init();
void				ft_check2(char *s, t_info *e, va_list *ap);
#endif
