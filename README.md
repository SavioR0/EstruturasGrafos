# Estrutura de Grafos
Sávio Rodrigues
---
# Introdução
Atividade da diciplina de Algoritmo e Estrutura de Dados II tem como objetivo aplicar grafos com matriz de adjacência e matriz de incidência e a busca de dados. Para tanto, utilizou-se como ponto de partida o código produzido durante as aulas sobre lista de Adjacências. A discussão proposta dessa documentação é apresentar a diferença 

# Apresentação
A teoria dos grafos ( ramo da matemática que estuda as relações entre os objetos de um determinado conjunto) é um assunto antigo, porém com várias aplicações no nosso dia-a-dia. No século XVIII o matématico suiço Leonard Euler utilizou os grafos para resolver o problemas que conhecemos como __As Sete pontes de königsberg__. 
<br><br>
A imagem a seguir possui uma representação de grafo, onde os números representam os vértices (V = {0, 1, 2}) e as letras representam as arestas (A = {a, b ,c}).
<p align="center">
    <img src="Imagens/grafos.png">
</p>
Nesse contexto existem três representações de grafos: Lista de Adjacencia, Matriz de Adjacência e Matriz de Incidência.
<br><br>

# Adaptações nas estruturas

## Matriz de Adjacência
Tendo como ponto de partida o código de lista de adjacência produzido durante as aulas, foram feitas algumas adaptações para que o algoritmo funcione como uma representação de matriz de Adjacência. A principal foi a substituição da variável *adj por **adj.

Em literatura a Matriz de adjacência é uma representação, com todas as arestas ou arcos de um grafo em uma matriz bidimencional _V x V_.
Portanto possui os seguintes atributos:
* ``int V`` = Número de vértices.
* ``int E`` = Número de Arestas.
* ``Vertex **adj`` = Matriz de Adjacência.
  
```c
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
```
A função ``GraphInitialize()`` precisou ser reajustada para atender a os objetivos da matriz de adjacência. Para tanto a função recebe como parâmetro o número de vértices e os inicializa em uma matriz a qual é preenchida com valor 0.
```c
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
```
``GraphInsertEdge()`` tem a função de inserir na matriz as Arestas adicionadas atribuindo 1 relancionando vertices na linha/coluna.

```C
void GraphInsertEdge(Graph G, int v1, int v2){
	if(G->adj[v1][v2]->value== 0){
		G->adj[v1][v2]->value=1;
		G->E++;
	}
}
```
Por fim a função ``ImprimeMatriz()`` e ``ImprimeGraph()``, mostra a matriz das relações dos vértices do grafo. Assim como mostra a imagem anexada em que foi utilizado o exemplo do slide 9/ aula 11.
```C
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
```
<p align="center">
    <img src="Imagens/CompMatrizAdj.png">
</p>

## Busca

## Matriz de Incidência
Semelhante à matriz de adjacência, a de incidência possui uma representação de grafo através de uma matriz bidimencional. Porém uma das dimensões são os vértices a outra são as arestas, ou seja uma matriz _V x E_. Portanto possui os seguintes atributos:
* ``int V`` = Número de vértices
* ``int A`` = Número de Arestas
* ``int **adj`` = Matriz de incidência.
  
```C
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
```
A função ``GraphInitialize()`` recebe como parâmetro o número de vértices e o numero de arestas e os inicializa em uma matriz a qual é preenchida com valor 0.
```C
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
```
Diferente da matriz de adjacência, a função ``GraphInsertEdge()`` na matriz de incidência tem a função de inserir 1 quando a aresta incide do vétice (representado pela linha) e -1 no vértice destino. Ou seja, em toda coluna da matriz, têm-se o valor 1 e -1 indicando o a incidência e destido de uma aresta.
```C
void GraphInsertEdge(Graph G, int v1, int v2){
	if(G->adj[v1][G->E]->value== 0){
		G->adj[v1][G->E]->value= 1;
		G->adj[v2][G->E]->value=-1;
		G->E++;
	}
}
```
Por fim a função ``ImprimeMatriz()`` mostra a matriz das relações dos vértices do grafo. Assim como mostra a imagem anexada em que foi utilizado o exemplo do slide 9/ aula 11 para a produção de uma parte desse documento.

```C
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
```
<p align="center">
    <img src="Imagens/CompMatrizInc.png">
</p>
A compilação, mostra que foram criados 8 vértices e 20 arestas indicando a incidência e destino de cada uma na matriz.
<br></br>

## Busca

# Consumo de memória e tempo de execução

A atividade proposta tem como objetivo duas execuções de grafos com 100 vértices para a obtenção de dados palpáveis na análise dos algoritmos. Um grafo esparso e um denso para cada uma das representações.

## Lista de Adjacência
### Grafo Esparso
### Grafo Denso

## Matriz de Adjacência
### Grafo Esparso
### Grafo Denso

## Matriz de Incidência
### Grafo Esparso
### Grafo Denso

## Conclusão
