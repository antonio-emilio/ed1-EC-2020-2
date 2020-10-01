#include <stdio.h>
#include <stdlib.h>


#define MAX_STRING_SIZE 1000 

typedef struct elemento{
    char c;
    struct elemento* prox;
    
} Elemento_t;

typedef Elemento_t* Pilha_t;
typedef int bool;

// pilha que sera usada no problema
Pilha_t p = NULL;

int restart(Pilha_t* p);

int push(Pilha_t* p, char c);

char pop(Pilha_t* p);

char top(Pilha_t* p);

bool is_empty(Pilha_t p);

int main(){

    char c[MAX_STRING_SIZE]; 
    int n, i;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", c);
        i = 0;

        restart(&p);

        while(c[i])
        {
            if(!is_empty(p) && top(&p) == c[i] - 2) pop(&p);

            else if(!is_empty(p) && top(&p) == c[i] - 1) pop(&p);

            else push(&p, c[i]);

            i++;
        }

        is_empty(p) ? printf("bem-formada\n") : printf("mal-formada\n");
    }


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