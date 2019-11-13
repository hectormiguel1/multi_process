#include "LinkedList.h"

Node * new_Node(char *);

Node * new_Node(char * data)
{
    Node tmpNode;
    tmpNode.next = NULL;
    tmpNode.prev = NULL;
    tmpNode.data = data;

    Node * pointerToTmpNode = (Node * ) malloc (sizeof(tmpNode));
    if(pointerToTmpNode != NULL)
    {
        strcpy ( pointerToTmpNode->data, data );
        pointerToTmpNode->prev = NULL;
        pointerToTmpNode->prev = NULL;

        return pointerToTmpNode;
    }
    else
    {
        return NULL;
    }
}
/**
 * Creates a new empty list allocates it into the heap and returns pointer.
 * @return: pointer to new LinkedList.
 */
LinkedList * startEmptyList()
{
    LinkedList tmp;
    tmp.firstElement = NULL;
    tmp.size = EMPTY;

    LinkedList *tmpPointer = (LinkedList *) malloc ( sizeof(tmp));

    if(tmpPointer != NULL)
    {
        return tmpPointer;
    }
    else
    {
        return NULL;
    }
}

/**
 * Starts a list with an initial value, return pointer to the new list.
 * @param data : initial information to store in first node of linked list.
 * @return pointer to new linked list
 */
LinkedList * startList( char * data)
{
    Node *startNodePointer = new_Node (data);

    LinkedList * tmpPointer = startEmptyList ();
    if(startNodePointer != NULL && tmpPointer != NULL)
    {
        tmpPointer->firstElement = startNodePointer;
        tmpPointer->lastElement = startNodePointer;
        tmpPointer->size++;

        return tmpPointer;
    }
    else
    {
        if(startNodePointer != NULL)
        {
            free(startNodePointer);
        }
        if(tmpPointer != NULL)
        {
            free(tmpPointer);
        }
        return NULL;
    }
}
/**
 * function adds data at the begining of the list.
 * @param list : list to add element to
 * @param data : data to be added to the list
 * @return : 1 on SUCCESS, 0 On failure.
 */
int insertFirst(LinkedList * list, char * data)
{
    Node * newNode = new_Node (data);

    if(newNode != NULL)
    {
        newNode->next = list->firstElement;
        newNode->prev = list->lastElement;
        list->firstElement->prev = newNode;
        list->size++;
        list->firstElement = newNode;
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }

}

/**
 * Adds an element at the end of the list
 * @param list : list to add element to
 * @param data : data to be added
 * @return : 1 on success, 0 on failure.
 */
int insertLast(LinkedList * list, char * data)
{
    Node * newNode = new_Node (data);

    if(newNode != NULL)
    {
        newNode->prev = list->lastElement;
        list->lastElement->next = newNode;
        list->lastElement = newNode;
        list->size++;
        return SUCCESS;

    }
    else
    {
        return FAILURE;
    }

}

/**
 * Adds node with data to the desired location
 * @param list : list to add data to.
 * @param index : location where to insert data
 * @param data : data to be inserted.
 * @return: 1 on success, false otherwise.
 */
int insertAt(LinkedList * list, int index, char * data)
{
    Node *tmpNode = new_Node ( data );
    if ( tmpNode == NULL)
    {
        return FAILURE;
    } else
    {
        Node *nextNode = NULL;
        getElement ( list, nextNode, index );
        if ( nextNode != NULL)
        {
            list->size++;
            tmpNode->next = nextNode;
            tmpNode->prev = nextNode->prev;
            nextNode->prev = tmpNode;
            return true;
        } else
            return false;
    }

}

/**
 * Returns the current size of the list
 * @param list : list to get size from
 * @return : size of list.
 */
int getSize(LinkedList * list)
{
    return list->size;
}

/**
 * Frees the memory taken up by all nodes and the LinkedList
 * @param list : list to be freed
 */
void destroyList(LinkedList * list)
{
    Node * currentNode = list->lastElement;

    while(list->size != EMPTY)
    {
        currentNode = currentNode->prev;
        free(currentNode->next);
        list->size--;
    }

    free(list);
}

/**
 * Finds the nth element in the list,
 * @param fromList : List to search item
 * @param destNode : Node where the item will be stored if found
 * @param atLocation : location to get.
 * @return SUCCESS if nth element was found, FAILURE otherwise.
 */
int getElement(LinkedList * fromList, Node * destNode, int atLocation)
{
    if(fromList->size > EMPTY && atLocation >= EMPTY)
    {
        Node *currentNode = fromList->firstElement;
        bool found = false;
        int currentLocation = EMPTY;
        while(currentNode != fromList->lastElement && !found)
        {
            if(currentLocation == atLocation)
            {
                destNode = currentNode;
                found = true;
            }
            else
            {
                currentLocation++;
                currentNode = currentNode->next;
            }
        }
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}