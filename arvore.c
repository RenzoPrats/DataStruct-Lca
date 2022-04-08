//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo que define as funcoes da arvore
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

//acessa o dado do no T
int acessar_dado(No *T) {
    if(T == NULL) {
        return -1;
    }
    return T->dado;
}

//retorna 1 se tiver pai, 0 se nao tiver pai
int tem_pai(No *T){
    if(T->pai == NULL){
        return 0;
    }else{
        return 1;
    }
}

//torna o no B pai de A
void linkar(No *a, No *b){
    a->pai = b;
}

//remove a aresta que liga o no pai de A com A
void cut(No *a){
    a->pai = NULL;
}

//recebe os parametros e passa para a funcao calcular_caminho
void lca(No *a, No *b, int caminho_a[], int caminho_b[],int *tam1, int *tam2){
    calcular_caminho(a, caminho_a, tam1);
    calcular_caminho(b, caminho_b, tam2);
}

void calcular_caminho(No *T, int caminho[], int *tam){
    //enquanto o pai do no T for diferente de null
    if(T->pai != NULL){
        //adiciona o valor do pai do no T no vetor caminho
        caminho[(*tam)] = acessar_dado(T->pai);
        //acrescenta 1 ao tamanho da lista caminho
        (*tam)++;
        //retorna a funcao calcular_caminho passando o pai do no T como parametro
        calcular_caminho(T->pai, caminho, tam);
    }
}