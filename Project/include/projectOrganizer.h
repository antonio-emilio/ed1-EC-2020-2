#ifndef __PROJECTORG_H__
#define __PROJECTORG_H__

/*
    este arquivo contém as definições mais gerais usadas no projeto e os includes
    que serão compartilhados pela maioria dos arquivos.
*/


#include <ncurses.h>

#include <stdlib.h>
#include <string.h>

#include "Exceptions.h"

#define True 1
#define False 0 

// tamanhos máximos
#define TITLE_SIZE 256
#define DESCRIPTION_SIZE 1024

#define NAME_SIZE 64
#define EMAIL_SIZE 64
#define BIO_SIZE 512

typedef int boolean;

// char* com os tamanhos específicos de title e description
typedef char Description[DESCRIPTION_SIZE];
typedef char Title[TITLE_SIZE]; 
typedef char Name[NAME_SIZE]; 
typedef char Email[EMAIL_SIZE]; 





#endif 