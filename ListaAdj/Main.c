#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaAdj.h"
#include "busca.h"

#define V 102 			//Número de vértices
#define EEsparso 101	//Arestas em um grafo esparço, ordem de V
#define EDenso 10000	//Arestas em um grafo denso, ordem de v² 
int main(){
	///========== TESTE USADO NA DOCUMENTAÇÃO DO CÓDIGO ===========

	Graph G = GraphInitialize(8);

	//Modelo de Grafo do slide 9 / aula 11
	//S=0, W=1, R=2, V=3, T=4, X=5, U=6, Y=7
	GraphInsertEdge(G, G->adj[0], G->adj[2]);
	GraphInsertEdge(G, G->adj[0], G->adj[1]);
	GraphInsertEdge(G, G->adj[1], G->adj[0]);
	GraphInsertEdge(G, G->adj[1], G->adj[4]);
	GraphInsertEdge(G, G->adj[1], G->adj[5]);
	GraphInsertEdge(G, G->adj[2], G->adj[0]);
	GraphInsertEdge(G, G->adj[2], G->adj[3]);
	GraphInsertEdge(G, G->adj[3], G->adj[2]);
	GraphInsertEdge(G, G->adj[4], G->adj[1]);
	GraphInsertEdge(G, G->adj[4], G->adj[5]);
	GraphInsertEdge(G, G->adj[4], G->adj[6]);
	GraphInsertEdge(G, G->adj[5], G->adj[1]);
	GraphInsertEdge(G, G->adj[5], G->adj[4]);
	GraphInsertEdge(G, G->adj[5], G->adj[6]);
	GraphInsertEdge(G, G->adj[5], G->adj[7]);
	GraphInsertEdge(G, G->adj[6], G->adj[4]);
	GraphInsertEdge(G, G->adj[6], G->adj[5]);
	GraphInsertEdge(G, G->adj[6], G->adj[7]);
	GraphInsertEdge(G, G->adj[7], G->adj[6]);
	GraphInsertEdge(G, G->adj[7], G->adj[5]);

	ImprimeGraph(G);
	DFS(G);
	BFS(G, G->adj[0]);
	printf("\n\n");
//==================================================*/


//==========CÓDIGO PARA A COLETA DE TEMPO E MEMÓRIA UTILIZADA===========
	
	/*//==========GRAFO ESPARSO=======

	clock_t t;
	t = clock();
	//Criando um grafo
	Graph G = GraphInitialize(V);

	//Inicializando o grafo com 100 vértices um onde o todos estão inteligados com o seu anterior
	for (int i = 0; i<EEsparso; i++){
		GraphInsertEdge(G, G->adj[i], G->adj[i+1]);
	}
	GraphInsertEdge(G, G->adj[EEsparso], G->adj[0]);

	//ImprimeGraph(G);
	DFS(G);
	BFS(G, G->adj[0]);
	//Imprime tempo
	t = clock() - t; //Tempo final menos inicial
	printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));// Tempo em milisegundos
	//==============================*/

	/*//======= GRAFO DENSO==========

	clock_t t;
	t = clock();
	//Criando do grafo (Grafo Esparso + v² vertices) 
	Graph G = GraphInitialize(V);
	//Inicializando o grafo com 100 vértices, onde o todos estão inteligados com o seu anterior
	for (int i = 0; i<EEsparso; i++){
		GraphInsertEdge(G, G->adj[i], G->adj[i+1]);
	}
	GraphInsertEdge(G, G->adj[EEsparso], G->adj[0]);

	//Adiciona 10.000 arestas aleatórios
	srand(time(NULL));
	
	for (int i = 0; i < EDenso; i++)
		GraphInsertEdge(G, G->adj[(rand() % 101)], G->adj[(rand() % 101)]);
	
	
	//ImprimeGraph(G);
	DFS(G);
	BFS(G, G->adj[0]);
	//Imprime tempo
	t = clock() - t;
	printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));// Tempo em milisegundos
	//===============================*/
//======================================================================
	return 0;
}





