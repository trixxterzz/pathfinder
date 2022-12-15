.PHONY = all clean uninstall reinstall
LIB := libmx.a
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,%.o,$(wildcard src/*.c))


all: MINILIBMX
MINILIBMX: allo
	@rm -f $(LIB)
	@mkdir -p obj 
	@mv $(OBJ) ./obj
	@ar -rc $(LIB) $(addprefix ./obj/, $(OBJ)) inc/libmx.h

allo:
	@clang -std=c11 -Wall -Werror -Wextra -Wpedantic -c $(SRC)
clean: 
	@rm -f
uninstall: clean
	@rm -f $(LIB) 
	@rm -drf obj 
reinstall: uninstall MINILIBMX