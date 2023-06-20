#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "S10_TDAGrafoMa_C3.h"
/* Agregue aqu� el TDA que va a utilizar */
//#include ......
void BFSDestino(Grafoc3 *G, int origen, int destino) {
  bool visitados[G->n];
  int cola[G->n];
  int frente = 0;
  int final = 0;

  for (int i = 0; i < G->n; i++) {
    visitados[i] = false;
  }
  visitados[origen] = true;
  cola[final] = origen;
  final++;

  printf("Recorrido BFS desde el vertice %d hasta el vertice %d: \n", origen, destino);
  bool encontrado = false;
  while (frente != final) {
    int actual = cola[frente];
    frente++;
    if (actual == destino) {
      encontrado = true;
      printf("%d ", actual);
      break;
    }
    printf("%d -> ", actual);

    // Recorrer los v�rtices adyacentes al v�rtice actual
    for (int i = 0; i < G->n; i++) {
      if (!visitados[i] && G->Mad[actual][i] != 0) {
        visitados[i] = true;
        cola[final] = i;
        final++;
      }
    }
  }

  if (!encontrado) {
    printf("no existe camino al vertice %d.", destino);
  }

  printf("\n");
}
Aristac3 *crearArista(int ver1, int ver2, float peso){
  Aristac3 *A;
  A = (Aristac3 *)malloc(sizeof(Aristac3));
  A->v = ver1;
  A->w = ver2;
  A->peso = peso;
  
  return A;
}
Grafoc3 *leergrafo(char *nombreArchivo) {
  Grafoc3 *G;
  Aristac3 *A;
  int n_vertices;
  int v, w;
  float p;
  FILE *fp = fopen(nombreArchivo, "r");
  if (fp == NULL) {
    printf("Error al abrir el archivo.\n");
    return NULL;
  }
  else{
    // Leer el n�mero de v�rtices
    if(fscanf(fp, "%d", &n_vertices)){ //este if es solo para evitar warnings
    G = crear_grafoc3(n_vertices);
    }
    
    // Leer las conexiones entre los v�rtices desde el archivo
    while (fscanf(fp, "%d %d %f", &v, &w, &p) != EOF) {
      A = crearArista(v, w, p);
      agregar_aristac3(G, *A);
    }
    
    fclose(fp);
    
    return G;
  }
}

int main(int argc,  char *argv[]) {
	/* PROBLEMA 1. 
		   Escriba las instrucciones necesarias para resolver y mostrar los 
			 resultados del problema 1 de su actividad*/
	Grafoc3 *G;
	//int Nodosfuente = nodos[] //Arreglo para guardar nodos fuente
  	char *archivo = argv[1];
  	char *or = argv[2];
  	char *des = argv[3];
  	int origen = atoi(or); 
  	int destino = atoi(des);
  	printf("Resultados del problema 1:\n");		
  	G = leergrafo(archivo);
  	//mostrar_grafo(g);
  	mostrar_grafoc3(G);
  	printf("\n");
		/* DECLARACI�N DE VARIABLES 
		  Declare aqu� las variables necesarias para resolver los problemas de la actividad */
		
		
		
		
		
    
	



    printf("\n");

		/* PROBLEMA 2. 
		   Escriba las instrucciones necesarias para mostrar
			 el  resultado de la funci�n solicitada en el problema 2 de su actividad*/
    printf("Resultados del problema 2:\n");		
 	//mostrar_adyacentesc3()
    int *numeros =  (int *) malloc(G->n * sizeof(int));
    int cont = 0;
    for (int i = 0; i < G->n; i++){
      int ver = 0;
      for (int j = 0; i < G->n; i++){
        if (G->Mad[j][i]!= 0){
          ver = 1;
        }
      }
      if (ver == 0){
        numeros[cont] = i;
        cont++;
      }
    }
    for (int i = 0;i < cont;i++){
      printf("AAAAA HRMN%d ", numeros[i]);
    }





    printf("\n");

		/* PROBLEMA 3. 
		   Escriba las instrucciones necesarias para mostrar
			 el  resultado de la funci�n solicitada en el problema 3 de su actividad*/
    printf("Resultados del problema 3:\n");	
	BFSDestino(G, origen, destino); //Busca y muestra el camino si es que existe









		
		printf("\n\n");
		return 0;
}
