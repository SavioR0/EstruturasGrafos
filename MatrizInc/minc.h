#ifndef _MINC_
#define _MINC_

typedef struct TipoVertex *Vertex;
typedef struct graphInc *Graph;


struct TipoVertex{
	int value;
	Vertex prox;
};

struct graphInc{
	int V;
	int E;
	Vertex **adj;
};

Vertex VertexInitialize(int value){
	Vertex v = (Vertex )malloc (sizeof(Vertex));
	v->value = value;
	return v;
}

Graph GraphInitialize(int V, int E){
	Graph G = (Graph)malloc (sizeof(Graph));
	G->V = V;
	G->E = 0;
	G->adj = (Vertex **)malloc(V * sizeof(Vertex));
	for(int i=0; i<V; i++)
		G->adj[i] = (Vertex *)malloc(sizeof(Vertex) * E);
	
	for(int i=0; i<V; i++)
		for(int j=0; j<E; j++)
			G->adj[i][j] = VertexInitialize(0);
	//printf("Grafo Criado!\n");
	return G;
}

void GraphInsertEdge(Graph G, int v1, int v2){
	if(G->adj[v1][G->E]->value== 0){
		G->adj[v1][G->E]->value=1;
		G->adj[v2][G->E]->value=-1;
		G->E++;
	}
}

void ImprimeMatriz(Graph G){
	printf("\t\t\t\t --MATRIZ DE INCIDÊNCIA--\n");
	printf("\t   ");
	for(int i =0; i<G->E; i++)
		printf("[%2d]",i);
	printf("\n");

	for(int i=0; i<G->V; i++){
		printf("\t[%d] ", i);
		for(int j = 0; j<G->E; j++)
			printf("%2d  ", G->adj[i][j]->value);
		printf("\n");
	}
	printf("\n");
}


#endif