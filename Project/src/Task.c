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

    // init labels
    for(int i = 0; i < LABELS_MAX; i++)
        new_task->labels[i] = NULL;

    new_task->win = NULL;


    return new_task;
}




Exception deleteTask(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION;

    if(isDisplayed(t)) hide(t);

    free(t);
    return SUCCESS;
}




Exception addLabel(Task_t* t, Label_t* label){
    if(!t || !label || t->numb_labels >= LABELS_MAX) return INVALID_INPUT_EXCEPTION;

    t->labels[t->numb_labels] = label;
    t->numb_labels++;
}




Exception removeLabel(Task_t* t, LabelName label_name){
    for(int i = 0; i < t->numb_labels; i++)
    {
        if(!strcmp(t->labels[i]->name, label_name)) 
        {
            deleteLabel(t->labels[i]);

            t->labels[i] = NULL;

            for(int i = 0; i < LABELS_MAX - 1; i++)
                t->labels[i] = t->labels[i + 1];

            t->numb_labels--;

            return SUCCESS; 
        }
        
    }

}




Exception show(Task_t* t, unsigned int y, unsigned x, boolean selected){
    if(!t) return INVALID_INPUT_EXCEPTION; 

    if(!t->win) 
        t->win = newwin(TASK_DISPLAY_HEIGHT, TASK_DISPLAY_WIDTH, y, x);    

    refresh();

    box(t->win, 0, 0);

    int title_len = strlen(t->title);

    // move to the center of the component
    wmove(t->win, 0, (TASK_DISPLAY_WIDTH - title_len)/2);

    // print the title
    if(selected)
    {
        wattron(t->win, A_REVERSE);
        wprintw(t->win, "%s", t->title);
        wattroff(t->win, A_REVERSE);
    }
    else wprintw(t->win, "%s", t->title);


    // display the labels if there are any 
    if(t->numb_labels)
    {
        for(int i = 0; i < t->numb_labels && i < TASK_DISPLAY_HEIGHT - 2; i++)
        {
            Color label_color = t->labels[i]->color;
            LabelName label_name;

            strcpy(label_name, t->labels[i]->name);
            wmove(t->win, 1 + i, 1);
            if(!INIT_PAIRS[label_color])
                init_pair(label_color, COLOR_BLACK, label_color);

            // toggles the color attribute 
            wattron(t->win, COLOR_PAIR(label_color));
            wprintw(t->win, "%s",label_name);
            wattroff(t->win, COLOR_PAIR(label_color));
        }

        // in case there are more labels but not enough space we display "..."
        if(t->numb_labels >= TASK_DISPLAY_HEIGHT - 2)
                wprintw(t->win, "%s", "...");
    }

    wrefresh(t->win);
}




Exception hide(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION; 

    // erase what's inside the window
    for(int i = 0; i < TASK_DISPLAY_HEIGHT; i ++)
        for( int j = 0; j < TASK_DISPLAY_WIDTH; j++)
        {
            wmove(t->win, i, j);
            wprintw(t->win, " ");
        }

    wborder(t->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // Erase frame around the window
    wrefresh(t->win); 
    delwin(t->win);
    t->win = NULL;
}




boolean isDisplayed(Task_t* t){
    return t->win ? True : False;
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




