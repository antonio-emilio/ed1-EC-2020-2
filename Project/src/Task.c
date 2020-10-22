#include "Task.h" 




/* 
    Allocates memory for the new task 
    being created and init default values 
*/
Task_t* createTask(char* title, char* description){

    if(strlen(title) >= TASK_DISPLAY_WIDTH)
        return NULL;


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
    
    // init available colors
    for(int i = 0; i < NUMB_COLORS; i++)
        new_task->available_colors[i] = True;

    new_task->win = NULL;


    return new_task;
}



/* dealocates memory of task */ 
Exception deleteTask(Task_t* t){
    if(!t) return INVALID_INPUT_EXCEPTION;
    
    if(isDisplayed(t)) hide(t);
    free(t);

    return SUCCESS;
}




/* adds a new label to the task */
Exception addLabel(Task_t* t, Label_t* label){
    if(!t || !label || t->numb_labels >= LABELS_MAX || !t->available_colors[label->color]) 
        return INVALID_INPUT_EXCEPTION;

    t->available_colors[label->color] = False;
    t->labels[t->numb_labels++] = label;
}



/* removes label from the task */
Exception removeLabel(Task_t* t, LabelName label_name){
    for(int i = 0; i < t->numb_labels; i++)
    {
        if(!strcmp(t->labels[i]->name, label_name)) 
        {
            // deletes the label found
            deleteLabel(t->labels[i]);
            t->labels[i] = NULL;

            // re-orders the sequencial list
            for(int i = 0; i < LABELS_MAX - 1; i++)
                t->labels[i] = t->labels[i + 1];

            t->numb_labels--;

            return SUCCESS; 
        }
        
    }

    return VALUE_NOT_FOUND_EXCEPTION;

}



/* displays the task display component on the stdscr */
Exception show(Task_t* t, unsigned int y, unsigned x, boolean selected){
    if(!t) return INVALID_INPUT_EXCEPTION; 

    if(!t->win) t->win = newwin(TASK_DISPLAY_HEIGHT, TASK_DISPLAY_WIDTH, y, x);    

    refresh();

    box(t->win, 0, 0);

    int title_len = strlen(t->title);

    // move to the center up of the component
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
            LabelName label_name;
            Color label_color = t->labels[i]->color;

            strcpy(label_name, t->labels[i]->name);

            wmove(t->win, 1 + i, 1);

            // if the color pair has already beeing init and it is init again
            // it causes a segmentation fault (core dumped) error
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



/* Hide the display component of the task */
Exception hide(Task_t* t){
    if(!t || !isDisplayed(t)) return INVALID_INPUT_EXCEPTION; 


    // erase what's inside the window
    for(int i = 0; i < TASK_DISPLAY_HEIGHT; i ++)

        for( int j = 0; j < TASK_DISPLAY_WIDTH; j++)

            mvwprintw(t->win, i, j, " ");

    // Erase frame around the window
    wborder(t->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); 

    wrefresh(t->win); 
    delwin(t->win);
    t->win = NULL;
}



/* tells if the display component of the task is displayed */
boolean isDisplayed(Task_t* t){
    return t->win ? True : False;
}




Exception setDescription(Task_t* t, char* d){
    if(!t || strlen(d) >= DESCRIPTION_SIZE) return INVALID_INPUT_EXCEPTION;

    strcpy(t->description, d);

    return SUCCESS;
}




Exception setTitle(Task_t* t, char* title){
    if(!t || strlen(title) >= TASK_DISPLAY_WIDTH) return INVALID_INPUT_EXCEPTION;

    strcpy(t->title, title);

    return SUCCESS;
}




char* getDescription(Task_t* t){
    return !t ? (char*) INVALID_INPUT_EXCEPTION : t->description;
}




char* getTitle(Task_t* t){
    return !t ? (char* ) INVALID_INPUT_EXCEPTION : t->title;
}