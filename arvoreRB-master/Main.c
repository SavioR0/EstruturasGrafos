#include<stdio.h>
#include<stdlib.h>
#include "arvoreRB.h"
#include "Insercao.h"
#include "Cor.h"


int main(){
	int reg[] = {6,4,8,5};
	Tree *raiz = CreateTree();
	Record r;
	int tam = sizeof(reg)/sizeof(reg[0]);
	
	printf("ELEMENTOS A SEREM ADICIONADOS:");
	for (int i = 0; i<tam;i++)
		printf(" %d ", reg[i]);
	printf("\n");

	for(int i=0; i<4; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}
	
	
	printf("\n\tORDEM CRESCENTE\n");
	showTreeInOrder(raiz);
	printf("\n");

	printf("Raiz : %d", raiz->reg.key);
	raiz->cor==1? printf(" (Vermelho) "): printf(" (Preto) ");
	printf("\tEsquerda : %d",raiz->esq->reg.key);
	raiz->esq->cor==1? printf("(Vermelho) "): printf("(Preto) ");
	printf("\tDireita : %d",raiz->dir->reg.key);
	raiz->dir->cor==1? printf(" (Vermelho) \n"): printf(" (Preto) \n");
	
	//r.key = 8;
	//removeTree(&raiz, NULL, r);
	
	//printf("%d ",raiz->reg.key);
	//printf("%d ",raiz->esq->reg.key);
	//printf("%d\n",raiz->dir->reg.key);

	
	return 0;
}