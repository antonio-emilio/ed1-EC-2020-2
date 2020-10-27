#ifndef __PROJECTORG_H__
#define __PROJECTORG_H__

/* Global definitions, functions and var */
#include <ncurses.h>

#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Display.h"


#define True 1
#define False 0 

#define ERROR -1
#define OK 0

#define DESCRIPTION_SIZE 1000
#define NAME_SIZE 1
#define EMAIL_SIZE 1
#define BIO_SIZE 1


typedef char Description[DESCRIPTION_SIZE];
typedef char Name[NAME_SIZE]; 
typedef char Email[EMAIL_SIZE]; 
typedef char Bio[BIO_SIZE]; 


#endif 