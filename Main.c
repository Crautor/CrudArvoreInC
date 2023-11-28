#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"



int main() {
    no *raiz = criarArvBin();
    int opcao,valor,contElite=1,cont18=101,cont19a29=201,cont30a39=301,cont40=401,contador=0;
    do{
        MenuPrincipal(&opcao);
        

        switch (opcao){
            case 1:
                // insert
                insere_ArvBin(raiz,&contElite,&cont18,&cont19a29,&cont30a39,&cont40);
                break;
            case 2:
                // pre ordem
                Pre_Ordem_chamar(raiz);
                break;  
            case 3:
                // in ordem
                In_Ordem_Chamar(raiz);
                break;
            case 4:
                // pos ordem
                Pos_Ordem_chamar(raiz);
                break;
            case 5:
                // contar no
                Contar_No_Chamar(raiz,&contador);
                printf("%d\n", contador);
                break;
            case 6:
                // liberar
                libera_ArvBin(raiz);
                break;
            case 7:
                // altura
                printf("\n %d \n ",altura_ArvBin(raiz)); 
                break;
            case 8:
                // read
                printf("informe o numero a ser consultado: ");
                scanf("%d",&valor);
                consulta_ArvBin(raiz,valor);
                break;
            case 9:
                // remove
                printf("informe o numero a ser removido: ");
                scanf("%d",&valor);
                remove_ArvBin(raiz,valor);
                break;
            case 10:
                // update
                printf("informe o numero a ser atualizado: ");
                scanf("%d",&valor);
                remove_ArvBin(raiz,valor);
                insere_ArvBin(raiz,&contElite,&cont18,&cont19a29,&cont30a39,&cont40);
                break;

            case 11:
                balancearArvore(raiz,&contador);
                break;
            case 0:
                printf("Voce decidiu parar!");
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                break;
        }   
        

    } while (opcao != 0);
    libera_ArvBin(raiz);

}

