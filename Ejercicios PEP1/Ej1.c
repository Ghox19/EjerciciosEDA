/*Construya un algoritmo en pseudocódigo que reciba tres listas de largo distinto
(L1, L2 y L3), y las ordene todas en la lista L1, eliminando los elementos repetidos. */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void Comprobar_lista_repetidos(Lista *A) {
    Nodo *aux1, *aux2, *elim;
    if (!is_lista_vacia(A)) {
        aux1 = A->head;
        while (aux1 != NULL) {
            aux2 = aux1;
            while (aux2->sig != NULL) {
                if (aux1->valor == aux2->sig->valor) {
                    elim = aux2->sig;
                    aux2->sig = elim->sig;
                    free(elim);
                } else {
                    aux2 = aux2->sig;
                }
            }
            aux1 = aux1->sig;
        }
    }
}

void ordenar_lista

void Lista_especifica(Lista *head) {
  int n = 7; // Ya que es una lista especifica se dice el numero y se ingresa a
             // la posicion que debe ir
  insertar_nodo_ini(head, n);
  n = 2;
  insertar_nodo_fin(head, n);
  n = 4;
  insertar_nodo_fin(head, n);
  n = 6;
  insertar_nodo_ini(head, n);
  n = 3;
  insertar_nodo_ini(head, n);
  n = 4;
  insertar_nodo_ini(head, n);
  n = 5;
  insertar_nodo_fin(head, n);
}

void Ordenar_listas(Lista *A,Lista *B){
    Nodo *aux1,*aux2,*elim;
    if (!(is_lista_vacia)){
        aux1 = A -> head;
        aux2 = B -> head;
    }

    }
/*int Mayor_elemento(Lista *L3) {
  Nodo *aux; // se crea un auxiliar que recorra la lista
  int max;     // variable max(mayor)
  if (!(is_lista_vacia(
          L3))) {      // verifica si la lista esta vacia, si no lo esta sigue
    aux = L3->head;  // da la direccion de la cabeza de la lista
    max = aux->info; // plantea que el primer numero es el mayor
    aux = aux->sig;  // avanza al siguiente numero
    while (aux != NULL) {      // ciclo que si no es NULL continue
      if (max < aux->info) { // compara el numero que contiene con el max
                               // establecido
        max = aux->info;     // si es mayor lo cambia
      }
      aux = aux->sig; // avanza para seguir el ciclo
    }
  }
  return max;
}*/

int main(){
    Lista *head;
    head = crear_lista();
    Lista_especifica(head);
    mostrar_lista(head);
    Comprobar_lista_repetidos(head);
    mostrar_lista(head);
}