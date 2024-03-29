#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct punto {
  int x;
  int y;
  struct punto *sig;
} nodo;

typedef nodo *pnodo;

void insertar_punto(pnodo *cabeza, int e,int cont){
    pnodo nuevo, actual;
    nuevo = malloc(sizeof(pnodo));
    printf("escriba el %d punto ejemplo(x y): ", cont);
    scanf("%d %d", nuevo->x, nuevo->y);
    
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

void mostrar(pnodo cabeza) {
    int i, count = 0;
    pnodo actual = cabeza;

    while (actual != NULL) {
        count++;
        actual = actual->sig;
    }

    actual = cabeza;

    i = count

    for (i = count - 1; i >= 0; i--) {
        printf("%4d %4d", valor.x, valor.y);
        actual = actual->sig;
    }

    free(elementos);
}

void mostrar(punto *p, int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,%d ", p[i].x, p[i].y);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("|%d| ", i + 1);
  }
  printf("\n");
}

int borrar(punto *p, int n) {
  int pos, temp1, temp2;
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,%d ", p[i].x, p[i].y);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("|%d| ", i + 1);
  }
  printf("\nQue posicion quieres eliminar: ");
  scanf("%d", &pos);
  pos -= 1;
  for (int j = pos; j < n; j++) {
    temp1 = p[j].x;
    temp2 = p[j].y;
    p[j].x = p[j + 1].x;
    p[j].y = p[j + 1].y;
    p[j + 1].x = temp1;
    p[j + 1].y = temp2;
  }
  n -= 1;
  printf("\n");
  return n;
}

void origen(punto *p, int n) {
  int pos, x, y;
  float distancia;
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,%d ", p[i].x, p[i].y);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("|%d| ", i + 1);
  }
  printf("\nQue posicion quieres calcular: ");
  scanf("%d", &pos);
  pos -= 1;
  x = p[pos].x;
  y = p[pos].y;
  distancia = pow((y * y + x * x), 0.5);
  printf("\nLa distancia del punto al origen es %f\n", distancia);
}

void distancia(punto *p, int n) {
  int pos1, pos2, x1, x2, y1, y2;
  float distancia;
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,%d ", p[i].x, p[i].y);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("|%d| ", i + 1);
  }
  printf("\nQue posiciones quieres calcular(pos1 pos2): ");
  scanf("%d %d", &pos1, &pos2);
  pos1 -= 1;
  pos2 -= 1;
  x1 = p[pos1].x;
  y1 = p[pos1].y;
  x2 = p[pos2].x;
  y2 = p[pos2].y;
  distancia = sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
  printf("\nLa distancia entre los 2 puntos es %f\n", distancia);
}