#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct elemento{
    char c;
    struct elemento* prox;
    
} Elemento_t;

typedef Elemento_t* Pilha_t;
typedef int bool;

// pilha que sera usada no problema
Pilha_t p = NULL;

int push(Pilha_t* p, char c);

char pop(Pilha_t* p);

char top(Pilha_t* p);

bool is_empty(Pilha_t p);

int main(){
    int i = 0;
    char c[1010];

    scanf("%s", c);

    while(c[i])
    {
        if(c[i] == '(') push(&p, '(');

        else if (!is_empty(p) && c[i] == ')') pop(&p);

        else if(is_empty(p) && c[i] == ')') push(&p,'-'); 
        i++;
    }

    !is_empty(p) ? printf("incorreta") : printf("correta");

        
    return 0;
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