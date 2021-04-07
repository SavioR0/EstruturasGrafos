#ifndef _MADJ_
#define _MADJ_

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

struct TipoVertex{
	int value;
};

struct graph{
	int V;
	int E;
	Vertex **adj;
};

Vertex VertexInitialize(int value){
	Vertex v = (Vertex )malloc (sizeof(Vertex));
	v->value = value;
	return v;
}

Graph GraphInitialize(int V){
	Graph G = (Graph)malloc (sizeof(Graph));
	G->V = V;
	G->E = 0;
	G->adj = (Vertex **)malloc(V * sizeof(Vertex));
	for(int i=0; i<V; i++)
		G->adj[i] = (Vertex *)malloc(sizeof(Vertex) * V);
	
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			G->adj[i][j] = VertexInitialize(0);

	return G;
}

void GraphInsertEdge(Graph G, int v1, int v2){
	if(G->adj[v1][v2]->value== 0){
		G->adj[v1][v2]->value=1;
		G->E++;
	}
}

void ImprimeMatriz(Graph G){
	printf("\t --MATRIZ DE ADJACÊNCIA--\n");
	printf("\t   ");
	for(int i =0; i<G->V; i++)
		printf("[%d]",i);
	printf("\n");

	for(int i=0; i<G->V; i++){
		printf("\t[%d] ", i);
		for(int j = 0; j<G->V; j++)
			printf("%d  ", G->adj[i][j]->value);
		printf("\n");
	}
	printf("\n");
}

void ImprimeGraph(Graph G){
	printf("\t--VÉRTICES E ARESTAS--\n");

	for (int i=0; i< G->V; i++){
		printf("   [%d]->",i);
		for(int j=0; j< G->V; j++){
			if(G->adj[i][j]->value == 1)
				printf("%d ", j);
		}
		printf("\n");
	}
	printf("\n");
}


#endif