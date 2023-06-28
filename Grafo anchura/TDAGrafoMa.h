//Estructura de datos para grafo con MATRIZ DE ADYACENCIA
// Grafo PONDERADO.
#include <stdbool.h>
struct grafo{
	float **Mad;
	int n;
	int m;
};
typedef struct grafo Grafo;
struct arista{
	int v,w;
	float peso;
};
typedef struct arista Arista;

//Encabezado Operaciones
Grafo *crear_grafo(int n);
Arista crear_arista(int v, int w, float peso);
bool agregar_arista(Grafo *g, Arista a);
void mostrar_grafo(Grafo *g);
bool eliminar_arista(Grafo *g, Arista a);
bool existe_arista(Grafo *g, Arista a);
bool existe_vertice(Grafo *g, int v);
int grado_vertice(Grafo *g, int v);
int *adyacentes_vertice(Grafo *g, int v);
void mostrar_adyacentes(Grafo *g, int v);


// Programación Operaciones

Arista crear_arista(int v, int w, float peso){
	Arista a;
	a.v = v;
	a.w = w;
	a.peso = peso;
	return a;
}

int grado_vertice(Grafo *g, int v){
	int cuenta=0;
	if (existe_vertice(g,v)){ // La existencia debiera validarse antes de entrar v aa la función
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0)
				cuenta = cuenta + 1;
		}
	}
	return cuenta;
}

int *adyacentes_vertice(Grafo *g, int v){
	int *adyacentes = NULL, k=0;
	if (grado_vertice(g,v)){ // La existencia debiera validarse antes de entrar v a la función
		adyacentes = (int*)malloc(sizeof(int) * grado_vertice(g,v));
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0){
					adyacentes[k] = j;
					k = k + 1;
			}
		}
	} //else printf("\n  adyacentes es NULL");
	return adyacentes;
}

Grafo *crear_grafo(int n){
	Grafo *g;
	g = malloc(sizeof(Grafo));
  g->Mad = malloc(sizeof(float*)*n);
	for (int i=0; i<n; i++){
      g->Mad[i] = malloc(sizeof(float)*n);
	}
	//Todas las aristas M[i][j] de la matriz quedan inactivas (sin conexión)
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) 
				g->Mad[i][j] = 0.0;
	}
  g->n = n;
  g->m = 0;
	return  g;	
}

void mostrar_grafo(Grafo *g){ 
	printf("\n Numero de vertices:%d",g->n);
	printf("\n Numero de aristas:%d",g->m);
	printf("\n");
	for (int i=0; i < g->n; i++){ 
		for (int j=0; j < g->n; j++){
			
			printf("%.2f ", g->Mad[i][j]);
		}
		printf("\n");
	}
}

bool agregar_arista(Grafo *g, Arista a){
	if (existe_vertice(g,a.v)){ // existe vértice v?
		if (existe_vertice(g,a.w)){ // existe vértice w?
				g->Mad[a.v][a.w] = a.peso;
				g->m = g->m + 1;
				return true;
		}
	}
	return false;
}

bool eliminar_arista(Grafo *g, Arista a){
	if (existe_vertice(g,a.v)){ // existe vértice v?
		if (existe_vertice(g,a.w)){ // existe vértice w?
			if (g->Mad[a.v][a.w] != 0.0) {
				g->Mad[a.v][a.w] = 0.0;
				g->m = g->m - 1;
				return true;
			}
		}
	}
	return false;
}

bool existe_vertice(Grafo *g, int v){
	if (v < g->n)
		return true;
	else
		return false;
}

bool existe_arista(Grafo *g, Arista a){
	if (existe_vertice(g,a.v)){ // existe vértice v?
		if (existe_vertice(g,a.w)){ // existe vértice w?
			if (g->Mad[a.v][a.w] != 0.0)
				return true;
		}
	}
	return false;
}

void mostrar_adyacentes(Grafo *g, int v){
			//Se asume que antes de llamar a esta operación ha validado existencia adyacentes
			for (int j=0; j<g->n; j++) {
				if (g->Mad[v][j] != 0.0){
						printf("\n  %d", j);
			  }
		  }
}









