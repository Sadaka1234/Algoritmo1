primer:
	gcc -c main.c funciones.c Lista.c -Wall
	gcc main.o funciones.o Lista.o -o ejecutar
	./ejecutar
