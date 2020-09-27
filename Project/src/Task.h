#ifndef __TASK_H__
#define __TASK_H__

#define INVALID_DESCRIPTION -1
#define INVALID_TITLE -2

#define SUCESS 1

typedef int STATUS;



#define TITLE_MAX_SIZE 256
#define DESCRIPTION_MAX_SIZE 500

typedef char Description[DESCRIPTION_MAX_SIZE];
typedef char Title[TITLE_MAX_SIZE]; 



typedef struct Task{
    int id;

    Title t;
    Description d;

} Task_t;








#endif