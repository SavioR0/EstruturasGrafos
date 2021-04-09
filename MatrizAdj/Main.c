#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "madj.h"
#include "busca.h"

#define V 102 			//Número de vértices
#define EEsparso 101	//Arestas em um grafo esparço, ordem de V
#define EDenso 10000	//Arestas em um grafo denso, ordem de v² 

int main(){
///========== TESTE USADO NA DOCUMENTAÇÃO DO CÓDIGO ===========
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
	BFS(G, G->adj[0][0]);
	DFS(G);
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
		GraphInsertEdge(G, i, i+1);
	}
	GraphInsertEdge(G, EEsparso, 0);

	//ImprimeMatriz(G);
	//ImprimeGraph(G);
	DFS(G);
	BFS(G, G->adj[0][0]);

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
		GraphInsertEdge(G, i, i+1);
	}
	GraphInsertEdge(G, EEsparso, 0);

	//Adiciona 10.000 arestas aleatórios
	srand(time(NULL));
	
	for (int i = 0; i < EDenso; i++)
		GraphInsertEdge(G, (rand() % 101), (rand() % 101));
	
	//ImprimeMatriz(G);
	//ImprimeGraph(G);
	DFS(G);
	BFS(G, G->adj[0][0]);
	//Imprime tempo
	t = clock() - t;
	printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));// Tempo em milisegundos
	//===============================*/
//======================================================================




	
	return 0;
}


