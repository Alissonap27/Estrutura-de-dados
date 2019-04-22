#include<stdio.h>
#include<stdlib.h>

typedef struct no_arv{
    int codigo;
    float valor;
    struct no_arv * esquerda;
    struct no_arv * direita;
}no_arv;

no_arv * create_new_element(int codigo, float valor){
    no_arv * novo = (no_arv *) malloc(sizeof(no_arv));
    novo->codigo = codigo;
    novo->valor= valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void insere_folha(no_arv ** arv, no_arv * novo){
   if (*arv == NULL){
     *arv = novo;
   }else{
     if(novo->codigo < (*arv)->codigo){
        insere_folha(&(*arv)->esquerda, novo);
     }else if(novo->codigo > (*arv)->codigo){
        insere_folha(&(*arv)->direita, novo);
     }
   }
}

//Caminhamento pos-ordem
void pos_ordem(no_arv * arv){
  if (arv != NULL) {
     pos_ordem(arv->esquerda);
     pos_ordem(arv->direita);
     printf("%d \n",arv->codigo);
  }
}

//Caminhamento pre-ordem
void pre_ordem(no_arv * arv){
  if (arv != NULL) {
     printf("%d \n",arv->codigo);
     pre_ordem(arv->esquerda);
     pre_ordem(arv->direita);
  }
}

//Caminhamento em-ordem
void em_ordem(no_arv * arv){
  if (arv != NULL) {
     em_ordem(arv->esquerda);
     printf("%d \n",arv->codigo);
     em_ordem(arv->direita);
  }
}

no_arv * maior_valor(no_arv * raiz){

    if (raiz == NULL){
       return NULL;
    }else{

   if (raiz != NULL) {
           printf("%.2f \n",raiz->valor);
        return maior_valor(raiz->direita);

        }
    }return raiz;
}



// Retorna o elemento contido na arvore
no_arv * pesquisar_nodo(no_arv * arv, int codigo){
    if (arv == NULL){
       return NULL;
    }else{
       if (codigo < arv->codigo){
          return pesquisar_nodo(arv->esquerda, codigo);
       }else{
            if (codigo > arv->codigo){
                return pesquisar_nodo(arv->direita, codigo);
            }else{
                return arv;
            }
       }
    }
}

int nivel_do_nodo(no_arv * arv, int codigo){
    int x;
    if (arv == NULL){
        return -1;
    }else{
        if (codigo < arv->codigo){
            x = nivel_do_nodo(arv->esquerda, codigo);
            if (x >= 0){
                return 1 + x;
            }else{
                return x;
            }
        }else{
            if (codigo > arv->codigo){
                x = nivel_do_nodo(arv->direita, codigo);
                if (x >= 0){
                    return 1 + x;
                }else{
                    return x;
                }
            }else{
                return 0;
            }
        }
    }
}


int contar_nodos(no_arv * arv){
   if (arv == NULL){
        return 0;
   }else{
        return 1 + contar_nodos(arv->esquerda) + contar_nodos(arv->direita);
   }
}

void monta_menu(){

   printf("//////////////////////////////////////////////////////////////// \n");
   printf("Operacoes sobre Arvores \n");
   printf("Selecione a opcao Desejada: \n");
   printf("   1 - Incluir Folha\n");
   printf("   2 - Caminhar Em Pre-Ordem \n");
   printf("   3 - Caminhar Em Ordem \n");
   printf("   4 - Caminhar Em Pos-Ordem \n");
   printf("   5 - Pesquisar nodos na Arvore \n");
   printf("   6 - Determinar o nivel de um nodo \n");
   printf("   7 - Contar nodos \n");
   printf("   8 - Maior Valor \n");
   printf("   0 - Sair \n");
   printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
   printf("Qual a sua opcao: ");
}

int main(){
  int op = 1;
  int nivel = 0;
  int codigo ;
  float valor;
  no_arv * aux= NULL;
  no_arv * arvore = NULL;
  no_arv * novo = NULL;

  do{
        monta_menu();
        scanf("%d", &op);
        system("cls");
        switch(op){
            case 1:
                printf("Informe o codigo a inserir na arvore: \n");
                scanf("%d", &codigo);
                printf("Informe o Valor a inserir na arvore: \n");
                scanf("%f", &valor);
                novo = create_new_element(codigo,valor);
                insere_folha(&arvore, novo);
                break;
            case 2:
                pre_ordem(arvore);
                break;
            case 3:
                em_ordem(arvore);
                break;
            case 4:
                pos_ordem(arvore);
                break;
            case 5:
                printf("Informe o numero a buscar na arvore: \n");
                scanf("%d", &codigo);
                novo = pesquisar_nodo(arvore, codigo);
                if (novo == NULL){
                    printf("Elemento nao esta na arvore. \n");
                }else{
                    printf("Elemento %d encontrado! \n", novo->codigo);
                }
                break;
            case 6:
                printf("Informe o numero a inserir na arvore: \n");
                scanf("%d", &codigo);
                printf("Elemento no nivel: %d \n", nivel_do_nodo(arvore, codigo));
                break;
            case 7:
                printf("Numero elementos na arvore = %d \n", contar_nodos(arvore));
                break;
            case 8:

                 aux=maior_valor(arvore);
                 if (aux == NULL){
                    printf("NULL \n");
                }else{
                    printf("Valor: %.2f\n", aux->valor);
                }
                break;
        }
    }while (op != 0);
}

