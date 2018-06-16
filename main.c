#include "./include/computor.h"
#include <stdio.h>

int		ft_isoperation(char op, int s)
{
	if (s == 0 && (op == '+' || op == '-' || op == '*' || op =='/'))
		return (1);
	else if (s == 1 && (op == '+' || op == '-'))
		return (1);
	else
		return (0);
}

int		ft_charspec(char c)
{
	if (c == '.' || c == '^' || c == '=' || ft_isspace(c) || c == 'X')
		return (1);
	return (0);
}

void	ft_prin(k_list *lst)
{
	while (lst)
	{
		ft_printf("( nb ");
		ft_putdouble(lst->nb2, lst->e);
		ft_printf("*X^ %d ) ", lst->pow);
		lst = lst->next;
	}
	ft_putchar(' ');
}

int		ft_check_egal(char *str)
{
	int	i;
	int	length;

	length = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (i == length)
		return (-1);
	if (str[i] == '=')
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		if (str[i] && ft_isdigit(str[i]))
			return (i);
	}
	return (-1);
}

int		ft_charautorise(char *str)
{

	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isoperation(str[i], 0) || ft_charspec(str[i]) || ft_isdigit(str[i]))
			i++;
		else
			return (-1);
	}
	i = ft_check_egal(str);
	return (i);
}

char	*ft_delspace(char *equation)
{

	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(equation);
	while (equation[i] && ft_isspace(equation[i]))
		i++;
	j--;
	while (j > 0 && ft_isspace(equation[j]))
		j--;
	j++;
	str = ft_strsub(equation, i, j - i);
	return (str);
}

int		ft_getsigne(char *str, char c, int *i, int pos)
{
	int s;

	if ((*i == 0  || pos == 1) && ft_isdigit(c))
	{
		s = 1;
	}
	else if (c == '+')
	{
		while (str[*i] && !ft_isdigit(str[*i]))
			*i = *i + 1;
		s = 1;
	}
	else if (c == '-')
	{
		while (str[*i] && !ft_isdigit(str[*i]))
			*i = *i + 1;
		s = 0;
	}
	else
		s = -1;
	return (s);
}

int		ft_typenum(char *str, int i)
{
	int	j;

	j = 0;
	if (str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '.')
		i++;
	if (str[i] == ' ' || str[i] == '\0')
		return (0);
	else if (str[i++] == '.')
	{
		while (str[i] && ft_isdigit(str[i]))
		{
			i++;
			j++;
		}
		return (j);
	}
	else
		return (-1);
}

int		ft_checkpow(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == ' ' || str[*i] == '=' || str[*i] == '\0')
		return (1);
	else
		return (-1);
}

int		ft_getpowformat(char *str, int *i, int pow)
{
	if (str[*i] && (str[*i] == '+' || str[*i] == '-' || str[*i] == '='))
		{
			*i = *i - 1;
			return (0);
		}
	if (str[*i] && str[*i] == '*' && str[*i + 1] == ' '\
	&& ft_toupper(str[*i + 2]) == 'X')
	{
		*i = *i + 2;
		if (str[*i + 1] == '+' || str[*i + 1] == '-' || str[*i + 1] == '='\
			|| str[*i + 1] == ' ')
		{
			*i = *i + 1;
			return (1);
		}
		if (str[*i] && str[*i + 1] == '^' && ft_isdigit(str[*i + 2]))
		{
			*i = *i + 2;
			pow = ft_atoi(&str[*i]);
			pow = (ft_checkpow(str, i) != -1) ? pow : -1;
			return (pow);
		}
	}
	return (-1);
}

int		ft_getpow(char *str, int *i)
{
	int	pow;

	if (str[*i] == ' ')
	{
		*i = *i + 1;
		return (ft_getpowformat(str, i, 0));
	}
	if (ft_toupper(str[*i]) == 'X')
	{
		*i = *i + 1;
		if (str[*i] == '^')
		{
			*i = *i + 1;
			if (ft_isdigit(str[*i]))
			{
				pow = ft_atoi(&str[*i]);
				pow = (ft_checkpow(str, i) != -1) ? pow : -1;
				return (pow);
			}
			else
				return (-1);
		}
		return (1);
	}
	return (0);
}

