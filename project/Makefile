matrix_pattern: common.o snakes.o spirals.o matrices.o
	gcc -Wall -Werror -Wextra common.o snakes.o spirals.o matrices.o -o matrix_pattern

matrices.o: matrices.c
	gcc -Wall -Werror -Wextra -c matrices.c -o matrices.o

snakes.o: snakes.c
	gcc -Wall -Werror -Wextra -c snakes.c -o snakes.o

spirals.o: spirals.c
	gcc -Wall -Werror -Wextra -c spirals.c -o spirals.o

common.o: common.c
	gcc -Wall -Werror -Wextra -c common.c -o common.o

.PHONY:rebuild clean all
 
rebuild:clean all

clean:
	rm -rf *.o matrix_pattern

all: matrix_pattern