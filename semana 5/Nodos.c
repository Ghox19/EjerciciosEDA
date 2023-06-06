#include <stdio.h>
#include <stdlib.h>

typedef struct snodo{
    int valor;
    struct snodo *sig;
}tnodo;

typedef tnodo *tpuntero;

void insertarenlista(tpuntero *cabeza, int e);
void imprimirlista(tpuntero cabeza);
void borrarlista(tpuntero *cabeza);

int main(){
    int e;
    tpuntero cabeza;
    cabeza = NULL;

    printf("Ingrese elementos, -1 para terminar: ");
    scanf("%d",&e);

    while(e!=-1){
        insertarenlista(&cabeza, e);
        printf ("ingresado correctamente\nIngrese elementos, -1 para terminar; ");
        scanf("%d",&e);
    }

    printf("\nSe imprime la lista cargada: ");
    imprimirlista(cabeza);

    printf("\nSe borra la lista cargada: \n");
    borrarlista(&cabeza);
    
    return 0;
}

void insertarenlista(tpuntero *cabeza, int e) {
    tpuntero nuevo, actual;

    nuevo = malloc(sizeof(tnodo));
    nuevo->valor = e;
    nuevo->sig = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        actual = *cabeza;

        while (actual->sig != NULL) {
            actual = actual->sig;
        }

        actual->sig = nuevo;
    }
}

void imprimirlista(tpuntero cabeza) {
    int i, count = 0;
    tpuntero actual = cabeza;

    while (actual != NULL) {
        printf(*actual);
        actual = actual->sig;
    }
}

void borrarlista(tpuntero *cabeza){
    tpuntero actual;

    while(*cabeza != NULL){
        actual = *cabeza;
        *cabeza = (*cabeza)->sig;
        free(actual);
    }
}
