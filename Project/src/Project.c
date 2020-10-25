#include <stdio.h>
#include <stdlib.h>
#include "Project.h"

Project createProject(Title title, Description description)
{
    if (strlen(title) >= TITLE_SIZE || strlen(description) >= DESCRIPTION_SIZE)
        return (Project)INVALID_INPUT_EXCEPTION;
    Project project = (Project)malloc(sizeof(Project_Element_t));
    if (!project)
        return (Project)MEMORY_ALOCATION_EXCEPTION;
    project->title = title;
    project->description = description;
    CollaboratorsListElement collaboratorsListElement = (CollaboratorsListElement)malloc(sizeof(Collaborators_List_Element_t));
    if (!collaboratorsListElement)
        return (Project)MEMORY_ALOCATION_EXCEPTION;
    collaboratorsListElement->id = 0;
    collaboratorsListElement->collaborator = NULL;
    collaboratorsListElement->prev_collaboratorsListElement = NULL;
    collaboratorsListElement->next_collaboratorsListElement = NULL;
    project->collaboratorsListElement = collaboratorsListElement;
    return project;
}

Exception showProjects()
{
    ProjectListElement actual = firstProject;
    if (!actual)
        return NULL_POINTER_EXCEPTION;
    printf("\n");
    while (actual)
    {
        printf("\n%d | Projeto %s", actual->id, actual->project->title);
        actual = actual->next_project;
    }
    printf("\n");
    return SUCCESS;
}

Exception showProjectDetails(Project project)
{
    if (!project)
        return NULL_POINTER_EXCEPTION;
    CollaboratorsListElement actual = project->collaboratorsListElement;
    printf("\n\n%d | Projeto %s\nDescricao: %s\nColaboradores:", project->id, project->title, project->description);
    if (actual->collaborator == NULL)
        printf("Sem colaboradores.");
    while (actual)
    {
        printf("%s\n", actual->collaborator->name);
        actual = actual->next_collaboratorsListElement;
    }
    return SUCCESS
}

Exception showProjectCollaboratorsList(Project project)
{
    if (!project)
        return NULL_POINTER_EXCEPTION;
    CollaboratorsListElement actual = project->collaboratorsListElement;
    printf("\n\nColaboradores:");
    if (actual->collaborator == NULL)
        printf("Sem colaboradores.");
    while (actual)
    {
        printf("%sn", actual->collaborator->name);
        actual = actual->next_collaboratorsListElement;
    }
    return SUCCESS;
}

Exception showCollaboratorProfile(Project project, Name name)
{
    if (!project)
        return NULL_POINTER_EXCEPTION;
    CollaboratorsListElement actual = project->collaboratorsListElement;
    if (strlen(name) >= NAME_SIZE)
        return INVALID_INPUT_EXCEPTION;
    while (actual)
    {
        if (!strcmp(name, actual->collaborator->name))
        {
            printf("\nNome: %s\nEmail: %s\nDescricao: %s\n", actual->collaborator->name, actual->collaborator->email, actual->collaborator->description);
            return SUCCESS;
        }
        else
        {
            actual = actual->next_collaboratorsListElement;
        }
    }
    return NOT_FOUND_EXCEPTION;
}

Collaborator createCollaboratorProfile(Name name, Email email, Description description)
{
    if (strlen(name) >= NAME_SIZE || strlen(email) >= EMAIL_SIZE || strlen(description) >= DESCRIPTION_SIZE)
        return (Collaborator)INVALID_INPUT_EXCEPTION;
    Collaborator collaborator = (Collaborator)malloc(sizeof(Collaborator_Element_t));
    if (!collaborator)
        return (Collaborator)MEMORY_ALOCATION_EXCEPTION;
    collaborator->name = name;
    collaborator->email = email;
    collaborator->description = description;
    return collaborator;
}

Exception editCollaboratorProfile(Project project, Name name)
{
    if (!project)
        return NULL_POINTER_EXCEPTION;
    if (strlen(name) >= NAME_SIZE)
        return INVALID_INPUT_EXCEPTION;
    CollaboratorsListElement actual = project->collaboratorsListElement;
    while (actual)
    {
        if (!strcmp(name, actual->collaborator->name))
        {
            printf("Nome: ");
            scanf(" %s", actual->collaborator->name);
            if (strlen(actual->collaborator->name) >= NAME_SIZE)
                return INVALID_INPUT_EXCEPTION;
            printf("Email: ");
            scanf(" %s", actual->collaborator->email);
            if (strlen(actual->collaborator->email) >= EMAIL_SIZE)
                return INVALID_INPUT_EXCEPTION;
            printf("Descricao: ");
            scanf(" %s", actual->collaborator->description);
            if (strlen(actual->collaborator->description) >= DESCRIPTION_SIZE)
                return INVALID_INPUT_EXCEPTION;
            return SUCCESS;
        }
        else
        {
            actual = actual->next_collaboratorsListElement;
        }
    }
    return NOT_FOUND_EXCEPTION;
}

