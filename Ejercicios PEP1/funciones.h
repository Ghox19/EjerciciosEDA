
#include <stdio.h>
#include <stdlib.h>

/* ESTRUCTURA DE DATOS  del TDA lista  */
struct nodo{
  int valor;
  struct nodo *sig;
};
typedef struct nodo Nodo;

struct lista{
  Nodo *head;
  int n; //Número de nodos agregados a la lista
};
typedef struct lista Lista;


/* Encabezados de las operaciones programadas*/

Lista *crear_lista();
int is_lista_vacia(Lista *L3);
Nodo *crear_nodo(int val);
void insertar_nodo_ini(Lista *L3, int val); 
void insertar_nodo_fin(Lista *L3, int val);
void mostrar_lista(Lista *L3);
int  eliminar_nodo_ini(Lista *L3);
int  eliminar_nodo_fin(Lista *L3);
void eliminar_nodo(Lista *L3, int valE); /* eliminar para valor dado*/
Nodo *buscar_Nodo(Lista *L3, int val); /* retorna la dirección del nodo */


/* PROGRAMACIÓN OPERACIONES SOLICITADAS EN ACTIVIDAD 2 LAB 
   Programe aquí las operaciones solicitadas */






/* Programación de las Operaciones ELEMENTALES
  IMPORTANTE: No modifique nada de aquí en adelante */

Lista *crear_lista(){
	Lista *L3 = (Lista*)malloc(sizeof(Lista));
    L3->head = NULL;
    L3->n = 0;
	return L3;
}

int is_lista_vacia(Lista *L3){
	if(L3->head == NULL)
		return 1; /*lista vacía retorna un 1*/
	else
		return 0;
}

Nodo *crear_nodo(int val){
	Nodo *new_nodo;
	new_nodo = (Nodo*)malloc(sizeof(Nodo));
	new_nodo->valor = val;
  new_nodo->sig = NULL;	
  return new_nodo;
}


void insertar_nodo_ini(Lista *L3, int val){
	Nodo *new_nodo;
	new_nodo = crear_nodo(val);
	if (!(is_lista_vacia(L3))){ 
			new_nodo->sig = L3->head;
	}
	L3->head = new_nodo;
	L3->n = L3->n + 1;  /* aumenta el número de nodos de la lista L */
}

void insertar_nodo_fin(Lista *L3, int val){
	Nodo *aux, *new_nodo;
	aux = L3->head;
	while(aux->sig !=NULL){
		aux = aux->sig;
	}
	new_nodo = crear_nodo(val);
	aux->sig = new_nodo;
	L3->n = L3->n + 1;  /* aumenta el número de nodos de la lista L */
}

void mostrar_lista(Lista *L3){
	Nodo *aux;
	if (!(is_lista_vacia(L3))){ 
	    aux = L3->head;
			printf("\nL->");
	    while(aux != NULL){
		    printf(" %d", aux->valor);
		    aux = aux->sig;
	    }
    }
}

int eliminar_nodo_ini(Lista *L3){
	Nodo *aux;
	int e=0;
	if (!is_lista_vacia(L3)) {
		aux =  L3->head; 
		L3->head = L3->head->sig; 
		e = aux->valor;
		L3->n = L3->n  - 1; /* descuenta el número de nodos de la lista */
		aux->sig = NULL;
		free (aux) ; 
	}
	return e;
}

int  eliminar_nodo_fin(Lista *L3){
	Nodo *aux, *auxE;
	int e=0;
	if (!is_lista_vacia(L3)){
		/* mover el aux al penúltimo nodo */
		aux = L3->head;
		while(aux->sig->sig !=NULL){
				aux = aux->sig;
		}		
		e = aux->sig->valor;
		L3->n = L3->n - 1;
		auxE = aux->sig;
		aux->sig = NULL;
		free (auxE) ; 
	}
	return e;	
}

Nodo *buscar_nodo(Lista *L3, int val){
	Nodo *aux;
	aux = L3->head;
	while(aux != NULL){
		if(aux->valor != val)
				aux = aux->sig;
		else
				return aux;
	}
  return aux;
}

void eliminar_nodo(Lista *L3, int val){
	Nodo *auxE, *aux; 
	int e;
	if  (!is_lista_vacia(L3)) {
		auxE = buscar_nodo(L3,val);
		if (auxE != NULL){
			if (auxE == L3->head){  
			   e = eliminar_nodo_ini(L3);
			}else {
			   if (auxE->sig == NULL){ 
						e = eliminar_nodo_fin(L3);
			   }else {
						/* Si el nodo a eliminar no está en el inicio ni en el fin 
						   mueve el aux al nodo anterior al que se elimina */
						aux = L3->head;
						while(aux->sig != auxE){
								aux = aux -> sig;
						}
						auxE = aux->sig;
						aux->sig = auxE->sig;
						L3->n = L3->n - 1;
						auxE->sig = NULL;
						free (auxE) ; 
				} 
			}
		}
	}	
} 


