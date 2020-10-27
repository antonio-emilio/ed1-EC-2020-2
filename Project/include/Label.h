#ifndef __LABEL_H__
#define __LABEL_H__ 

#include "ProjectOrganizer.h"

#define LABEL_NAME_SIZE 20
#define NUMB_COLORS 8

typedef char LabelName[LABEL_NAME_SIZE];

typedef unsigned int Color;

int INIT_PAIRS[NUMB_COLORS];


typedef struct Label{ 
    LabelName name;
    Color color;

} Label_t;


/* inicializa o que é necessário para a 
utilização de labels no projeto */
int initLabels();

Label_t* createLabel(Color color, LabelName name);

int deleteLabel(Label_t* l);

int setColor(Label_t* l, Color c);

int setLabelName(Label_t* l, LabelName name);

Color getColor(Label_t* l);

char* getLabelName(Label_t* l);

#endif