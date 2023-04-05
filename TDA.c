#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#define max = 20

/*TDA-> estructura
    -> operaciones*/

int main(){
    int n;
    printf("cuantos puntos va a ingresar: ");
    scanf("%d",&n);
    punto *punto;
    punto = memoria(n);
    insertar_punto(punto,n);
    mostrar(punto,n);
}