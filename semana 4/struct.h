#include <stdio.h>
#include <stdlib.h>

typedef struct punto {
    int x;
    int y;
}punto;

punto *memoria(int n){
    punto *tp;
    tp = (punto*)malloc(sizeof(punto)*n);
    return tp;
}

void insertar_punto(punto *p,int n){
    for (int i = 0; i < n; i++){
        printf("escriba el %d punto ejemplo(x y): ",i+1);
        scanf("%d %d",&p[i].x,&p[i].y);
    }
}

void mostrar(punto *p,int n){
    for (int i = 0; i < n; i++){
        printf("%d,%d ",p[i].x,p[i].y);
    }
}

int borrar(punto *p, int n){
    int pos, temp1, temp2;
    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("%d,%d ",p[i].x,p[i].y);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("|%d| ",i+1);
    }
    printf("\nQue posicion quieres eliminar: ");
    scanf("%d",&pos);
    pos -= 1;
    for (int j = pos; j < n; j++){
        temp1 = p[j].x;
        temp2 = p[j].y;
        p[j].x = p[j + 1].x;
        p[j].y = p[j + 1].y;
        p[j + 1].x = temp1;
        p[j + 1].y = temp2;
    }
    n -= 1;
    for (int i = 0; i < n; i++){
        printf("%d,%d ",p[i].x,p[i].y);
    }
    return n;
}