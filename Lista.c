#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Start(tLista *lista){
  lista->head = NULL;
  lista->tail = NULL;
  lista->curr = NULL;
  lista->listSize = 0;
  return ;
}
void Siguiente(tLista *Lista){
	if (Lista->curr->sig == NULL){
		return ;
	}
	Lista->curr = Lista->curr->sig;
	return ;
}
void Anterior(tLista *Lista){
	if (Lista->curr->ant == NULL){	
		return ;
	}
	Lista->curr = Lista->curr->ant;
	return ;
}
void NuevaCabeza(tLista *Lista,void *eztruct){
	tNodo *N_Nodo;
	N_Nodo = malloc(sizeof(tNodo));
	N_Nodo->numero = 0;
	N_Nodo->ant = Lista->head;
	N_Nodo->sig = Lista->tail;
	N_Nodo -> estructura = eztruct;
	Lista->head = N_Nodo;
	Lista->tail = N_Nodo;
	Lista->curr = N_Nodo;
	Lista->listSize++;
	return ;
}
void NuevoNuevo(tLista *Lista, void *eztruct){
	tNodo *Nuevo_Nodo , *aux = Lista->curr;
	int i;
	Nuevo_Nodo = malloc(sizeof(tNodo)); 
	if (Lista->curr->sig == NULL){ //ultima
		Nuevo_Nodo->ant = Lista->tail;
		Nuevo_Nodo->ant->sig = Nuevo_Nodo;
		Nuevo_Nodo->sig = NULL;
		Nuevo_Nodo->numero = Lista->listSize;
		Nuevo_Nodo->estructura = eztruct;
		Lista->tail = Nuevo_Nodo;
		Lista->curr = Nuevo_Nodo;
	}
	else { //cualquiera
		Nuevo_Nodo->ant = Lista->curr;
		Nuevo_Nodo->sig = Lista->curr->sig;
		Nuevo_Nodo->estructura = eztruct;
		Lista->curr->sig = Nuevo_Nodo;
		Lista->curr->sig->ant = Nuevo_Nodo;
		Lista->curr = Nuevo_Nodo;
		for (i=aux->numero; i<=Lista->listSize; i++){
			aux->numero = i;
			aux = aux->sig;
		}
	}
	Lista->listSize++;
	return ;
}
void Matar(tLista *Lista){
	tNodo *aux = Lista->curr;
	
	if (Lista->listSize == 0){
		printf("Error 404: Not Found\n");
		return ;
	}
	
	if ((Lista->curr->sig == NULL)&&(Lista->curr->ant == NULL)){
		Lista->curr= NULL;
		Lista->head= NULL;
		Lista->tail= NULL;		
		}
		
	else if (Lista->curr->sig == NULL){ //ultima
		Lista->curr = Lista->curr->ant;
		Lista->curr->sig = NULL;
		Lista->tail = Lista->curr;
	}
	else if(Lista->curr == Lista->head){ //primera
		Lista->curr->sig->ant = NULL;
		Lista->head =Lista->curr->sig;
	}
	else { //cualquiera
		Lista->curr->sig->ant = Lista->curr->ant;
		Lista->curr->ant->sig = Lista->curr->sig;
		Lista->curr = Lista->curr->ant;
		}
	
	free((void*)aux);
	Lista->listSize--;
	return ;
}
int ListLen(tLista * lista){
	return lista->listSize;
}
void * Current(tLista * lista){
	return lista -> curr -> estructura;
}
void Head(tLista * lista){
	lista -> curr = lista -> head;
	return;
}
void * RetornoHead(tLista * lista){
	return lista -> head;
}

/******** Start ********************
Descripcion: Inicializa la lista

Parametros:
lista: Puntero a tLista, la lista que se va a inicializar

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** Siguiente ********************
Descripcion: Cambia el puntero actual al nodo siguiente

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** Anterior ********************
Descripcion: Cambia el puntero actual al nodo anterior

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** NuevaCabeza ********************
Descripcion: Crea un nodo y lo establece como la cabeza de la lista

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando
eztruct: Puntero a void, la estructura que se ingresa a la lista

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** NuevoNuevo ********************
Descripcion: Crea un nodo a continuacion del actual y lo establece como actual

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando
eztruct: Puntero a void, la estructura que se ingresa a la lista

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** Matar ********************
Descripcion: Elimina el nodo actual

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** ListLen ********************
Descripcion: Entrega el largo de la lista

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: El largo de la lista
************************************************/

/******** Current ********************
Descripcion: Entrega el puntero al nodo actual

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: El puntero al nodo actual
************************************************/

/******** Head ********************
Descripcion: Establece la cabeza de la lista como nodo actual

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: Nada, funcion de tipo 'void'
************************************************/

/******** RetornoHead ********************
Descripcion: Entrega el puntero a la cabeza de la lista

Parametros:
lista: Puntero a tLista, la lista con la cual se esta trabajando

Retorno: El puntero a la cabeza de la lista
************************************************/
