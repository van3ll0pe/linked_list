#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Linked_list {
    int i;
    struct Linked_list *next;
}Linked_list;

void addElement_end(Linked_list **linked_list, int value);
void removeElement_end(Linked_list **linked_list);
int nbrElement(Linked_list **linked_list);
void removeElement_top(Linked_list **linked_list);
void addElement_top(Linked_list **linked_list, int value);
void printElement(Linked_list **linked_list, int nPosition);
void addElement_nPosition(Linked_list **linked_list, int value, int nPosition);
void removeElement_nPosition(Linked_list **linked_list, int nPosition);



void addElement_top(Linked_list **linked_list, int value) { //add a new element of the 
    
    Linked_list *new_element = malloc(sizeof(Linked_list) * 1);
    new_element->i = value;

    new_element->next = (*linked_list);
    (*linked_list) = new_element;
}

void removeElement_top(Linked_list **linked_list) { //remove the first element of the linked list
    if ((*linked_list) != NULL) {
        Linked_list *tmp = (*linked_list);

        (*linked_list) = (*linked_list)->next;
        free(tmp);
    }
}

int nbrElement(Linked_list **linked_list) { //function to give the number of element of the linked list
    int nbr = 0;

    if ((*linked_list) != NULL) {
        Linked_list *element = (*linked_list);

        while (element->next != NULL) {
            nbr++;
            element = element->next;
        }
        nbr++;
    }
    return nbr;
}

void removeElement_end(Linked_list **linked_list) {//function to remove the last element of the linked last
        if (*linked_list != NULL) {
            Linked_list *element = (*linked_list);
            Linked_list *tmp = (*linked_list);
            while (element->next != NULL) {
                element = element->next;
            }

            while (tmp->next != element) {
                tmp = tmp->next;
            }

            tmp->next = element->next;
            free(element);
        }
}

void addElement_end(Linked_list **linked_list, int value) { //function to add new element at the end of the linked list
    Linked_list *element = malloc(sizeof(Linked_list) * 1);
    element->i = value;

    if (*linked_list == NULL) {
        element->next = (*linked_list);
        (*linked_list) = element;
    } else {
        
        Linked_list *tmp = (*linked_list);

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        element->next = tmp->next;
        tmp->next = element;
    }
}

void printElement(Linked_list **linked_list, int nPosition) {
    if (nPosition < 0 || nPosition >= nbrElement(linked_list)) {
        printf("No element\n");
    } else {
        Linked_list *element = (*linked_list);

        for (int i = 0; i < nPosition; i++) {
            element = element->next;
        }

        printf("%d\n", element->i);
    }
}

void addElement_nPosition(Linked_list **linked_list, int value, int nPosition) {
    if (nPosition < 0 || nPosition >= nbrElement(linked_list)) {
        printf("no position valid\n");
    } else {
        Linked_list *element = malloc(sizeof(Linked_list) * 1);
        element->i = value;

        if (*linked_list == NULL || nPosition == 0)
        {
            element->next = (*linked_list)->next;
            (*linked_list) = element;

        }
        else {
            Linked_list *tmp = (*linked_list);
            for (int i = 1; i < nPosition; i++) {
                tmp = tmp->next;
            }

            element->next = tmp->next;
            tmp->next = element;
        } 
    }
}

void removeElement_nPosition(Linked_list **linked_list, int nPosition) {
    if (nPosition < 0 || nPosition >= nbrElement(linked_list)) {
        printf("no position valid\n");
    } else {
        if (nPosition != 0 && (*linked_list) != NULL) {
            Linked_list *tmp = (*linked_list);
            Linked_list *tmp_before = tmp;
            for (int i = 1; i < nPosition; i++) {
                tmp_before = tmp;
                tmp = tmp->next;
            }
            tmp_before->next = tmp->next;
            free(tmp);
        }
        else if (nPosition == 0 && (*linked_list) != NULL){
            Linked_list *tmp = (*linked_list);
            (*linked_list) = (*linked_list)->next;
            free(tmp);
        }
        else {
            return ;
        }
    }
}