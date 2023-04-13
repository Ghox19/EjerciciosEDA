#include <stdio.h>
#include <stdlib.h>
#define LARGO_NOM 30

FILE *abrir_archivo(char nomA[LARGO_NOM],char *modo_lec){
    FILE *fil;
    fil = fopen(nomA,modo_lec);
    if (fil == NULL){
        printf("Error al abrir el archivo %s\n",nomA);
        return NULL;
    }
    printf("El Archivo %s se a abierto correctamente\n",nomA);
    return fil;
}

int elementos_matriz(FILE *fil){
	int cont1 = 0, cont2 = 0;
    while(!feof(fil)){
        int num1[1];
        fscanf(fil,"%d",&num1);
        cont1 += 1;
    }
	return cont1;
}