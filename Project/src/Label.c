#include "Label.h"



Exception initLabels(){
    for(int i = 0; i < NUMB_COLORS; i++)
        INIT_PAIRS[i] = 0;
}


Label_t* createLabel(Color color, LabelName name){

    if(color >= NUMB_COLORS || strlen(name) > LABEL_NAME_SIZE)
        return (Label_t*) INVALID_INPUT_EXCEPTION; 


    Label_t* new_label = (Label_t*) malloc(sizeof(Label_t));

    if(!new_label) return (Label_t*) MEMORY_ALOCATION_EXCEPTION;


    setColor(new_label, color);
    setLabelName(new_label, name);


    return new_label;
}




Exception deleteLabel(Label_t* l){
    if(!l) return INVALID_INPUT_EXCEPTION;

    free(l);
    return SUCCESS;
}





// _______setters__________


Exception setColor(Label_t* l, Color c){
    if(c >= NUMB_COLORS) return INVALID_INPUT_EXCEPTION;

        l->color = c;
        return SUCCESS;
}




Exception setLabelName(Label_t* l, LabelName name){
    if(strlen(name) > LABEL_NAME_SIZE) return INVALID_INPUT_EXCEPTION;

        strcpy(l->name, name);
        return SUCCESS;
}




// _______gettters________

Color getColor(Label_t* l){
    return l ? l->color : (Color) INVALID_INPUT_EXCEPTION;
}




char* getLabelName(Label_t* l){

    return l ? l->name :  (char*) INVALID_INPUT_EXCEPTION;

}

