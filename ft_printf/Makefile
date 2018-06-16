# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 08:44:56 by ycoutena          #+#    #+#              #
#    Updated: 2017/10/02 14:11:06 by ycoutena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c			\
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c			\
			ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c			\
			ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c			\
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c			\
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c			\
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c			\
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c				\
			ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c		\
			ft_lstadd.c	ft_lstiter.c ft_lstmap.c ft_strtoupper.c		\
			ft_strtolower.c ft_debug.c ft_strrev.c ft_power.c			\
			ft_list_clear.c ft_list_foreach.c ft_list_last.c			\
			ft_list_size.c ft_print_list.c ft_isspace.c ft_convert.c	\
			ft_check.c ft_itoa_base.c ft_printf.c ft_type_d.c 			\
			ft_type_o.c ft_type_p.c ft_type_s_c.c ft_type_u.c			\
			ft_type_x.c ft_putnstr.c ft_type_lc.c ft_cleanjoin.c		\
			ft_check_next.c ft_fill.c ft_config_x.c ft_config_c.c		\
			ft_config_d.c ft_modif_d.c ft_config_lc.c ft_convert_c.c	\
			ft_init_e.c ft_affine.c ft_atof.c ft_putdouble.c			\
			ft_putdouble_fd.c ft_putdouble_test_fd.c ft_sqrt.c

ICD		=	libft.h
ICDP	=	ft_printf.h

OBJS	=	$(SRCS:.c=.o)

DIROBJ	=	obj

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes/

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:
			@$(CC) $(CFLAGS) -c $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@mkdir $(DIROBJ)
			@mv *.o $(DIROBJ)
clean	:
			@$(RM) $(DIROBJ)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY: clean fclean re
