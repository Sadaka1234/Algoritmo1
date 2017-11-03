#ifndef lab
#define lab

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct Persona{
	int id, fobia;
	}Persona;
	
	
void CrearPersona(Persona * lista, int idd, int fobiaa, int lugar);
void AgregarNodo(char *line, int ** arreglo, int n);
void MayoresFobias(Persona * Personas, int ** arreglo, int * fobias, int n);
void Sort(int ** arreglo, int k, int dimensiones);
int MinofArray(int * array, int largo);
#endif
