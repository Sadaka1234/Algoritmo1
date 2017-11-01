#ifndef lab
#define lab

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Lista.h"

typedef struct Persona{
	int id, fobia;
	tLista comunidad;
	}Persona;
	
	
void CrearPersona(tLista* lista, int idd, int fobiaa);
void AgregarNodo(char *line, tLista *lista);
#endif
