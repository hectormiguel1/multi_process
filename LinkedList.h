//
// Created by hector on 11/12/19.
//

#ifndef MULTI_PROCESS_LINKEDLIST_H
#define MULTI_PROCESS_LINKEDLIST_H
#define SUCCESS 1
#define FAILURE 0
#define EMPTY 0
#include <stdlib.h>
#include <string.h>

typedef enum boolean {false, true} bool;

typedef struct Node
{
    char * data;
    struct Node * prev;
    struct Node * next;
}Node;

typedef struct LinkedList
{
    int size;
    Node * firstElement;
    Node * lastElement;

} LinkedList;


LinkedList * startEmptyList();
LinkedList * startList( char * data);
int insertFirst( LinkedList *, char *);
int insertLast( LinkedList *, char *);
int insertAt( LinkedList *, int index, char *);
int getSize( LinkedList *);
void destroyList( LinkedList *);
int  getElement( LinkedList *, Node *, int);
int contains( LinkedList *, char *);
int removeElement(LinkedList *, char*);
int removeLast(LinkedList *);
int removeFirst(LinkedList *);


#endif //MULTI_PROCESS_LINKEDLIST_H
