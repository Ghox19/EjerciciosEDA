//Estructura de datos para grafo con MATRIZ DE ADYACENCIA
// Grafo Dirigido, no ponderado.
#include <stdbool.h>
struct grafo{
	int **Mad;
	int n;
	int m;
};
typedef struct grafo Grafo;

//Encabezado Operaciones
Grafo *crear_grafo(int n);
void agregar_arista(Grafo *g, int v, int W);
void mostrar_grafo(Grafo *g);
void eliminar_arista(Grafo *g, int v, int w);
bool existe_vertice(Grafo *g, int v);
bool existe_arista(Grafo *g, int v, int w);



// Programación Operaciones

Grafo *crear_grafo(int n){
	Grafo *g;
	g = malloc(sizeof(Grafo));
  g->Mad = malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++){
      g->Mad[i] = malloc(sizeof(int)*n);
	}
	//Todas las aristas M[i][j] de la matriz quedan inactivas (sin conexión)
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) 
				g->Mad[i][j] = 0;
	}
  g->n = n;
  g->m = 0;
	return  g;	
}

void agregar_vertice (Grafo *g){
	g->Mad = realloc(g->Mad, sizeof(int)*(g->n + 1)); //realloc reasigna tamaño memoria

	//Agrega una celda al final de la fila de cada vertices ya creados e inicializa en 0																									       // conservando lo anterior
	for (int i=0; i<g->n; i++){
      g->Mad[i] = realloc(g->Mad[i], sizeof(int)*(g->n + 1));
			g->Mad[i][g->n] = 0;
	}
	
	//agrega la fila completa del nuevo vértice
	g->Mad[g->n] = malloc(sizeof(int)*(g->n + 1)); 
	//actualizar el número de vértces del grafo
  g->n = g->n + 1; 
	
	//inicializa la nueva fila
	for (int j=0; j<g->n ;j++) 
			g->Mad[g->n-1][j] = 0;

}

void mostrar_grafo(Grafo *g){ 
	printf("\n Numero de vertices:%d",g->n);
	printf("\n Numero de aristas:%d",g->m);
	printf("\n");
	for (int i=0; i < g->n; i++){ 
		for (int j=0; j < g->n; j++){
			printf("%d ", g->Mad[i][j]);
		}
		printf("\n");
	}
}

void agregar_arista(Grafo *g, int v,int w){
	g->Mad[v][w] = 1;
	g->m = g->m + 1;
}

void eliminar_arista(Grafo *g, int v,int w){
	g->Mad[v][w] = 0;
	g->m = g->m - 1;
}

bool existe_vertice(Grafo *g, int v){
	if (v < g->n)
		return true;
	else
		return false;
}

bool existe_arista(Grafo *g, int v, int w){
	if (existe_vertice(g,v)){ // existe vértice v?
		if (existe_vertice(g,w)){ // existe vértice w?
			if (g->Mad[v][w] == 1)
				return true;
			else
				return false;
		}
	}
	return false;
}












