#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafoMa.h"

/* struct para resultados recorrido en profundidad */
typedef struct vertice_visitado{
	int marcado;
	int pred;
	int distancia;  //distancia o tiempo alcanzado
}Visit;

void DFS_visit(Grafo *g, Visit vertex[], int u, int *time);
void DFS(Grafo *g);

/* Función principal del recorrido: (FUENTE: Cormen) */
void DFS(Grafo *g){
	Visit vertex[g->n];
	for (int i=0; i<g->n; i++) {
				vertex[i].marcado = 0;
				vertex[i].pred = -1;
				vertex[i].distancia = 0;
	}
	int time=0;
	for (int i=0; i<g->n; i++){
				if (vertex[i].marcado == 0){
						DFS_visit(g,vertex,i,&time);
				}
	}
	/* Ver datos de nodos visitados de la estructura vertix */
	printf("\n\nArreglo de distancias y Predecesores después del recorrido: ");
	printf("\n=============================================================");
	printf("\n Nodo \t PRED \t DIST");
	printf("\n--------------------------");
	for (int i=0; i<g->n; i++){
			printf("\n %d \t %d \t %d", i, vertex[i].pred, vertex[i].distancia);
	}
}

void DFS_visit(Grafo *g, Visit vertex[], int u, int *t){
	int grado_s, *ady=NULL;
	*t = *t + 1;
	vertex[u].distancia = *t;
	vertex[u].marcado = 1; // nodo  a explorar
	printf("\nPor la arista (%d,%d)\t", vertex[u].pred, u);
	printf("visito nodo %d\t en tiempo %d", u, vertex[u].distancia);
	grado_s = grado_vertice(g,u);
	if ( grado_s == 0) {
		return;
	}			
	ady = adyacentes_vertice(g,u);
	if (ady != NULL) {
			for (int k=0; k<grado_s; k++){ //Recorre adyacentes de nodo u
					if (vertex[ady[k]].marcado == 0){
							vertex[ady[k]].pred = u;
							DFS_visit(g,vertex,ady[k],t);
					 }
			}//fin for
			vertex[u].marcado = 2; //Fin de exploración del nodo
			*t = *t + 1;
	}
}


/**************************************
			
			PRINCIPAL

  ************************************   */
int main(int argc,  char *argv[]) {

		// Declarar variables 
		int i=0, k=0, num_vertices, v, grado_s, *ady=NULL;
		Arista a,b;
		FILE *fp;
		Grafo *g;

	  // Crear grafo
		fp = fopen("grafo_2.txt", "r");
		fscanf(fp, "%d", &num_vertices); //lee el dato de la primera fila del archivo
		g =  crear_grafo(num_vertices);
    printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
		
		// Insertar aristas al grafo
		while (fscanf(fp, "%i %i %f", &a.v, &a.w, &a.peso) == 3){
	      agregar_arista(g,a);
				/* para grafo NO dirigido agregar arista en sentido contrario */
					b.v = a.w;
					b.w = a.v;
					b.peso = a.peso;
					agregar_arista(g,b);
		}
		fclose(fp);
		
		// Mostrar grafo
		printf("\n\nDATOS DEL GRAFO @%p:",g);
		mostrar_grafo(g);
		
		// Eliminar Arista
		a.v = 6;
		a.w = 6;
		if (eliminar_arista(g,a))
			printf("\nArista (%d,%d) eliminada!\n", a.v, a.w);
		else
			printf("\nArista (%d,%d) No EXISTE!\n", a.v, a.w);

		mostrar_grafo(g);
		
		// grado vertice . (para grafo dirigido corresponde al grado de salida)
		v = 7;
		grado_s = grado_vertice(g,v);  // es lo mismo que el número de adyacentes
		if (grado_s == 0)
			printf("\nvertice %d con grado 0 o NO EXISTE!!!", v);
		else
			printf("\ngrado (de salida) vertice %d es %d", v, grado_s);


		// Adyacentes de un vertice
		v = 0;
		ady = adyacentes_vertice(g,v); //ady se crea para que se ocupe en el problema que lo requiere
		if (ady != NULL) {
			printf("\nadyacentes creado en @ = %p", ady);
			printf("\nAdyacentes del vertice %d: ", v);
			mostrar_adyacentes(g,v);  //Se usa g para mostrar los adyacentes
		}else printf("\nvertice %d NO TIENE ADYACENTES!!!", v);
		
		
		
		/***********************************/
		/* probar recorrido en profundidad */
		printf("\n\nRECORRIDO EN PROFUNDIDAD:");
		DFS(g);

	printf("\n\n");
  return 0;
}