#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "Calc.h"

struct calc{
    char f[21];
    Pilha* p;
}

Calc* calc_cria (char* formato){
    Calc* c = (Calc*)malloc(sizeof(Calc));
    strycpy (c->f, formato);
    c-> = pilha_cria();
    return c;
}

void calc_operador (Calc* c, char op){
    float v1, v2, v;
    if (pilha_vazia(c->p))
        v2 = 0.0;
    else 
        v2 =pilha_pop(c->p);
    if(pilha_vazia(c->p))
        v1 = 0.0;
    else 
        v1 =pilha_pop(c->p);
}