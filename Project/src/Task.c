#include "Task.h" 




Task_t* createTask(char* title, char* description){

    if(strlen(title) >= TASK_DISPLAY_WIDTH)
        return (Task_t*) INVALID_INPUT_EXCEPTION;


    // aloca memória 
    Task_t* new_task = (Task_t*) malloc(sizeof(Task_t));
    if(!new_task) return (Task_t*) MEMORY_ALOCATION_EXCEPTION;


    // atribui os valores 
    setDescription(new_task, description);
    setTitle(new_task, title);

    new_task->numb_labels = 0;
    new_task->win = NULL;


    return new_task;
}




Exception deleteTask(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION;

    free(t);
    return SUCCESS;
}




Exception addLabel(Task_t* t, Label_t* label){
    if(!t || !label || t->numb_labels >= LABELS_MAX) return INVALID_INPUT_EXCEPTION;

    t->labels[t->numb_labels++] = label;
}




Exception show(Task_t* t, unsigned int y, unsigned x){
    if(!t) return INVALID_INPUT_EXCEPTION; 


    t->win = newwin(TASK_DISPLAY_HEIGHT, TASK_DISPLAY_WIDTH, y, x);    
    refresh();

    box(t->win, 0, 0);


    int title_len = strlen(t->title);

    wmove(t->win, 0, (TASK_DISPLAY_WIDTH - title_len)/2);
    wprintw(t->win, "%s", t->title);

    wrefresh(t->win);

}




Exception hide(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION; 

    //TODO: implement
    
}




boolean isDisplayed(Task_t* t){
    return (boolean) t->win;
}




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




char* getDescription(Task_t* t){

    return !t ? (char*) INVALID_INPUT_EXCEPTION : t->description;
}




char* getTitle(Task_t* t){

    return !t ? (char* ) INVALID_INPUT_EXCEPTION : t->title;
}




