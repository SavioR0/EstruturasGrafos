#ifndef _ARVORERB_
#define _ARVORERB

typedef struct Record Record;
typedef struct Tree Tree;

/*       Árvore RB
 1.Todo nó é vermelho ou preto
 2.A raiz é preta
 3.Toda folha (Nil) é preta
 4.Se um nó é vermelho, então os seus filhos são  pretos
 5.Para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.
 */

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
	int cor; // 1 Para Vermelho, 0 para preto
};

Tree* CreateTree(){
	return NULL;
}



void pesquisa(Tree **t, Tree **aux, Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}

void showTreeInOrder(Tree *t){
	if(!(t == NULL)){
    	showTreeInOrder(t->esq); 
    	printf("%d ", t->reg.key);
		if(t->cor == 1)
			printf("Vermelho ");
		else
			printf("Preto ");
    	showTreeInOrder(t->dir); 
	}
}
#endif