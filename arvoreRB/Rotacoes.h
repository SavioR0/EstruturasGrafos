#ifndef _ROTACOES_
#define _ROTACOES_

void rotacaoSimplesEsquerda(Tree **t){
	Tree *aux;
	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	aux->cor = (*t)->cor;
	(*t)->cor = 1;
	(*t) = aux;
}

void rotacaoSimplesDireita(Tree **t){
	Tree *aux;
	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	aux->cor = (*t)->cor;
	(*t)->cor = 1;
	(*t) = aux;
}

/*
void rotacaoDuplaDireita(Tree **t){
	rotacaoSimplesEsquerda(&(*t)->esq);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(Tree **t){
	rotacaoSimplesDireita(&(*t)->dir);
	rotacaoSimplesEsquerda(t);
}
*/

#endif