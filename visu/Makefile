CC		=	gcc -Iincludes

CFLAGS		+=	-W -Wextra -Wall -ansi -pedantic

RM		=	rm -f

SRC		=	src/main.c				\
			src/gnl.c				\
			src/animation.c				\
			src/ants.c				\
			src/draw2.c				\
			src/draw.c				\
			src/parse.c				\
			src/pipe.c				\
			src/sort.c				\
			src/write_f.c				\

OBJ		=	$(SRC:.c=.o)

NOM		=	visu_hex

all:		visu

visu:		$(OBJ)
		@echo -e "\n > COMPILATION DES .C VISU-HEX EN COURS\n"
		$(CC) -o $(NOM) $(OBJ) -lSDL_gfx -lSDL -lGL -lGLU -lSDL_image -lSDLmain -lSDL_ttf -g3
		@echo -e "\n > COMPILATION DES .C VISU-HEX TERMINEE"
		# @cat ../makefile_deco/girl2

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		@echo -e "\t->>> SUPPRESSION DE L'EXECUTABLE ET DE LA LIB <<<-"
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
