#include "lista.c"

/*
struct lista {

    float info;
    struct lista * prox;

};

typedef struct lista Lista;
*/

Pilha * pilha_cria(void){
    Pilha *p = (pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push (Pilha* p, float v){
    Lista* n= (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->info = p->prim;
    p->prim = n;

}

float pilha_pop(Pilha* p){
    Lista* t;
    float v;
    if (pilha_vazia(p)){
        printf("Pilha vazia \n");
        exit(1);
    }

    t = p->prim;
    v = t->info;
    p-> prim = t->prox;
    free(t);
    return v;
}

int pilha_vazia(Pilha *p){
    return (p->prim == NULL);
}

lst_libera (p->prim);
