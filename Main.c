#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"



int main() {
    no *raiz = criarArvBin();
    int opcao, contElite=1,cont18=101,cont19a29=201,cont30a39=301,cont40=401,contador,alt_dir=0,alt_esq=0;
    do{
        MenuPrincipal(&opcao);
        

        switch (opcao){
            case 1:
                insere_ArvBin(raiz,&contElite,&cont18,&cont19a29,&cont30a39,&cont40);
                break;
           case 2:
                Pre_Ordem_chamar(raiz);
                break;  
            case 3:
                In_Ordem_Chamar(raiz);
                break;
            case 4:
                Pos_Ordem_chamar(raiz);
                break;
            case 5:
                Contar_No_Chamar(raiz,&contador);
                printf("%d\n", contador);
                break;
            case 6:
                libera_ArvBin(raiz);
                break;
            case 7:
                printf("\n %d \n ",altura_ArvBin(raiz)); 
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

