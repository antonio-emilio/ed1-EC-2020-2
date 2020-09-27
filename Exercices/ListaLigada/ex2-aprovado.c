#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef  int boolean;

boolean bye = FALSE;

typedef struct Elemento{

    int id;
    struct Elemento* link;

} Elemento_t;



typedef Elemento_t* Lista;

Lista arya = NULL;
// inserir 
void I(int p, int e, boolean init){

    Elemento_t* novo_elemento; 
    //caso não tenha elementos, insere na primeira posição
    if(arya == NULL)
    {
        novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));  

        novo_elemento->id = p;
        novo_elemento->link = NULL;

        arya = novo_elemento;

        if(!init) printf("inserido %d\n", p);
        return;
    }

    Elemento_t* atual = (Elemento_t*) arya;

        // caso tenha insere depois de 'e'
        while(atual)
        {

           if(atual->id == e)
           {

                novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));  

                novo_elemento->id = p;
                novo_elemento->link = atual->link;  

                atual->link = novo_elemento;
                if(!init) printf("inserido %d\n", p);
                return;
           } 

           atual = atual->link;
        }

        return;
};


// remover
void R(int p){

    Elemento_t* anterior = NULL;
    Elemento_t* atual = (Elemento_t*) arya;
    
    while(atual != NULL && atual->id != p){

        anterior = atual;
        atual = atual->link;

    }


    if(atual->id==p){


        if(anterior == NULL){
            arya = atual->link;
            free(atual);
            printf("removido %d\n", p);
        }else{
            anterior->link = atual->link;
            free(atual);
            printf("removido %d\n", p);
        }

    }


}


//contar entre dois outros elementos 
void C(int a, int b){
    Elemento_t* elemento = (Elemento_t*) arya;

    int distancia = 0;
    int e = 0;


    while(elemento)
    {
        if(a == elemento->id || b == elemento->id)
            e++;

        e && distancia++ ;

        if( e >= 2)
            break;
            

        elemento = elemento->link;
    }

    printf("quantidade %d\n", distancia - 2);

}


// mostrar
void M(){
    if(!arya)
        printf("lista vazia");
    else
        printf("lista ");

    Elemento_t* e = (Elemento_t*) arya;

    while(e)
    {
        printf("%d ", e->id);
        e = e->link;
    }
    printf("\n");
    

}

// terminar execução
void F(){
    // desalocar memoria

    bye = TRUE;
    printf("fim");
    
}


int main(){

    int n, p, e, i = 0;


    scanf("%d", &n);

    // inicializa lista
    while(n--)
    {
        scanf("%d", &p);
        I(p, i, TRUE);
        i = p;
    }

    char funcao;
    int p1, p2;

    while(!bye)
    {
        scanf("%c", &funcao); 

        switch (funcao)
        {
            case 'F':
                F();
                break;
            case 'R':
                scanf("%d", &p1);
                R(p1);
                break;
            case 'I': 
                scanf("%d %d", &p1, &p2);
                I(p1, p2, FALSE);
                break;
            case 'C':
                scanf("%d %d", &p1, &p2);
                C(p1, p2);
                break;
            case 'M':
                M();
            default:
                break;
        }

    }
    



    return 0;
}