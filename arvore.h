//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo que define o prototipo das funcoes da arvore
# ifndef ARVORE_BINARIA_H
# define ARVORE_BINARIA_H

typedef struct no {
    int dado;
    struct no *pai;
} No;

//acessar dado do no
int acessar_dado(No *T);

//adiciona o no A ao no B
void linkar(No *a, No *b);

//remove a aresta que liga o no pai de A com A
void cut(No *a);

//prototipo da funcao lca que recebe o no A, no B, o caminho_a que sera preenchido pelo caminho percorrido de A ate a raiz,
//O caminho_b sera preenchido pelo caminho percorrido de B ate a raiz, 
//tam1 que sera o tamanho do caminho_a e tam2 o tamanho do caminho_b
void lca(No *a, No *b, int caminho_a[], int caminho_b[], int *tam1, int *tam2);

//prototipo da funcao que calcula o caminho, recebe um No X, o caminho que sera preenchido pelo caminho percorrido de X ate a raiz
// e o tamanho desse caminho
void calcular_caminho(No *a, int caminho[], int *tam);

//verifica se o no tem pai
int tem_pai(No *T);

#endif