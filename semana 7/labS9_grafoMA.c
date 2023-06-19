#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafo_MA.h"


int main(int argc,  char *argv[]) {

		// Paso a)
		int i, num_vertices, v, w;
		FILE *fp;
		Grafo *g;
		
	  // Paso b)
		fp = fopen("datos_grafo.txt", "r");
		fscanf(fp, "%d", &num_vertices); //lee el dato de la primera fila del archivo
		g =  crear_grafo(num_vertices);
    printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
		
		// Paso c)
		while (fscanf(fp, "%i %i", &v, &w ) == 2){
	      agregar_arista(g,v, w);
		}
		fclose(fp);
		
		// Paso d)
		printf("\n\nDATOS DEL GRAFO @%p:",g);
		mostrar_grafo(g);
		
		// Paso e)
		agregar_vertice(g); //n cambia y debiera agregar una lista en g->lisv[n-1]
		printf("\nNumero de vertices cambio a: %d", g->n); //debiera mostrar 7
		//printf("\nNumero de aristas (nodos) del nuevo vertice %d es %d", g->n-1, obtener_num_aristas_vertice(g,g->n-1)); //debiera mostrar 0
		mostrar_grafo(g);
		
		// continuar usted con las operaciones buscar arista, eliminar arista, etc.
		
	printf("\n\n");
  return 0;
}