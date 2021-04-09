#ifndef _MINC_
#define _MINC_

typedef struct TipoVertex *Vertex;
typedef struct graphInc *Graph;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;


struct TipoVertex{
	int value;
};

struct graphInc{
	int V;
	int E;
	Vertex **adj;
};

//============================FILA===================================//
struct TipoItem{
    int data;
	Item *prox;
};

struct TipoFila{
	Item *head;
	Item *tail;
	int size;
};

//// procs FILA

Fila* FFVazia(){
	Fila *f = (Fila*) malloc(sizeof(Fila));
	f->head = NULL;
	f->tail = NULL;
	return f;
}

void Queue(Fila *f, int vertex){
	Item *d = (Item *) malloc (sizeof(Item));
	d->data = vertex;
	d->prox = NULL;

	if(f->head == NULL){
		f->head = d;
		f->tail = d;
	}else{
		f->tail->prox = d;
		f->tail = d;
	}

	f->size ++;
}

Item* Dequeue(Fila *f){
	Item *aux;

	if(f->head == NULL)
		return NULL;

	aux = f->head;
	f->head = f->head->prox;
	f->size --;

	return aux;
}

//===============================================================//

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