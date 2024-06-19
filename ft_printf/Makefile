NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_printf_c.c\
			ft_printf_s.c\
			ft_printf_p.c\
			ft_printf_d_i.c\
			ft_printf_u.c\
			ft_printf_x_low.c\
			ft_printf_x_up.c\
			ft_printf_percent.c\
			side_functions/ft_strlen.c\
			side_functions/ft_putnbr.c\
			side_functions/ft_putnbr_unsigned.c\
			side_functions/ft_putnbr_hexa.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(AR) rcs $@ $^

clean	:		
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re