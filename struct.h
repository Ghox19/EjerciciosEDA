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
        printf("%d,%d\n",p[i].x,p[i].y);
    }
}