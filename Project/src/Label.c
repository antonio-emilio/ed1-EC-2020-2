#include "Label.h"




Label_t* createLabel(Color color, LabelName name){

    if(color >= NUMB_COLORS || strlen(name) > LABEL_NAME_SIZE)
        return (Label_t*) INVALID_INPUT_EXCEPTION; 


    Label_t* new_label = (Label_t*) malloc(sizeof(Label_t));
    if(!new_label) return (Label_t*) MEMORY_ALOCATION_EXCEPTION;

    new_label->color = color;
    strcpy(new_label->name, name);


    return new_label;
}


Exception deleteLabel(Label_t* l){
    free(l);
}


Exception setColor(Label_t* l, Color c){
    if(c >= NUMB_COLORS)
        return INVALID_INPUT_EXCEPTION;


        l->color = c;
}


Exception setLabelName(Label_t* l, LabelName name){
    if(strlen(name) > LABEL_NAME_SIZE)
        return INVALID_INPUT_EXCEPTION;


        strcpy(l->name, name);
}

Color getColor(Label_t* l){
    return l ? l->color : INVALID_INPUT_EXCEPTION;
}

char* getLabelName(Label_t* l){

    return l ? l->name :  INVALID_INPUT_EXCEPTION;

}

