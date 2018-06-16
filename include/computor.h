#ifndef COMPUTOR_H
#define COMPUTOR_H

#include "../ft_printf/includes/ft_printf.h"

typedef struct			p_list
{
	int					nb;
	double				nb2;
	int					pow;
	int					pos;
	int					signe;
	int					e;
	struct p_list		*next;
}						k_list;

typedef struct			p_info
{
	int					nb;
	double				nb2;
	int					pow;
	int					pos;
	int					signe;
	int					e;
	int					bl;
	int					passe;
}						k_info;

#endif
