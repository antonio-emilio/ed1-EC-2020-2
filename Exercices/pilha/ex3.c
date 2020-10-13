#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct elemento{
    int n;
    struct elemento* prox;
    
} Elemento_t;

typedef Elemento_t* Pilha_t;

typedef int bool;

Pilha_t p1;


int restart(Pilha_t* p);

int push(Pilha_t* p, int c);

int pop(Pilha_t* p);

int top(Pilha_t p);

int size(Pilha_t* p);

int insertBottom(Pilha_t* p, int i);

int main(){ 
    int i;

    while(True)
    {
        scanf("%d", &i);
        if(!i)
            break;
        else
            push(&p1, i);
    }

    while(True)
    {
        scanf("%d", &i);
        if(!i)
            break;
        else
            insertBottom(&p1, i);
    }

    restart(&p1);

    return 0;
}




int restart(Pilha_t* p){
    int c;

    while(True)
    {
        c = pop(p);
        if(!c) break;

        printf("%d\n", c);
    }


    return 1;
}


int push(Pilha_t* p, int c){

    Elemento_t* novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));
    if(!novo_elemento) return -1; 


    novo_elemento->n = c;
    novo_elemento->prox = *p;
    *p = novo_elemento;


    return 1;
}


bool is_empty(Pilha_t p){ return !p; }


int pop(Pilha_t* p){
    if(!*p) return '\0';

    Elemento_t* top = *p;
    int c = top->n;    
    *p = top->prox;
    free(top);

    return c;
}


int top(Pilha_t p){
    return p->n;
}

int insertBottom(Pilha_t* p, int i){

    if(is_empty(*p))
       push(p, i); 
    else
    { 
        int x = top(p); 
        pop(p); 
        insertBottom(p, i); 

        push(p, x); 
    } 
}

