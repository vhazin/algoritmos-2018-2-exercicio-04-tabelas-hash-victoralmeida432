#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
}aLista;

void addItem(aLista **listinha, int chave, int hash){
    aLista *ponteiro = (aLista *)malloc(sizeof(aLista));
    ponteiro -> num = chave;
    ponteiro -> prox = NULL;
    if(listinha[hash] == NULL){
        listinha[hash] = ponteiro;
    }else{
        aLista *aux = listinha[hash];
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux -> prox = ponteiro;
    }
}
void Item(aLista **listinha, int i){
    printf("%d -> ",i);
    aLista *ponteiro = listinha[i];
    while(ponteiro != NULL){
        printf("%d -> ", ponteiro->num);
        ponteiro = ponteiro->prox;
    }
    printf("\\\n");
}

int main(void){
    int nt, tl, nk;
    scanf("%d",&nt);
    
    while(nt--){
        aLista *listinha[99] = {NULL}; 
        scanf("%d %d", &tl,&nk);
    
        for(; nk > 0;nk--){
            int chave;
            scanf("%d", &chave);
            int hash = chave % tl;
            addItem(listinha,chave,hash);
        }

        for (int i = 0; i < tl; i++){
            Item(listinha, i);
        }

        if(nt > 0){ 
            printf("\n");
        }

        free(listinha[tl]);
    }
    return 0;

}
