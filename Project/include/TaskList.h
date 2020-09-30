#ifndef __TASK_LIST_H__

#define __TASK_LIST_H__ 

#include "projectOrganizer.h"

#include "Task.h"


typedef struct Element{ 
    Task_t task;
    struct Element* next;
} Element_t;

typedef Element_t* TaskList_t; 


#endif