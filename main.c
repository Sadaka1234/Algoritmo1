#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "funciones.h"
#include "Lista.h"

int main(){
	FILE *fp;
    char line[20];  				/*Almacenador de lineas */
    int cant;       			    /* Cantidad de personas*/
    int i;
    fp = fopen("test.txt", "r");
    tLista * ListaGente;            //Lista de personas
    ListaGente = malloc(sizeof(tLista));
    Start(ListaGente);
    
	fgets(line, 255, (FILE*)fp);
    cant = atoi(line);  			//Cuantas personas hay, CREA PERSONAS
	for (i = 0; i < cant; i++){		//FOBIAS
		fgets(line, 255, (FILE*)fp);
		CrearPersona(ListaGente, i+1, atoi(line));
		}
	
	fgets(line, 255, (FILE*)fp);
    cant = atoi(line);  			//Cuantas personas hay, CREA RELACIONES
	for (i = 0; i < cant; i++){		//RELACIONES
		fgets(line, 255, (FILE*)fp);
		AgregarNodo(line, ListaGente);
		}
	Head(ListaGente);
	Persona * person = Current(ListaGente);
	tLista * listoco = Current(&(person->comunidad));
	tNodo * nodito = listoco->curr;
	Persona * personita = nodito->estructura;
	printf("%d", personita->id);
	}