k_list	*ft_newlst(k_info e)
{
	k_list *lst;
	int		s;

	lst = (k_list *)malloc(sizeof(k_list));
	if (lst)
	{
		s = e.signe;
		lst->pow = e.pow;
		lst->pos = e.pos;
		lst->signe = s;
		lst->e = e.e;
		if (s == 1)
			lst->nb2 = e.nb2;
		else if (s == 0)
			lst->nb2 = -e.nb2;
		else
			lst->nb2 = 0;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}

void	ft_addlst(k_list **begin, k_info e)
{
	k_list *tmp;
	k_list *lst;

	tmp = *begin;
	lst = ft_newlst(e);
	if (lst)
	{
		if (!*begin)
		{
			*begin = lst;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = lst;
		}
	}
}

int		ft_getinfo(k_list **begin, k_info e,  char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			e.pos = 1;
			i++;
			(str[i] == ' ') ? i++ : 1;
		}
		e.signe = ft_getsigne(str, str[i], &i, e.pos);
		e.e = ft_typenum(str, i);
		e.nb2 = ft_atof(&str[i]);
		while (str[i] && str[i] != ' ' && (ft_isdigit(str[i]) || str[i] == '.'))
			i++;
		e.pow = ft_getpow(str, &i);
		(e.pow == -1) ? ft_printf("erreur pow %d \n", e.pow): 1 ;
		if (e.pow == -1)
			return (-1);
		(str[i] == '=') ? i-- : 1;
		ft_addlst(begin, e);
		i++;
	}
	return (1);
}

char	*ft_reduce(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != 'a')
		i++;
	if (i == 0)
		return (str);
	new = ft_strsub(str, 0, i);
	free(str);
	return (new);
}

char	*ft_delallspace(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new = ft_strdup(str);
	while (str[i])
	{
		if (str[i + 1] && str[i] == 32 && str[i + 1] == 32)
			while (str[i + 1] == 32)
				i++;
		new[j] = str[i];
		j++;
		i++;
	}
	while (new[j])
	{
		new[j] = 'a';
		j++;
	}
	new = ft_reduce(new);
	return (new);
}

k_info	ft_init_info()
{
	k_info e;

	e.nb = 0;
	e.nb2 = 0;
	e.pow = 0;
	e.pos = 0;
	e.signe = 0;
	e.e = 0;
	e.bl = 0;
	return (e);
}

void	ft_freelst(k_list *lst)
{
	k_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}


k_list	*ft_newpoly(k_info info, int i)
{
	k_list *lst;

	lst = (k_list *)malloc(sizeof(k_list));
	if (lst)
	{
		lst->pow = i;
		lst->nb2 = info.nb2;
		lst->pos = 0;
		lst->e = info.e;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}

void	ft_addpoly(k_list **begin, k_info info, int i)
{
	k_list *lst;
	k_list *tmp;

	tmp = *begin;
	lst = ft_newpoly(info, i);
	if (lst)
	{
		if (!*begin)
			*begin = lst;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = lst;
		}
	}
}

k_info	ft_reduce_next(k_list *lst, k_info info, int i)
{
	while (lst)
	{
		if (lst->pow == i)
		{
			info.passe = 1;
			if (lst->e > info.e)
				info.e = lst->e;
			if (info.bl == 0)
			{
				if (lst->pos == 0)
					info.nb2 = lst->nb2;
				else
					info.nb2 = -lst->nb2;
				info.bl = 1;
			}
			else if (lst->pos == 0)
				info.nb2 += lst->nb2;
			else
				info.nb2 -= lst->nb2;
		}
		lst = lst->next;
	}
	return (info);
}

int		ft_lenpoly(k_list **poly)
{
	int		i;
	k_list	*tmp;

	i = 0;
	tmp = *poly;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_check_poly(k_list **poly)
{
	int		i;
	k_info	info;

	i = ft_lenpoly(poly);
	if (i < 3)
	{
		while (i < 3)
		{
			info = ft_init_info();
			ft_addpoly(poly, info, i);
			i++;
		}
	}
}

int		ft_get_high_pow(k_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->pow > i)
			i = lst->pow;
		lst = lst->next;
	}
	return (i);
}

void	ft_form_reduit(k_list **poly, k_list *lst)
{
	k_info	info;
	k_list	*tmp;
	k_list	*tmp2;
	int		i;

	i = 0;
	tmp = lst;
	tmp2 = lst;
	info = ft_init_info();
	i = ft_get_high_pow(lst);
	while (i >= 0)
	{
		lst = tmp;
		info = ft_reduce_next(lst, info, i);
		if (info.passe == 1)
		{
			//printf("info %f, pow %d \n ", info.nb2, i);
			ft_addpoly(poly, info, i);
			info = ft_init_info();
		}
		i--;
	}
	ft_check_poly(poly);
}

int		ft_check_degree(k_list *lst, int i)
{
	i = 0;

	while (lst)
	{
		if (lst->nb2 != 0 && lst->pow > i)
			i = lst->pow;
		lst = lst->next;
	}
	ft_printf("= 0 \nPolynomial degree : %d\n", i);
	if (i > 2)
	{
		ft_printf("The polynomial degree is stricly greater than 2, "\
		"I can't solve.");
		return (-1);
	}
	if (i == 0)
	{
		ft_printf("Pas de solution");
		return (-1);
	}
	return (1);
}

