#ifndef __LABEL_H__
#define __LABEL_H__ 

#include "projectOrganizer.h"

#define LABEL_NAME_SIZE 20
#define NUMB_COLORS 8

typedef char LabelName[LABEL_NAME_SIZE];

typedef unsigned int Color;

int AVAILABLE_COLORS[NUMB_COLORS];


typedef struct Label{ 
    LabelName name;
    Color color;

} Label_t;


/* inicializa o que é necessário para a 
utilização de labels no projeto */
Exception initLabels();

Label_t* createLabel(Color color, LabelName name);

Exception deleteLabel(Label_t* l);

Exception setColor(Label_t* l, Color c);

Exception setLabelName(Label_t* l, LabelName name);

Color getColor(Label_t* l);

char* getLabelName(Label_t* l);

#endif