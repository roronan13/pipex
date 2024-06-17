NAME		=	pipex

SRCS		=	pipex.c\
				pipex_2.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -rf

MAKE_LIBFT	= $(MAKE) -C ./libft

LIBFT		= ./libft/libft.a

INCLUDE		= -I ./

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

all			:	$(NAME)

$(LIBFT)	:
				$(MAKE_LIBFT)

$(NAME)		:	$(OBJS) | $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean		:	
				$(RM) $(OBJS)
				$(MAKE_LIBFT) clean

fclean		:	clean
				$(RM) $(NAME)
				$(MAKE_LIBFT) fclean

re			:	fclean
				make fclean -C libft
				make -C libft
				make
				make clean -C libft
				make clean

.PHONY		:	all clean fclean re