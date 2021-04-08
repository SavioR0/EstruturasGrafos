#ifndef _BUSCA_
#define _BUSCA_

//========================DFS================================
void DFS_VISIT(Graph G, int v, int *cor, int *d, int *f, int *tempo){
	cor[v]  = 1;
	*tempo        += 1;
	d[v]    = *tempo;

	for(int i = 0; i<G->V ; i++)
		if(G->adj[v][i]->value == 1 && cor[i] == 0)
			DFS_VISIT(G, i, cor, d, f, tempo);

	cor[v] = 2;
	*tempo += 1;
	f[v] = *tempo;
	printf("    Vertex:%d D:%d, F:%d \n", v, d[v], f[v]);
}

void DFS(Graph G){
	int cor[G->V]; // Branco 0, Cinza 1, Preto 2
	int d[G->V];   // Tempo de descoberta
	int f[G->V];   // Tempo de finalização
	int tempo = 0;
	for(int v=0; v<G->V; v++)
		cor[v] = 0;
	printf("\t=======DFS======\n");
	for(int v=0; v<G->V; v++)
		if(cor[v] == 0)
			DFS_VISIT(G, v, cor, d, f, &tempo);
}
//===========================================================
//====================BFS====================================

void BFS(Graph G, Vertex s){
	int cor[G->V]; //0 Branco, 1 Cinza, 2 Preto
	int d[G->V];
	int pi[G->V]; // -1 == NULL
	Fila *f = FFVazia();

	for(int i=0; i<G->V; i++)
		if(i != s->value){
			cor[i] = 0;
			d[i]   = -1; //infinito
			pi[i]  = -1; // ? não tem pai ainda
		}

	cor[s->value] = 1; 
	d[s->value]   = 0;
	pi[s->value]  = -1;

	Queue(f, s->value);
	printf("\t=======BFS======\n");
	while (f->size > 0){
		Item *u = Dequeue(f);

		for(int v =0; v< G->V; v++){
			if(G->adj[u->data][v]->value == 1 && cor[v]== 0){ //Se Exitir aresta entre os vértices e ele for branco
				cor[v]= 1;
				d[v] = d[u->data] + 1;
				pi[v] = u->data;
				Queue(f, v);
			}
		}

		cor[u->data] = 2;
		printf("    Vertex:%d\n", u->data);		
	}
}
//===========================================================

#endif




