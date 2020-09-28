#ifndef __TASK_H__
#define __TASK_H__

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

#include "Label.h"


#define INVALID_DESCRIPTION -1
#define INVALID_TITLE -2

typedef int STATUS;

#define TITLE_SIZE 256
#define DESCRIPTION_SIZE 1000
#define LABELS_MAX 4 

typedef char Description[DESCRIPTION_SIZE];
typedef char Title[TITLE_SIZE]; 

int TASKS_ID = 0; 

typedef struct Task{
    int id;

    Label_t labels[LABELS_MAX];
    Title title;
    Description description;

} Task_t;

Task_t* createTask(char* title, char* description);

Task_t* deleteTask(Task_t* t);

void setDescription(Task_t* t, char* d);

void setTitle(Task_t* t, char* title);

char* getDescription(Task_t* t);

char* getTitle(Task_t* t);

void showTask(Task_t* t);

#endif