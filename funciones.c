#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Lista.h"
#include "funciones.h"

void CrearPersona(tLista* lista, int id, int fobia){
	Persona * persona;
	persona = malloc(sizeof(Persona));
	persona->id = id;						//ID de la persona
	persona->fobia = fobia;					//Fobia de la persona
	tLista * Haciadonde;
    Haciadonde = malloc(sizeof(tLista));
    Start(Haciadonde);
	persona->comunidad = *Haciadonde; 		//Lista que contiene los nodos adyacentes
	
	if (ListLen(lista)== 0){
		NuevaCabeza(lista, persona);
		}
	else {
		NuevoNuevo(lista, persona);
		}	
	}
	
	
	
void AgregarNodo(char *line, tLista *lista){
	char *search = " ";
	char *desde, *hasta;		//Desde: Nodo actual, Hacia: Relacion con
	tLista * Siguientes;
	Siguientes = malloc(sizeof(tLista));
	Siguientes = lista;
	
	int cant = lista->listSize;			//Largo de personas
	
	
	
	//Apunta a la persona
	desde = strtok(line, search);
	//Apunta a la relacion
	hasta = strtok(NULL, search);
	Head(lista);
	
	
	for (int i = 0; i < cant; i++){
		Persona * actual = lista->curr->estructura;	//Desde
		if (actual->id == (int)desde){
			Head(Siguientes);
			for (int j = 0; j < cant; j++){			
				Persona * siguiente = lista->curr->estructura;	//Hasta
				if (siguiente->id == (int)hasta){	
					if (ListLen(lista)== 0){
						NuevaCabeza(&(actual->comunidad), siguiente);
						}
					else {
						NuevoNuevo(&(actual->comunidad) , siguiente);
						}	
					}	
					Siguiente(Siguientes);		
				}
			}
		Siguiente(lista);
		}
	}
		
	
		
	
		
	
	
	
	
