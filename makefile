NAME = fdf

CFILES = src/cleaning.c \
		 src/draw.c \
		 src/draw2.c \
		 src/key_hooks.c \
		 src/main.c \
		 src/parsing.c

LIBS = libftprintf.a \
	   libmlx.a 

FRAMEWORKS = -framework OpenGL -framework AppKit

HEADERS = inc

all: $(CFILES) $(LIBS)
	@gcc -Wall -Wextra -Werror -o $(NAME) -I $(HEADERS) $(FRAMEWORKS) $(LIBS) $(CFILES)

clean :
	rm -f minilibx_macos/*.o

fclean : clean
	rm -f fdf

re : fclean all
