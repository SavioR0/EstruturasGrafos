#include<stdio.h>
#include<stdlib.h>
#include "madj.h"
#include "busca.h"

int main(){
	Graph G = GraphInitialize(8);

	//Modelo de Grafo do slide 9 / aula 11
	//S=0, W=1, R=2, V=3, T=4, X=5, U=6, Y=7
	GraphInsertEdge(G, 0, 2);
	GraphInsertEdge(G, 0, 1);
	GraphInsertEdge(G, 1, 0);
	GraphInsertEdge(G, 1, 4);
	GraphInsertEdge(G, 1, 5);
	GraphInsertEdge(G, 2, 0);
	GraphInsertEdge(G, 2, 3);
	GraphInsertEdge(G, 3, 2);
	GraphInsertEdge(G, 4, 1);
	GraphInsertEdge(G, 4, 5);
	GraphInsertEdge(G, 4, 6);
	GraphInsertEdge(G, 5, 1);
	GraphInsertEdge(G, 5, 4);
	GraphInsertEdge(G, 5, 6);
	GraphInsertEdge(G, 5, 7);
	GraphInsertEdge(G, 6, 4);
	GraphInsertEdge(G, 6, 5);
	GraphInsertEdge(G, 6, 7);
	GraphInsertEdge(G, 7, 6);
	GraphInsertEdge(G, 7, 5);
	
	ImprimeMatriz(G);
	ImprimeGraph(G);
	return 0;
}


