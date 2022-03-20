CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -O3 # -S -g

make: MemComBarriers

MemComBarriers: MemComBarriers.c
	$(CC) -o MemComBarriers MemComBarriers.c $(CFLAGS)