#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0


typedef struct Elemento{
    char digit;
    struct Elemento *prox;

} Elemento_t;

typedef struct Pilha{
    Elemento_t* head;
    int size;
}Pilha_t;

typedef int bool;


void init(Pilha_t* p);

bool is_well_form(char* str);

int restart(Pilha_t* p);

int push(Pilha_t* p, char c);

char pop(Pilha_t* p);

char top(Pilha_t* p);

bool is_empty(Pilha_t* p);

bool is_in(char digit, char * array);

void size(Pilha_t* p, int* s);

void display(Pilha_t* p);

int main(){

    Pilha_t operators,  digits;
    init(&operators);
    init(&digits);


    char* op = "^+/*";
    char* trash_chars = "() ";
    char expression[10000];

    int m, s = 0, i = 0;        

    if(scanf("%d", &m)) 
        while (fgetc(stdin) != '\n'); // Read until a newline is found
    
        
    while(m)
    {
        i = 0;
        fgets(expression, 10000, stdin);

        if(is_well_form(expression))        
        {

            while(expression[i])
            {   
                if(is_in(expression[i], op))
                    push(&operators, expression[i]);

                else if(!is_in(expression[i], trash_chars))
                    push(&digits, expression[i]);
                

                
                if(digits.size >= 2 && !is_empty(&operators))
                {
                   
                    char right_digit = pop(&digits);
                    char left_digit = pop(&digits);

                    printf("%c%c", left_digit, right_digit);

                    while(!is_empty(&operators))
                    {
                        printf("%c", pop(&operators));

                    }
                } 
                i++;
            }

        }
        else printf("mal-formada\n");
        printf("\n");
        m--;
    }
   return 0;
}


void init(Pilha_t* p){
    p->head = NULL; 
    p->size = 0;
}


void display(Pilha_t* p){

    if(is_empty(p))
        return;
    else
    { 
        int x = top(p); 
        pop(p); 
        display(p);
        printf("%c\n", x);

        push(p, x); 
    } 
}


bool is_in(char digit, char* array){
    int i = 0;

    while(array[i])
    {
        if(digit == array[i])
            return True;

        i++;
    }

    return False;
}


bool is_well_form(char* str){
    Pilha_t p;
    init(&p);

    int i = 0;
    while(str[i])
    {
        if(str[i] == '(') push(&p, '(');

        else if (!is_empty(&p) && str[i] == ')') pop(&p);

        else if(is_empty(&p) && str[i] == ')') push(&p,'-'); 
        i++;
    }

    if(is_empty(&p)) return True;

    restart(&p);

    return False;
    
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


    novo_elemento->digit = c;
    novo_elemento->prox = p->head;
    p->head = novo_elemento;
    p->size ++;


    return 1;
}


bool is_empty(Pilha_t* p){ return ! p->head; }


char pop(Pilha_t* p){
    if(!p->head) return '\0';

    // top element
    Elemento_t* top = p->head;
    char c = top->digit;    
    p->head = top->prox;
    p->size --;
    free(top);

    return c;
}


char top(Pilha_t* p){
    return p->head->digit;
}