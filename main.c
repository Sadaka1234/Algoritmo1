#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "funciones.h"


int main(){
    char line[200];  				/*Almacenador de lineas */
    int cant;       			    /* Cantidad de personas*/
    int i;
    //---------------------------------------------------------------------Creacion Lista Personas
    fgets(line, sizeof(char)*200, stdin);
    Persona * ListaGente;            //Lista de personas
    cant = atoi(line);  			//Cuantas personas hay, CREA PERSONAS
    int lugar = 0;
    ListaGente = malloc(cant * sizeof(Persona));
    int n = cant;					//Respaldo cantidad de personas
	for (i = 0; i < cant; i++){		//SE ASIGNAN LAS FOBIAS
		fgets(line, sizeof(char)*200, stdin); 
		CrearPersona(ListaGente, i+1, atoi(line), lugar);
		lugar += 1;
		}
	//----------------------------------------------------------------------Creacion arreglos comunidades
	
	int ** arreglo;					//Arreglo con comunidades 
	arreglo = malloc((cant+1) * sizeof(*arreglo));
	for (i=0; i<(cant+1); i++){
			arreglo[i] = malloc((cant+1)* sizeof *arreglo[i]);
			}
	arreglo[0][0] = 0;					
	fgets(line, sizeof(char)*200, stdin); 
    cant = atoi(line);  			//Cuantas relaciones hay
	for (i = 0; i < cant; i++){		//RELACIONES
		fgets(line, sizeof(char)*200, stdin); 
		AgregarNodo(line, arreglo, cant);
		}
	//----------------------------------------------------------------------Manejo comunidades	
	int k = 0;	  					//Numero comunidades
	while(arreglo[k][0] != 0){
		k+=1;
		}
	int * fobias;					//Mejores Fobias
	fobias = malloc(cant * sizeof(*fobias));
	
	Sort(arreglo, k, cant+1);				//Para entregar las comunidades en orden
		
	MayoresFobias(ListaGente ,arreglo, fobias, n);
	fprintf(stdout, "%d\n", k);
	for (i=0; i<k;i++){	
		fprintf(stdout, "%d\n", fobias[i]);
		}
	

	/*for (i=0; i<cant+1; i++){		//descomentar en caso de querer ver la matriz
		for (int j=0; j<cant+1; j++){
			printf("%d ", arreglo[i][j]);
			}
		printf("\n");
		}*/
	free(ListaGente);
	free(arreglo);
	}
