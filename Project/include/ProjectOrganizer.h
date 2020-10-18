#ifndef __PROJECTORG_H__
#define __PROJECTORG_H__



#include <ncurses.h>

#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Exceptions.h"

#define True 1
#define False 0 

#define TITLE_SIZE 20
#define DESCRIPTION_SIZE 1000

typedef int boolean;

typedef char Description[DESCRIPTION_SIZE];
typedef char Title[TITLE_SIZE]; 
typedef char Name[NAME_SIZE]; 
typedef char Email[EMAIL_SIZE]; 
typedef char Bio[BIO_SIZE]; 


Exception initProjectOrganizer();

#endif 