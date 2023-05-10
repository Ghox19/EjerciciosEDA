#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#define max = 20

/*TDA-> estructura
    -> operaciones*/

int main() {
  int n, eleccion;
  int ver = 1;
  printf("cuantos puntos va a ingresar: ");
  scanf("%d", &n);
  punto *punto;
  punto = memoria(n);
  insertar_punto(punto, n);
  while (ver == 1) {
    printf(
        "\nQue quieres hacer:\nMostrar puntos 1)\nBorrar punto "
        "2)\nEncontrar distancia origen "
        "3)\nEncontrar distancia 2 puntos 4)\nSalir 5)\nEscriba su eleccion:");
    scanf("%d", &eleccion);
    if (eleccion == 1) {
      mostrar(punto, n);
    }
    if (eleccion == 2) {
      n = borrar(punto, n);
    }
    if (eleccion == 3) {
      origen(punto, n);
    }
    if (eleccion == 4) {
      distancia(punto, n);
    }
    if (eleccion == 5) {
      ver = 0;
    }
    if (eleccion <= 0 || eleccion > 5) {
      printf("La eleccion no es valida");
    }
  }
}