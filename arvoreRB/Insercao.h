#ifndef _INSERCAO_
#define _INSERCAO_ 
#include "Cor.h"
#include "Rotacoes.h"
static int actions = 0;

void insert(Tree **t, Record r){
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->cor = 1;
    (*t)->reg    = r; 
    actions++;
    printf("[%d]%d adicionado.\n", actions, r.key);
  } else {
    if(r.key == (*t)->reg.key){
        printf("Valor Duplicado!\n");
        return;
    }else {
      if(r.key < (*t)->reg.key){
        insert(&(*t)->esq, r);
        
      }else{
        insert(&(*t)->dir, r); 
      }
    }
    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq) == 0){
      actions++;
      rotacaoSimplesEsquerda(t);
      printf("[%d]Rotação para a esquerda.\n", actions);
    }
    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq->esq) == 1){
      rotacaoSimplesDireita(t);
      printf("[%d]Rotação para a direita.\n", actions);
    }
    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq) == 1){
      trocaCor(t);
      printf("[%d]Troca de cor (%d <- %d -> %d).\n", actions, (*t)->esq->reg.key,(*t)->reg.key,(*t)->dir->reg.key);
    }
  }
}

void insertTree(Tree **t, Record r){
  insert(&(*t), r);
  if((*t) != NULL)
    (*t)->cor = 0;
}

#endif