#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "funciones.h"

void CrearPersona(Persona * lista, int id, int fobia, int lugar){
	Persona persona;
	persona.id = id;						//ID de la persona
	persona.fobia = fobia;					//Fobia de la persona
	lista[lugar] = persona; 
	}

	
	
	
void AgregarNodo(char *line,  int ** arreglo, int n){
	char *search = " ";
	char *desde, *hasta;		//Desde: Nodo actual, Hacia: Relacion con
	//Apunta a la persona
	desde = strtok(line, search);
	//Apunta a la relacion
	hasta = strtok(NULL, search);
	int i, j;
	if (arreglo[0][0] == 0){
		for (i=0; i<n+1; i++){			//El arreglo se llena con ceros si aun no es iniciado
			for (j=0; j<n+1; j++){
				arreglo[i][j] = 0;
				}
			}
		}
	*desde = atoi(desde);
	*hasta = atoi(hasta);

	for (i=0; i<n; i++){			//Se usa el arreglo para ver las comunidades
		for (j=0; j<n; j++){
			
			if (arreglo[i][j] == *desde){
				while(arreglo[i][j] != 0){
					if (arreglo[i][j] == *hasta){
						return ;
						}
					j+=1;
					}
				arreglo[i][j] = *hasta;
				return;
				}
			else if (arreglo[i][j] == *hasta){
				while(arreglo[i][j] != 0){
					if (arreglo[i][j] == *desde){
						return ;
						}
					j+=1;
					}
				arreglo[i][j] = *desde;
				return;
				}
			else if (arreglo[i][j] == 0 && j != 0){
				if (arreglo[i+1][0] == 0){
					arreglo[i+1][0] = *hasta;
					arreglo[i+1][1] = *desde;
					return;
					}
				}
			else if (arreglo[i][j] == 0){
				arreglo[i][j] = *hasta;
				arreglo[i][j+1] = *desde;
				return;
				}
			}
		}
			
	}
	
void MayoresFobias(Persona * Personas, int ** arreglo, int * fobias, int n){
	int * mejores;
	int i, j,k, aux, mejor;
	mejores = malloc(n * sizeof(*mejores));
	
	for (i = 0; i < n; i++){
		mejores[i] = 0;
		}
		
	for (i = 0; i<n; i++){
		for (j = 0; j < n; j++){
			aux = arreglo[i][j] - 1;
			aux = Personas[aux].fobia;
			mejores[aux]+=1;
			}
		mejor = 0;
		for (k=0; k<n; k++){
			if (mejores[k] > mejor){
				fobias[i] = k;
				mejor = mejores[k];
				}
			}
		for (k = 0; k < n; k++){
			mejores[i] = 0;
			}
		}
	free(mejores);
	}
	
		
int MinOfArray(int * array, int largo){
    int minimo = array[0];
    for (int i=1; i<largo ; i++){
        if (array[i] < minimo && array[i] != 0){
           minimo = array[i];
        }
    } 
	return minimo;
	}



void Sort(int ** arreglo, int k, int dimensiones){
	int * orden;
	orden = malloc(k * sizeof(*orden));
	int temp;
	for(int i=0;i<k;i++){
		orden[i] = MinOfArray(arreglo[i], dimensiones);
		}
	for (int m = 0; m< k; m++){
		for (int i=0; i<k ; i++){
			if (orden[i] > orden[i+1]){
				for (int j = 0; j<dimensiones; j++){
					temp = arreglo[i][j];
					arreglo[i][j] = arreglo[i+1][j];
					arreglo[i+1][j] = temp; 	
					}
				temp = orden[i];
				orden[i] = orden[i+1];
				orden[i+1] = temp;
			}
		} 
	}
}
		
	
	
	
	