Exception pushProject(Project project)
{
    if (!project)
        return NULL_POINTER_EXCEPTION;
    ProjectListElement actual = firstProject;
    if (firstProject)
    {
        while (actual)
        {
            if (actual->next_project == NULL)
            {
                actual->next_project->id = actual->id + 1;
                actual->next_project->project = project;
                actual->next_project->next_project = NULL;
                return SUCCESS;
            }
            actual = actual->next_project;
        }
    }
    else
    {
        firstProject->id = 1;
        firstProject->next_project = NULL;
        firstProject->project = project;
    }
}

Exception deleteProject(Project project)
{
    ProjectListElement actual = firstProject, aux;
    if (!firstProject || !project)
        return NULL_POINTER_EXCEPTION;
    while (actual)
    {
        if (actual->next_project->project == project)
        {
            aux = actual->next_project;
            actual->next_project = aux->next_project;
            free(aux);
            return SUCCESS;
        }
        else
            actual = actual->next_project;
    }
    return NOT_FOUND_EXCEPTION;
}

Exception pushCollaborator(Project project, Collaborator collaborator)
{
    if (!project || !collaborator)
        return NULL_POINTER_EXCEPTION;
    CollaboratorsListElement actual = (CollaboratorsListElement)malloc(sizeof(Collaborators_List_Element_t));
    if (!actual)
        return MEMORY_ALOCATION_EXCEPTION;
    CollaboratorsListElement aux;
    actual = project->collaboratorsListElement;
    if (actual->collaborator == NULL)
    {
        actual->id = 1;
        actual->collaborator = collaborator;
        actual->prev_collaboratorsListElement = NULL;
        actual->next_collaboratorsListElement = NULL;
        return SUCCESS;
    }
    else
    {
        while (actual)
        {
            if (actual->next_collaboratorsListElement == NULL)
            {
                aux = actual->next_collaboratorsListElement;
                aux->id = actual->id + 1;
                aux->collaborator = collaborator;
                aux->prev_collaboratorsListElement = actual;
                aux->next_collaboratorsListElement = NULL;
                return SUCCESS;
            }
            actual = actual->next_collaboratorsListElement;
        }
    }
}

Exception deleteCollaborator(Project project, Collaborator collaborator)
{
    CollaboratorsListElement actual = project->collaboratorsListElement, aux, firstElement;
    firstElement = actual;
    if (!project || !collaborator || firstElement->id == 0)
        return NULL_POINTER_EXCEPTION;
    while (actual)
    {
        if (actual->next_collaboratorsListElement->collaborator == collaborator)
        {
            aux = actual->next_collaboratorsListElement;
            actual->next_collaboratorsListElement = aux->next_collaboratorsListElement;
            if (aux->next_collaboratorsListElement != NULL)
            {
                aux->next_collaboratorsListElement->prev_collaboratorsListElement = actual;
            }
            free(aux);
            return SUCCESS;
        }
        actual = actual->next_collaboratorsListElement;
    }
    return NOT_FOUND_EXCEPTION;
}

Collaborator searchCollaboratorByName(Project project, Name name)
{
    if (!project)
        return (Collaborator)NULL_POINTER_EXCEPTION;
    CollaboratorsListElement actual = (CollaboratorsListElement)malloc(sizeof(Collaborators_List_Element_t));
    if (!actual)
        return (Collaborator)MEMORY_ALOCATION_EXCEPTION;
    if (strlen(name) >= NAME_SIZE)
        return (Collaborator)INVALID_INPUT_EXCEPTION;
    actual = project->collaboratorsListElement;
    while (actual)
    {
        if (!strcmp(name, actual->collaborator->name))
        {
            return actual->collaborator;
        }
        else
        {
            actual = actual->next_collaboratorsListElement;
        }
    }
    return (Collaborator)NOT_FOUND_EXCEPTION;
}

Exception showProjectTasklist(Project project);