int	ft_print_reduce(k_list *poly, int i)
{
	double	nb;
	k_list	*tmp;

	tmp = poly;
	ft_printf("Reduced form : ");
	while (poly)
	{
		if (poly->nb2 != 0)
		{
			(i != 0 && poly->nb2 > 0) ? ft_putstr("+ "): 1;
			if (poly->nb2 < 0)
			{
				nb = -poly->nb2;
				ft_putstr("- ");
				ft_putdouble(nb, poly->e);
			}
			else
				ft_putdouble(poly->nb2, poly->e);
			ft_printf(" * X^%d ", poly->pow);
			i++;
		}
		poly = poly->next;
	}
	return (ft_check_degree(tmp, i));
}

void	ft_simple_solution(double res, double c, double b)
{
	if (c != 0 )
	{
		res = -c / b;
		ft_printf("The solution is :\n");
		ft_putdouble(res, 2);
	}
	else
	{
		res = -b;
		ft_printf("The solution is :\n");
		ft_putdouble(res, 2);
	}
}

void	ft_positive_solution(double res, double a, double b)
{
	double	solution1;
	double	solution2;

	solution1 = (-b - ft_sqrt(res)) / (2 * a);
	solution2 = (-b + ft_sqrt(res)) / (2 * a);
	ft_printf("Discriminant is strictly positive,"\
	" the two solutions are:\n");
	ft_putdouble(solution1, 6);
	ft_putendl("");
	ft_putdouble(solution2, 6);
}

void	ft_unique_solution(double b, double a)
{
	double	solution;

	solution = -b / (2 * a);
	ft_printf("Discriminant has one solution :\n");
	ft_putdouble(solution, 2);
}

void	ft_solution_complexe(double res, double b, double a)
{
	double	solution1;
	double	solution2;

	ft_printf("Discriminant is negative, "\
	" the two complex solutions are:\n");
	solution1 = (-b / 2 * a );
	solution2 = (ft_sqrt(-res) / 2 * a );
	ft_putdouble(solution1, 2);
	ft_printf(" - i*");
	ft_putdouble(solution2, 2);
	ft_putendl("");
	ft_putdouble(solution1, 2);
	ft_printf(" + i*");
	ft_putdouble(solution2, 2);
}

void	ft_pas_de_solution(void)
{
	ft_printf("pas de solution");
}

double	ft_get_poly_nb_by_pow(k_list *poly, int p)
{
	double	nb;

	nb = 0;
	while (poly)
	{
		if (poly->pow == p)
			return (poly->nb2);
		poly = poly->next;
	}
	return (nb);
}

void	ft_discriminant(k_list *poly)
{
	double	a;
	double	b;
	double	c;
	double	res;
	
	c = ft_get_poly_nb_by_pow(poly, 0);
	b = ft_get_poly_nb_by_pow(poly, 1);
	a = ft_get_poly_nb_by_pow(poly, 2);
	res = (b * b) - 4 * (a * c);
	if (a != 0)
	{
		if (res > 0)
			ft_positive_solution(res,a,b);
		else if (res == 0)
			ft_unique_solution(b,a);
		else
			ft_solution_complexe(res, b, a);
	}
	else if (a == 0 && b == 0)
		ft_pas_de_solution();
	else
		ft_simple_solution(res,c,b);
}

void	ft_reverspoly(k_list **begin)
{
	k_list *tmp;
	k_list *prev;
	k_list *suiv;

	tmp = *begin;
	prev = NULL;
	while (tmp)
	{
		suiv = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = suiv;
	}
	*begin = prev;
}

void	ft_resolve(k_list *lst)
{
	k_list	*poly;
	int		bl;

	bl = 1;
	poly = NULL;
	ft_form_reduit(&poly, lst);
	ft_reverspoly(&poly);
	bl = ft_print_reduce(poly, 0);
	if (bl != -1)
		ft_discriminant(poly);
	ft_freelst(poly);
}

void	ft_computor(char *equation)
{
	char	*str;
	int		i;
	k_list	*lst;
	k_list	*lst2;
	k_info	info;

	lst = NULL;
	info = ft_init_info();
	i = 20;
	str = ft_delspace(equation);
	str = ft_delallspace(str);
	if (ft_charautorise(str) != -1)
	{
		if (ft_getinfo(&lst, info, str) == 1)
		{
			ft_resolve(lst);
			ft_freelst(lst);
		}
		free(str);
	}
	else
	{
		ft_printf("erreur charactere sepcial ");
		free(str);
	}
}

int main (int ac, char **av)
{
	if (ac <= 1)
		ft_printf("erreur : enter a valid polynome ");
	else if (ac == 2)
		ft_computor(av[1]);
	else if (ac >= 3)
		ft_printf("erreur : enter polynome between \" ");
	else
		ft_printf("erreur unknown ");
	ft_putendl("");
	return (0);
}
