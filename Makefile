NAME		=	pipex

SRCS		=	pipex.c

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

re			:	$(MAKE_LIBFT) fclean
				make fclean 
				make

.PHONY		:	all clean fclean re