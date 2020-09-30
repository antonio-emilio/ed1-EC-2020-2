#ifndef __TASK_H__
#define __TASK_H__

/*
    Uma task contém todas as informações de uma
    determinada atividade. 
*/
#include "projectOrganizer.h"

#include "Label.h"

// número máximo de labels que uma task pode ter 
#define LABELS_MAX 4 

#define TASK_HEIGHT 6
#define TASK_WIDTH 30

typedef WINDOW* TASK_WIN; 

typedef struct Task{

    Title title;
    Description description;

    Label_t labels[LABELS_MAX];
    int numb_labels;

} Task_t;

/* constructor */
Task_t* createTask(char* title, char* description);

/* destructor */
Exception deleteTask(Task_t* t);

/* adiciona uma label para a task especifica */
Exception addLabel(Task_t* t, Label_t* label);


// setters
Exception setDescription(Task_t* t, char* d);

Exception setTitle(Task_t* t, char* title);


// getters
char* getDescription(Task_t* t);

char* getTitle(Task_t* t);


#endif