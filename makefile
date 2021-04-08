all: run

matadd: matadd.c
	#gcc order1.c -o order1
	#gcc order2.c -o order2
	#sudo perf stat -e L1-dcache-loads,L1-dcache-load-misses ./order1
	#sudo perf stat -e L1-dcache-loads,L1-dcache-load-misses ./order2
	gcc -Wall -Wextra -Werror -march=core2 matadd.c -o matadd

run: matadd
	./matadd

perf: matadd
	sudo perf stat -e L1-dcache-loads,L1-dcache-load-misses ./matadd

clean:
	rm -f order1 order2
	