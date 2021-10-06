NAME        = so_long

SRCS        = solong.c \
			  graph.c \
			  event.c \
			  texture.c \
			  parsing.c \
			  utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  utils_to_graph.c \
			  print.c \
			  utils_to_parse.c \
			  check_map.c


OBJS		=	$(SRCS:%.c=%.o)

INC_DIR		= include

INC			= $(INC_DIR)/solong.h

LIBFT		= dependency/libft/libft.a

FRAMEWORK	 = -framework OpenGL -framework Appkit

MLX		= dependency/mlx/libmlx.a


CFLAGS		= -g3 -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        lib $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ 


$(NAME) : 	$(MLX) $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(FRAMEWORK) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

lib:		
			make -C dependency/libft
			make -C dependency/mlx

clean:
			rm -f $(OBJS)
			$(MAKE)	-C dependency/libft clean
			$(MAKE)	-C dependency/mlx clean

fclean:		clean
			rm -f $(NAME)

re:            fclean all

.PHONY:       all clean fclean re lib

