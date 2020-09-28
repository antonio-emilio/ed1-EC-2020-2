#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 256

#define ERROR -1
#define OK 0

#define True 1
#define False 0

typedef int STATUS;

typedef struct grandson{
    char name[NAME_SIZE];

    struct grandson* prev;
    struct grandson* next;

}Grandson_t;

typedef Grandson_t* GrandChildren_t;


STATUS insertGrandson(GrandChildren_t* gc, char* name){

    Grandson_t* new_grandson = (Grandson_t*) malloc(sizeof(Grandson_t));
    if(!new_grandson) return -1;
    
    strcpy(new_grandson->name, name);


    if(!*gc)
    {
        new_grandson->next = new_grandson;
        new_grandson->prev = new_grandson;
        *gc = new_grandson;

        return OK;
    }


    Grandson_t* head = *gc; 

    new_grandson->next = head;
    new_grandson->prev = head->prev;
    new_grandson->prev->next = new_grandson;

    head->prev = new_grandson;

    return OK;
}

STATUS removeClockwise(GrandChildren_t* gc, char* name){
    int i = 0;

    Grandson_t* gs = *gc; 

    while(i < 3 && gs)
    {

        if(!strcmp(gs->name, name))
        {
            if (*gc == gs) 
                *gc = gs->next; 
        
            if (gs->next != NULL) 
                gs->next->prev = gs->prev; 
        
            if (gs->prev != NULL) 
                gs->prev->next = gs->next; 
        
            free(gs);    

            return OK;
        }

        gs = gs->next;
        i++;
    }

    return ERROR;
}

STATUS removeAntiClockwise(GrandChildren_t* gc, char* name){

    int i = 0;

    Grandson_t* gs = *gc; 

    while(i < 3 && gs)
    {
        if(!strcmp(gs->name, name))
        {
            if (*gc == gs) 
                *gc = gs->next; 
        
            if (gs->next != NULL) 
                gs->next->prev = gs->prev; 
        
            if (gs->prev != NULL) 
                gs->prev->next = gs->next; 
        
            free(gs); 

            return OK;
        }

        gs = gs->prev;
        i++;
    }

    return ERROR;
}

void showGrandsonsClockwise(GrandChildren_t gc){
    Grandson_t* gs = gc; 
    int i = 60;

    while(True)
    {
        gs = gs->prev;
        if(gs == gc) break;
    }
}



int main(){
    int points = 0;
    int status;
    GrandChildren_t gc = NULL;

    insertGrandson(&gc, "vovo");

    char name[NAME_SIZE]; 
    char direction[NAME_SIZE];  
    int numb_grandsons = 0;

    while(True)
    {
        scanf("%s", name);
        if(!strcmp(name, "FIM"))
            break;

        insertGrandson(&gc, name);
        numb_grandsons++;
    }

    while(numb_grandsons--)
    {
        scanf("%s %s", name, direction);

        if(!strcmp(direction, "horario"))
            status = removeClockwise(&gc, name);
        else
            status = removeAntiClockwise(&gc, name);

        status == OK && points++;
    }

    printf("%d", points);


    return 0;
}