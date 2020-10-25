#ifndef __PROJECT_H__
#define __PROJECT_H__

#include "projectOrganizer.h"

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
    struct CollaboratorsListElement collaboratorsListElement; // Ponteiro para o primeiro elemento da lista de colaboradores
} Project_Element_t;

typedef Project_Element_t *Project;

// Collaborator List struct
typedef struct Collaborators_List_Element
{
    int id;
    struct Collaborator collaborator;  // Perfil do colaborador
    struct Collaborators_List_Element *prev_collaboratorsListElement;
    struct Collaborators_List_Element *next_collaboratorsListElement;   // Ponteiro para a próxima struct da lista de colaborador com o ponteiro do próximo colaborador da lista
} Collaborators_List_Element_t;

typedef Collaborators_List_Element_t *CollaboratorsListElement;

// Collaborator struct
typedef struct Collaborator_Element
{
    Name name;
    Email email;
    Description description;
} Collaborator_Element_t;

typedef Collaborator_Element_t *Collaborator;

// Functions

Project createProject(Title title, Description description);

Exception showProjects();

Exception showProjectDetails(Project project);

Exception showProjectCollaboratorsList(Project project);

Exception showCollaboratorProfile(Project project, Name name);

Collaborator createCollaboratorProfile(Name name, Email email, Description description);

Exception editCollaboratorProfile(Project project, Name name);

Exception pushProject(Project project);

Exception deleteProject(Project project);

Exception pushCollaborator(Project protect, Collaborator collaborator);

Exception deleteCollaborator(Project protect, Collaborator collaborator);

Collaborator searchCollaboratorByName(Project project, Name name);

Exception showProjectTasklist(Project project);

#endif