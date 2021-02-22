#ifndef _COR_
#define _COR_


int AcessarCor(Tree **t){
    if((*t) == NULL)
        return 0;
    return (*t)->cor;
}

void trocaCor(Tree **t){
    int cor = (*t)->cor;
    if(cor == 0)
        (*t)->cor = 1;
    else
        (*t)->cor = 0;

    if((*t)->esq)
        (*t)->esq->cor = cor;
    if((*t)-> dir)
        (*t)->dir->cor = cor;    
} 
#endif