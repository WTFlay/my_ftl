CC		=	gcc
SRC		=	$(wildcard src/*.c)
OBJ		=	$(patsubst src/%.c,obj/%.o,$(SRC))
CFLAGS	=	-W -Wall -Werror -pedantic -Wextra -std=gnu11
CFLAGS	+=	$(shell sdl2-config --cflags)
LDFLAGS =   $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf
EXEC	=	my_ftl
LIB		=	libmy.a
LIB_SRC	=	$(wildcard mylib/src/*.c)
LIB_OBJ	=	$(patsubst mylib/src/%.c,mylib/obj/%.o,$(LIB_SRC))

all		:	$(EXEC)

$(EXEC)	:	$(OBJ) $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIB)	:	$(LIB_OBJ)
	ar rcs $@ $^

mylib/obj/%.o	:	mylib/src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

obj/%.o	:	src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean	:
	rm -rf $(OBJ) $(LIB_OBJ)

fclean	:	clean
	rm -rf $(EXEC) $(LIB)

re		:	fclean all

.PHONY	:		clean fclean re
