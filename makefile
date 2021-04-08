all: run

matrix: matrix.c
	gcc -Wall -Wextra -Werror -march=core2 -O2 matrix.c -o matrix

run: matrix
	./matrix

perf: matrix
	sudo perf stat -e L1-dcache-loads,L1-dcache-load-misses ./matrix

clean:
	rm -f order1 order2
	