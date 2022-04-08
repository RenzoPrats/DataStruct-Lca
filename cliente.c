//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo com a funcao main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main() {
    //declarando as variaveis n e m
    int n, m;
    //recebendo o valor de n e m
    scanf("%d %d", &n, &m);
    //criando a floresta com n arvores
    No *floresta = (No *) malloc(n * sizeof(No));

    //criando as n arvores da floresta
    for(int y = 0; y < n; y++){
        floresta[y] = (No) {y+1, NULL};
    }
    //para cada operacao
    for(int i = 0; i < m; i++){
        //cria as variaveis a e b
        int a, b = 0;
        //armazena o comando da operacao
        char *comando = (char *) malloc(4 * sizeof(char));
        scanf("%s", comando);

        //se o comando for cut
        if(strcmp(comando, "cut") == 0){
            //recebe apenas o valor de a
            scanf("%d", &a);
            //se existir pai da arvore que tem o valor de A 
            if(tem_pai(&floresta[a-1]) == 1){
                //remove a aresta que liga o no pai de A com A
                cut(&floresta[a-1]);
            }
        
        //se o comando for lca
        }else if(strcmp(comando, "lca") == 0){
            //recebe A e B
            scanf("%d %d", &a, &b);
            //aloca o caminho A e B
            int *caminho_a = (int *) malloc((n*2) * sizeof(int));
            int *caminho_b = (int *) malloc((n*2) * sizeof(int));
            //cria os ponteiros tam1 e tam2 que apontaram para u e w respectivamente
            int u = 0;
            int w = 0;
            int *tam1 = &u;
            int *tam2 = &w;
            //se A igual B, o lca eh o proprio A
            if(a == b){
                printf("%d\n", a);
            }else{
                //adiciona no caminho_a o proprio A, e aumenta o tamanho desse caminho
                caminho_a[(*tam1)] = a;
                (*tam1)++;

                //adiciona no caminho_b o proprio B, e aumenta o tamanho desse caminho
                caminho_b[(*tam2)] = b;
                (*tam2)++;

                //chama a funcao lca que recebe o no A, B, o caminho_a, o caminho_b, tam1 e tam2
                lca(&floresta[a-1], &floresta[b-1], caminho_a, caminho_b, tam1, tam2);
                
                int ajudante = 0;
                //a funcao lca preenchera os vetores que contem o caminho_a que eh o caminho percorrido de A ate a raiz
                // e o caminho_b que eh o caminho percorrido de B ate a raiz
                //se olharmos esses vetores do fim para o comeco, conseguiremos ver o caminho da raiz ate o no
                //com base nisso eh possivel verificar ate onde o caminho eh igual e esse sera o LCA
                //por fim quando os caminhos forem diferentes printaremos o ultimo que foi igual
                while( (*tam1) >= 0 && (*tam2) >= 0 ){
                    if(caminho_a[(*tam1)-1] == caminho_b[(*tam2)-1]){
                        ajudante = caminho_a[(*tam1)-1];
                    }else{
                        break;
                    }
                    (*tam1)--;
                    (*tam2)--;
                }

                printf("%d\n", ajudante);
                *tam1 = 0;
                *tam2 = 0;       
                
            }

            //desaloca o caminho_a e caminho_b
            free(caminho_a);
            free(caminho_b);
        
        //se o comando for link
        }else if (strcmp(comando, "link") == 0){
            //recebemos A e B
            scanf("%d %d", &a, &b);
            //se A eh diferente de B podemos entao linkar
            if(a!=b){
                linkar(&floresta[a-1], &floresta[b-1]);
            }
        }
        //desaloca comando
        free(comando);
    }
    //desaloca a floresta
    free(floresta);
    return 0;
}