#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct elemento{
    char c;
    struct elemento* prox;
    
} Elemento_t;

typedef Elemento_t* Pilha_t;
typedef int bool;

Pilha_t p = NULL;

int restart(Pilha_t* p);

int push(Pilha_t* p, char c);

char pop(Pilha_t* p);

char top(Pilha_t* p);

bool is_empty(Pilha_t p);


int main(){ 
    int i, j, n, m;
    bool is_possible = True;

    scanf("%d", &n);
    i = 1, j = n;

    while(n--)
    {
        scanf("%d", &m);
        if(m != i && m != j) is_possible = False;

        i++;
        j--;
    }

    is_possible ? printf("sim") : printf("nao");

    return 0;
}


int restart(Pilha_t* p){
    char c;

    do{
        c = pop(p);

    }while(c);

    return 1;
}


int push(Pilha_t* p, char c){

    Elemento_t* novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));
    if(!novo_elemento) return -1; 


    novo_elemento->c = c;
    novo_elemento->prox = *p;
    *p = novo_elemento;


    return 1;
}


bool is_empty(Pilha_t p){ return !p; }


char pop(Pilha_t* p){
    if(!*p) return '\0';

    // top element
    Elemento_t* top = *p;
    char c = top->c;    
    *p = top->prox;
    free(top);

    return c;
}


char top(Pilha_t* p){
    return (*p)->c;
}