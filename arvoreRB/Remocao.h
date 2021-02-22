#ifndef _REMOCAO_
#define _REMOCAO_

void antecessor(Tree **t, Tree *r){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, r);
		return;
  	}
  	
  	r->reg = (*t)->reg;
  	r = *t; 
  	*t = (*t)->esq;
  	free(r);
} 

void rebalanceTree(Tree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
	if((*t)->esq)
		left = getWeight(&(*t)->esq->esq) - getWeight(&(*t)->esq->dir);
	if((*t)->dir)
		right = getWeight(&(*t)->dir->esq) - getWeight(&(*t)->dir->dir);

	printf("Raiz:%d, Filho esq:%d, Filho dir:%d\n", balance, left, right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right >= 0)
		rotacaoDuplaEsquerda(t);
	if(balance == -2 && right < 0)
		rotacaoSimplesEsquerda(t);
  	
  	
}

void removeTree(Tree **t, Tree **f, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ 
		removeTree(&(*t)->esq, t, r); return;
	}
  	if (r.key > (*t)->reg.key){ 
		removeTree(&(*t)->dir, t, r); return;
	}

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	rebalanceTree(f);
    	return;
  	}

  	if ((*t)->esq != NULL){ 
  		antecessor(&(*t)->esq, *t); 
  		rebalanceTree(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
  	rebalanceTree(f);  	
  	
}

#endif