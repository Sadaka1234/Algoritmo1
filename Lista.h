#ifndef LISTA
#define LISTA

typedef struct nodo {
	void * estructura;
	int numero;
	struct nodo *sig;
	struct nodo *ant;
} tNodo;

typedef struct {
	char nombre[50];
	tNodo *head;
	tNodo *tail;
	tNodo *curr;
	int listSize;
} tLista;

void Start(tLista *); //Lista

void NuevaCabeza(tLista *,void *); //Lista, Eztruct

void NuevoNuevo(tLista *, void *); //Lista, Eztruct

void Siguiente(tLista *); //Lista

void Anterior(tLista *); //Lista

void Matar(tLista *); //Lista

int ListLen(tLista *); 

void * Current(tLista *);

void Head(tLista *);

void * RetornoHead(tLista *);
#endif
