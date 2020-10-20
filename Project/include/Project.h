#ifndef __PROJECT_H__
#define __PROJECT_H__

#include "ProjectOrganizer.h"

// Project List struct
typedef struct Project_List_Element
{
    int id;
    struct Project project;
    struct Project_List_Element *next_project;
} Project_List_Element_t;

typedef Project_List_Element_t *ProjectListElement;

ProjectListElement firstProject = NULL;

// Project struct
typedef struct Project_Element
{
    Title title;
    Description description;
    struct CollaboratorsList collaboratorListElement; // Ponteiro para o primeiro elemento da lista de colaboradores
} Project_Element_t;

typedef Project_Element_t *Project;


// Collaborator List struct
typedef struct Collaborators_List
{
    int id;
    struct Collaborator collaborator;  // Perfil do colaborador
    struct Collaborators_List *next_collaborator;   // Ponteiro para a próxima struct da lista de colaborador com o ponteiro do próximo colaborador da lista
} Collaborators_List_t;

typedef Collaborators_List_t *CollaboratorsList;

// Collaborator struct
typedef struct Collaborator_Element
{
    Name name;
    Email email;
    Bio bio;
} Collaborator_Element_t;

typedef Collaborator_Element_t *Collaborator;


// Functions

Project createProject(Title title, Description description, CollaboratorsList collaboratorsList);

void showProjects();

void showProjectDetails(Project project);

void showProjectCollaboratorsList(Project project);

void showCollaboratorProfile(Project project, Name name);

Collaborator createCollaborator(Name name, Email email, Bio bio);

void pushProject(Project project);

void deleteProject(Project project);

void pushCollaborator(Project protect, Collaborator collaborator);

void deleteCollaborator(Project protect, Collaborator collaborator);

Collaborator searchCollboratorByName(Name name);



#endif