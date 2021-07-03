#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

# ifndef CtoI
#  define CtoI(c) ((c) - '0')
# endif

# ifndef MAXBUF
# 	define MAXBUF (sizeof(long int) * 8)
# endif

typedef struct s_print
{
	va_list	arg;
	char	padc;
	char	sign_char;
	int		length;
	int		prec;
	int		ladjust;
	int		altfmt; //need to correct
	int		tranc; //DO WE NEED THIS?
	int		base;
	int		capitals;
	int 	ret;
}    t_print;

int			ft_printf(const char *format, ...);
void		ft_initialise_tab(t_print *tab);
int			ft_eval_format(t_print *tab, register const char *format, va_list *argp);
int			ft_conv_proc(t_print *tab, register const char *format, va_list *argp);
int			ft_printf_str(t_print *tab, register char *p);
int			ft_printf_signed(t_print *tab, va_list *argp);
int			ft_printf_usigned(t_print *tab, va_list *argp);
int			ft_printf_num(t_print *tab, unsigned long u);
int			ft_print_zero(t_print *tab);
int			ft_print_nullterm(t_print *tab);
int			ft_printf_before_num(t_print *tab);
int			ft_printf_before_num_sub(t_print *tab);
int			ft_printf_after_num(t_print *tab);
t_print		*ft_len_prec_count(t_print *tab, int a);
int			ft_printf_after_str(t_print *tab, long	n);
int			ft_printf_before_str(t_print *tab, register char *p);
int			ft_num_conv(t_print *tab, register char	c, va_list *argp);
int			ft_str_conv(t_print *tab, va_list *argp);
const char	*ft_ladj_padc(t_print **tab, register const char *format);
const char	*ft_len(t_print **tab, register const char *format, va_list *argp);
const char	*ft_prec(t_print **tab, register const char *format, va_list *argp);

#endif