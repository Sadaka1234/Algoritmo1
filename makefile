primer:
	gcc -c main.c funciones.c -Wall
	gcc main.o funciones.o -o ejecutar
	./ejecutar < input-1.dat
