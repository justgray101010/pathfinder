NAME = pathfinder

INC = ./inc/libmx.h

HEADTMP = ./libmx.h

SRC = ./main.c \

SRCS = ./src/main.c \

OBJ = ./main.o \

OBJO = ./obj/main.o \
	
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

all: install clean

install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)
	

clean:
	@cd libmx && make -f Makefile clean
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

reinstall: uninstall clean all