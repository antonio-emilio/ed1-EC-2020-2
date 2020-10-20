#ifndef __TASK_H__
#define __TASK_H__


#include "ProjectOrganizer.h"

#include "Label.h"


#define LABELS_MAX 4 


#define TASK_DISPLAY_WIDTH 20 
#define TASK_DISPLAY_HEIGHT 5

typedef char Title[TASK_DISPLAY_WIDTH];

typedef struct Task{

    Title title;
    Description description;
    boolean available_colors[NUMB_COLORS];


    Label_t* labels[LABELS_MAX];
    int numb_labels;


    WINDOW* win;

} Task_t;


Task_t* createTask(char* title, char* description);


Exception deleteTask(Task_t* t);


Exception addLabel(Task_t* t, Label_t* label);


Exception show(Task_t* t, unsigned int y, unsigned x, boolean selected);


Exception hide(Task_t* t);


boolean isDisplayed(Task_t* t);


Exception setDescription(Task_t* t, char* d);


Exception setTitle(Task_t* t, char* title);


char* getDescription(Task_t* t);


char* getTitle(Task_t* t);


#endif