#ifndef __LABEL_H__
#define __LABEL_H__ 


#define LABEL_NAME_SIZE

typedef char Name;
typedef int Color;

typedef struct Label{ 
    Color color;
    Name name;

} Label_t;

#endif