#ifndef __TASK_LIST_H__
#define __TASK_LIST_H__ 

#include "Task.h"


typedef struct Element{ 

    Task_t* task;
    struct Element* next;

} Element_t;


typedef struct TaskList{

    int num_tasks;
    Element_t* head;

} TaskList_t;


#endif