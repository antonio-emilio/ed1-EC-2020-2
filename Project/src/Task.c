#include "Task.h" 


Task_t* createTask(char* title, char* description){
    if(strlen(title) >= TITLE_SIZE || strlen(description) >= DESCRIPTION_SIZE)
        return (Task_t*) INVALID_INPUT_EXCEPTION;

    // aloca memória 
    Task_t* new_task = (Task_t*) malloc(sizeof(Task_t));
    if(!new_task) return (Task_t*) MEMORY_ALOCATION_EXCEPTION;

    // atribui os valores 
    setDescription(new_task, description);
    setTitle(new_task, title);
    new_task->numb_labels = 0;


    return new_task;
}


Exception deleteTask(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION;

    free(t);
    return SUCCESS;
}


/* adiciona uma label para a task especifica */
Exception addLabel(Task_t* t, Label_t* label){
    if(!t || !label || t->numb_labels >= LABELS_MAX) return INVALID_INPUT_EXCEPTION;

    t->labels[t->numb_labels++] = *label;
}


// settters

Exception setDescription(Task_t* t, char* d){
    if(!t || strlen(d) >= DESCRIPTION_SIZE) return INVALID_INPUT_EXCEPTION;

    strcpy(t->description, d);
    return SUCCESS;
}


Exception setTitle(Task_t* t, char* title){
    if(!t || strlen(title) >= TITLE_SIZE) return INVALID_INPUT_EXCEPTION;

    strcpy(t->title, title);
    return SUCCESS;
}


// getters
char* getDescription(Task_t* t){
    return !t ? (char*) INVALID_INPUT_EXCEPTION : t->description;
}


char* getTitle(Task_t* t){
    return !t ? (char* ) INVALID_INPUT_EXCEPTION : t->title;
}

