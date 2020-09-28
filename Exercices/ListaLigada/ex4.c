#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 256

typedef struct grandson{
    char name[NAME_SIZE];

    struct grandson* prev;
    struct grandson* next;

}Grandson_t;

typedef Grandson_t* GrandChildren_t;


int insertGrandson(GrandChildren_t* gc, char* name){

    Grandson_t* new_grandson = (Grandson_t*) malloc(sizeof(Grandson_t));
    if(!new_grandson) return -1;

    strcpy(new_grandson->name, name);

    if(!*gc)
    {
        new_grandson->next = new_grandson;
        new_grandson->prev = new_grandson;

        return 0;
    }

    Grandson_t* head = *gc; 

    new_grandson->next = head;
    new_grandson->prev = head->prev;
    new_grandson->prev->next = new_grandson;

    head->prev = new_grandson;

    return 0;
}

int removeClockwise(GrandChildren_t* gc, char* name){
    int i = 0;

    Grandson_t* gs = *gc; 

    while(i < 1 && gs)
    {
        if(!strcmp(gs->name, name))
        {
            //remove grandson...

            return 0;
        }

        gs = gs->next;
    }

    return -1;
}

int removeAntiClockwise(GrandChildren_t* gc, char* name){
    int i = 0;

    Grandson_t* gs = *gc; 

    while(i < 1 && gs)
    {
        if(!strcmp(gs->name, name))
        {
            //remove grandson...

            return 0;
        }

        gs = gs->prev;
    }

    return -1;
}



int main(){
    GrandChildren_t gc;

    insertGrandson(&gc, "vovó");



    return 0;
}