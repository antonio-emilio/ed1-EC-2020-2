#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_SIZE 12
#define NAME_SIZE 25


#define True 1
#define False 0

typedef int boolean;

boolean bye = False;

typedef struct Person{
    
    char phone[PHONE_SIZE];
    char name[NAME_SIZE];    
    struct Person* next;
    int v;

} Person_t;


typedef Person_t* List_t;


void swapPeople(Person_t* p1, Person_t* p2)
{
    char name[NAME_SIZE], phone[PHONE_SIZE];
    int v;

    strcpy(name, p2->name);
    strcpy(phone, p2->phone);
    v = p2->v;

    strcpy(p2->name, p1->name);
    strcpy(p2->phone, p1->phone);
    p2->v = p1->v;

    strcpy(p1->name, name);
    strcpy(p1->phone, phone);
    p1->v = v;
}

void sortList(List_t* l){
    Person_t* p1;
    Person_t* p2; 

    for(p1 = *l; p1; p1 = p1->next)
    {
        for(p2 = p1; p2; p2 = p2->next)
        {
            if(p1->v < p2->v)
                swapPeople(p1, p2);
        }
    }

}



void insertPerson(List_t* l, char* name, char* phone, int v){

    Person_t** person = (Person_t**) l;

    while(*person)
        person = (Person_t**) &(*person)->next;

    Person_t* new_person = (Person_t*)  malloc(sizeof(Person_t)); 
    if(!new_person) return;

    strcpy(new_person->phone, phone);
    strcpy(new_person->name, name);

    new_person->v = v;
    new_person->next = NULL;

    *person = new_person;

};

void removePerson(List_t* l, char* name){

    Person_t* current = *l;
	Person_t** prev = l;

	while(current){

		if(!strcmp(current->name, name)){

			*prev = (Person_t*) current->next;
			free(current);
			return;
		}

		prev = (Person_t**) &(current->next);
		current =(Person_t*) current->next;
	}

}

void incrementPerson(List_t* l, char* name){

     Person_t* person = *l;

	while(person)
    {

		if(!strcmp(person->name, name))
        {
            person->v++;
            break;
        }
        person = person->next;
    } 

}

void printList(List_t* l)
{
    Person_t* person = *l;

	while(person)
    {
        printf("%s - %s %d\n", person->name, person->phone, person->v);
        
        person = person->next;
    }

}



int main(){
    List_t l = NULL;
    char func, name[NAME_SIZE], phone[PHONE_SIZE];
    int v;

    insertPerson(&l,"Hermanoteu", "4523-2248", 300);
    insertPerson(&l,"Ooloneia", "4523-4887", 299);


    while(!bye)
    {
        scanf("%c", &func);

        switch (func)
        {
        case 'F':
            bye = True;
            break;

        case 'I':
            scanf("%s %s %d", name, phone, &v);
            insertPerson(&l, name, phone, v);
            break;

        case 'R':
            scanf("%s", name);
            removePerson(&l, name);
            break;

        case 'L':
            scanf("%s", name);
            incrementPerson(&l, name);

        }
    }

    sortList(&l);
    printList(&l);

    return 0;
}