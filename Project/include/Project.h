#ifndef __PROJECT_H__
#define __PROJECT_H__

#include "projectOrganizer.h"

// Project List struct
typedef struct Project_List
{
    int id;
    struct Project project;
    struct Project next_project;
} Project_List_t;

typedef Project_List_t *ProjectList;

// Project struct
typedef struct Element
{
    Title title;
    Description description;
    struct Collaborator collaborator;
} Element_t;

typedef Element_t *Project;

// Collaborator struct
typedef struct Collaborator_Profile
{
    Name name;
    Email email;
    Bio bio;
    struct Collaborator_Profile *next;
} Collaborators_Profile_t;

typedef Collaborators_t *Collaborator;

// Start a project

Project creteProject();




#endif