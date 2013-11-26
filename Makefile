prog: prog.c Makefile
	$(CC) prog.c -o prog -ggdb `sdl-config --libs --cflags`
