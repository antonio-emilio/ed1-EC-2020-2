#ifndef __PROJECTORG_H__
#define __PROJECTORG_H__



#include <ncurses.h>

#include <stdlib.h>
#include <string.h>


#include "Exceptions.h"
#include "Label.h"

#define True 1
#define False 0 

#define DESCRIPTION_SIZE 1000
#define NAME_SIZE 1
#define EMAIL_SIZE 1
#define BIO_SIZE 1

typedef int boolean;

typedef char Description[DESCRIPTION_SIZE];
typedef char Name[NAME_SIZE]; 
typedef char Email[EMAIL_SIZE]; 
typedef char Bio[BIO_SIZE]; 

// default ncurses configurations are defined here
void init_project_organizer();

#endif 