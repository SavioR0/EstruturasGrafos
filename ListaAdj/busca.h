#ifndef _BUSCA_
#define _BUSCA_

void DFS(Graph G){
	int cor[G->V]; // Branco 0, Cinza 1, Preto 2
	int d[G->V];   // Tempo de descoberta
	int f[G->V];   // Tempo de finalização
	int tempo = 0;

	for(int v=0; v<G->V; v++)
		cor[v] = 0;

	for(int v=0; v<G->V; v++)
		if(cor[v] == 0)
			DFS_VISIT(G, G->adj[v], cor, d, f, &tempo);
}

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

	while (f->size > 0){
		Item *u = Dequeue(f);
		for(Vertex v = G->adj[u->data]; v != NULL; v=v->prox){
			if(cor[v->value] == 0){
				cor[v->value] = 1;
				d[v->value]   = d[u->data] + 1;
				pi[v->value]  = u->data;
				Queue(f, v->value);
			}
		}

		cor[u->data] = 2;
		printf("Vertex:%d\n", u->data);
	}
}

#endif