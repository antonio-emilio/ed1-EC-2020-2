#ifndef __LABEL_H__
#define __LABEL_H__ 

#include <ncurses.h>
#include <stdlib.h>


#define LABEL_NAME_SIZE 20

typedef char LabelName[LABEL_NAME_SIZE];

typedef int Color;

typedef struct Label{ 
    LabelName name;
    Color color;

} Label_t;

Label_t* createLabel(Color color, LabelName name);

void deleteLabel(Label_t* l);

void setColor(Label_t* l, Color c);

void setLabelName(Label_t* l, LabelName name);

Color getColor(Label_t* l);

char* getLabelName(Label_t* l);

#endif