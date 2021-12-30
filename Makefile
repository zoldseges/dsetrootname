all: dsetrootname

dsetrootname: main.c
	gcc main.c -lX11 -o dsetrootname
install: main.c
	cp dsetrootname /usr/local/bin/dsetrootname


