NAME		=	pipex

SRCS		=	pipex.c\
				pipex_2.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -rf

MAKE_LIBFT	= $(MAKE) -C ./libft

LIBFT		= ./libft/libft.a

MAKE_FT_PRINTF	= $(MAKE) -C ./ft_printf

FT_PRINTF	= ./ft_printf/libftprintf.a

INCLUDE		= -I ./

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

all			:	$(NAME)

$(LIBFT)	:
				$(MAKE_LIBFT)

$(FT_PRINTF)	:	
					$(MAKE_FT_PRINTF)

$(NAME)		:	$(OBJS) | $(LIBFT) $(FT_PRINTF)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

clean		:	
				$(RM) $(OBJS)
				$(MAKE_LIBFT) clean
				$(MAKE_FT_PRINTF) clean

fclean		:	clean
				$(RM) $(NAME)
				$(MAKE_LIBFT) fclean
				$(MAKE_FT_PRINTF) fclean

re			:	fclean
				make fclean -C libft
				make fclean -C ft_printf
				make -C libft
				make -C ft_printf
				make

.PHONY		:	all clean fclean re