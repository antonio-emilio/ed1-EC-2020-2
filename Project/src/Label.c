#include "Label.h"



int initLabels(){
    for(int i = 0; i < NUMB_COLORS; i++)
        INIT_PAIRS[i] = False;
    
    return OK;
}


Label_t* createLabel(Color color, LabelName name){

    if(color >= NUMB_COLORS || strlen(name) > LABEL_NAME_SIZE)
        return NULL; 


    Label_t* new_label = (Label_t*) malloc(sizeof(Label_t));

    if(!new_label) return NULL;


    setColor(new_label, color);
    setLabelName(new_label, name);


    return new_label;
}




int deleteLabel(Label_t* l){
    if(!l) return ERROR;

    free(l);
    return OK;
}





// _______setters__________


int setColor(Label_t* l, Color c){
    if(c >= NUMB_COLORS) return ERROR;

        l->color = c;
        return OK;
}




int setLabelName(Label_t* l, LabelName name){
    if(strlen(name) > LABEL_NAME_SIZE) return ERROR;

        strcpy(l->name, name);
        return OK;
}




// _______gettters________

Color getColor(Label_t* l){
    return l ? l->color : (Color) ERROR;
}




char* getLabelName(Label_t* l){

    return l ? l->name :  (char*) ERROR;

}

