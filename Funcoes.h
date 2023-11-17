#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct No
    {
        int num;
        struct No *esq;
        struct No *dir;

    };
    //renomear no
typedef struct No no;
typedef no *ArvBin;

ArvBin* criarArvBin(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if (raiz != NULL){
        *raiz = NULL;
    }
    else{
        printf("erro de alocação");
        exit(0);
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz,int *contElite,int *cont18,int *cont19a29,int *cont30a39,int *cont40){
    int opcao;
    no *novo = (no *) malloc (sizeof(no));
    if (novo == NULL){
        printf("sem memoria disponivel");
        exit(0);
    }
    do{
        MenuInsercao(&opcao);
        switch (opcao){
        case 1:
            novo->num = (*contElite);
            (*contElite)++;
            break;
        case 2:
            novo->num = (*cont18);
            (*cont18)++;
            break;
        case 3:
            novo->num = (*cont19a29);
            (*cont19a29)++;
            break;
        case 4:
            novo->num = (*cont30a39);
            (*cont30a39)++;
            break;
        case 5:
            novo->num = (*cont40);
            (*cont40)++;
            break;
        case 0:
            printf("Voce Optou por cancelar a inscricao");
            break;
        default:
            printf("Opcao Invalida!");
            break;
        }
        if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5){
            opcao=-1;
        }
        if (opcao==0){
            break;
        }
        
    } while (opcao!=-1);
    novo->dir = NULL;
    novo->esq = NULL;
    if (*raiz==NULL){
        *raiz = novo;
    }
    else{
        no *atual = *raiz;
        no *ant = NULL;

        while (atual != NULL){
            ant = atual;
            if (novo->num == atual->num){
                printf("Numero Ja Existente");
                free(novo);
                return 0;
            }
            if (novo->num > atual->num){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(novo->num > ant->num){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
}
void libera_NO(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }
    else{
        libera_NO(no_liberar->esq);
        libera_NO(no_liberar->dir);
        free(no_liberar);
    }
}

int libera_ArvBin(ArvBin* raiz){
    if(raiz==NULL){
        printf("Arvore Liberada");
        return 0;
    }
    else{
        libera_NO(*raiz);
    }
    free(raiz);
}

void Pos_Ordem(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }
    else{
        Pos_Ordem(no_liberar->esq);
        Pos_Ordem(no_liberar->dir);
        printf("%d\n", no_liberar->num);
    }
}

int Pos_Ordem_chamar(ArvBin* raiz){
    if(raiz==NULL){
        printf("Arvore vazia");
        return 0;
    }
    else{
        Pos_Ordem(*raiz);
    }

}
void Pre_Ordem(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }
    else{
        printf("%d\n", no_liberar->num);
        Pre_Ordem(no_liberar->esq);
        Pre_Ordem(no_liberar->dir);
    }
}

int Pre_Ordem_chamar(ArvBin* raiz){
    if(raiz==NULL){
        printf("Arvore vazia");
        return 0;
    }
    else{
        Pre_Ordem(*raiz);
    }

}
void In_Ordem(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }
    else{
        In_Ordem(no_liberar->esq);
        printf("%d\n", no_liberar->num);
        In_Ordem(no_liberar->dir);
    }
}

int In_Ordem_Chamar(ArvBin* raiz){
    if(raiz==NULL){
        printf("Arvore vazia");
        return 0;
    }
    else{
        In_Ordem(*raiz);
    }

}

void Contar_No(no *no_liberar,int *Contador){
    if(no_liberar == NULL){
            return;
    }
    else{
        Contar_No(no_liberar->esq,Contador);
        (*Contador)++;
        Contar_No(no_liberar->dir,Contador);
    }   
}


int Contar_No_Chamar(ArvBin* raiz, int *Contador){
    if(raiz==NULL){
        return 0;
    }
    else{
        Contar_No(*raiz,Contador);
    }
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return 0;
    }
    if (*raiz == NULL){
        return - 1;
    }
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    
    if (alt_esq > alt_dir) {
        return alt_esq + 1;
    } 

    else {
        return alt_dir + 1;
    }
}

struct No* remove_atual(struct No* atual){
    no *no1,*no2;
    if (atual->esq==NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if (no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
    if (raiz == NULL){
        return 0;
    }
    struct No* ant = NULL;
    struct No* atual = *raiz;
    while (atual != NULL){
        if (valor == atual->num){
            if (atual== *raiz){
                *raiz = remove_atual(atual);
            }
            else{
                if (ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }
                else{
                    ant->esq = remove_atual(atual);
                }
                
            }
            return 1;
        }
        ant = atual;
        if (valor> atual->num){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    int esquerda,direita;
    if (raiz == NULL){
        return 0;
    }
    struct No* atual = *raiz;
    while (atual!=NULL){
        if (valor == atual->num){
            if (atual->esq==NULL){
                esquerda = -1;
            }
            else{
                esquerda = atual->esq->num;
            }
            if (atual->dir==NULL){
                direita = -1;
            }
            else{
                direita = atual->dir->num;
            }
            printf("\n");
            printf("    %d \n",atual->num);
            printf("  /    \\ \n");
            printf("%d      %d    \n",esquerda,direita);
            printf("\n-1 = NULL\n");
            return 1;
        }
        if (valor>atual->num){
            atual= atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}


void MenuInsercao(int *opcao){
        printf("\n====================================\n");
        printf("MENU INSERCAO\n");
        printf("1 - Categoria Elite\n");
        printf("2 - Categoria ate 18 anos\n");
        printf("3 - Categoria de 19 a 29 anos\n");
        printf("4 - Categoria de 30 a 39 anos\n");
        printf("5 - Categoria acima de 40 anos\n");
        printf("0 - Sair\n");
        printf("====================================\n");
        printf("Digite a Opcao: ");
        scanf("%d", opcao);

}
void MenuPrincipal(int *opcao){
        printf("\n====================================\n");
        printf("MENU\n");
        printf("1 - Inserir Elementos\n");
        printf("2 - Imprimir Pre-Ordem\n");
        printf("3 - Imprimir In-Ordem\n");
        printf("4 - Imprimir Pos-Ordem\n");
        printf("5 - Contar Elementos\n");
        printf("6 - Liberar Arvore\n");
        printf("7 - Altura Arvore\n");
        printf("8 - Consultar Elemento\n");
        printf("9 - Remover Elemento\n");
        printf("0 - Sair\n");       
        printf("====================================\n");
        printf("Digite a Opcao: ");
        scanf("%d", opcao);

}