/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_stock.h"
/*Boolean nodeFree(List * myList, Node * myNode); */
Boolean listCreate(VmSystem * system)

{
  system->itemList = (List *)malloc(sizeof(List));

  if(system->itemList == NULL)
  return FALSE;
  
  else{
  system->itemList->head = NULL;
  system->itemList->size = 0;
  } 
  
  return TRUE;
}

void listFree(VmSystem * system)
{
    Node * currentNode;
    Node * nextNode;
    if(system==NULL)
    {
        return;
    }
    currentNode = system->itemList->head;
    
  while((currentNode != NULL) || (system->itemList->size > 0))
  {
      nextNode = currentNode->next;
      stockFree(currentNode->data);
      nodeFree(currentNode);
      
      system->itemList->size--;
      currentNode = nextNode;
      
      if (system->itemList->size == 0)
      {
              break;
      }
  }
  free(system->itemList);

}

Node * createNode(Stock * myStock)
{
    Node * new = (Node *)malloc(sizeof(Node));
  new->data = myStock;
  new->next=NULL;
  return new;
}


void stockFree(Stock * myStock)
{
    free(myStock);
}


void nodeFree(Node * myNode)
{
    free(myNode);
    
    /*
    if (myNode == NULL)
    {
        return TRUE;
    }
    adjust the list to no longer include this node 
    myList->size--;
    if(myList->head == myNode)
    {
        myList->head = myNode->next; 
    }
    free(myNode);
    return TRUE;
    */
}

void insertNode(List * list, Node * newNode)
{
   /* Node * currentNode;
    Node * previousNode;
*/    
  
    
    /*simple insert at head, ran out of time to implement the commented text below*/
    newNode->next = list->head;
  list->head = newNode;
  list->size++;
   
  
    



/*an attempt at sorting but ran out of time*/
    
  /*  
    printf("New node is: %s\n", newNode->data->name);
    printf("size: %d\n", list->size);
      
      Is this the first Node in the list ?
    if(list->size == 0)
    {
        printf("First node: %s\n", newNode->data->name);
        newNode->next = list->head;
         list->head = newNode;
         printf(list->head->data->name);
         printf(newNode->data->name);
         list->size++;
    }
     Not the first Node, do we insert at the Head ? 
    else if((strcmp(newNode->data->name,list->head->data->name)) <= 0)
    {
        printf("node inserted at head: %s\n", newNode->data->name);
      //  inserted at head
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
     Otherwise run down the list and insert in the List 
    else 
    {
        previousNode = list->head;
        currentNode = list->head->next;
                
        while (currentNode->next != NULL)
        {
            printf("Current Node %s. Node to be inserted %s\n", currentNode->data->name, newNode->data->name);
            if (strcmp(currentNode->data->name, newNode->data->name)<= 0)
            {
                break;
            }
             Advance along the list 
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
         Insert here 
        newNode->next = currentNode;
        previousNode->next = newNode;
        list->size++;
    }
    
 
  
  printf("Size: %d\n",list->size); 
} */
}


Stock * stockTok(char * stock)
{
    char * price;
    Stock * newStock = (Stock *)malloc(sizeof(Stock));
    char * myId;
    char * myName;
    char * myDesc;

    /*id*/
    myId = strtok(stock, STOCK_DELIM);
    if (myId == NULL)
    {
        printf("ERROR: id not found \n");
        return NULL;
    }
    (void)strcpy(newStock->id,myId);
    /*name*/
    myName = strtok(NULL, STOCK_DELIM);
    if (myName == NULL)
    {
        printf("ERROR name not found\n");
        return NULL;
    }
    (void)strcpy(newStock->name,myName); 
    /*description*/
    myDesc=strtok(NULL, STOCK_DELIM);
    if (myDesc == NULL)
    {
        printf("ERROR desc not found\n");
        return NULL;
    }
    (void)strcpy(newStock->desc,myDesc);
    /*price??*/
    price = strtok(NULL, STOCK_DELIM);
    if (price == NULL)
    {
        printf("ERROR price not found\n");
        return NULL;
    }
  
 
  newStock->onHand = atoi(strtok(NULL, STOCK_DELIM));
  newStock->price = convertToPrice(price);
  return newStock;
}

Stock * searchStock(List * listToBeSearched, char * idToBeFound)
{
    Node * curr;
    
    curr = listToBeSearched-> head;
while(curr != NULL)
  {
    if(strcmp(curr->data->id, idToBeFound) == 0)
      return curr->data;
    curr = curr->next;
  }

  return NULL;
}


void removeStock(List * list, Stock * stock)
{

  Node * prev;
  Node * curr;
  Node * next;

  curr = list->head;
  next = curr->next;

  if(stock->id == curr->data->id)
  {
    list->head = next;
    nodeFree(curr);
  }
  else
  {
    while(curr->data->id != stock->id)
    {
      prev = curr;
      curr = next;
      next = curr->next;
    }

    prev->next = next;
    nodeFree(curr);
  }
}

void defaultStock(List * myList)
{
    Node * currentNode;
    currentNode = myList->head;
    while(currentNode)
    {
        currentNode->data->onHand = DEFAULT_STOCK_LEVEL;
        currentNode = currentNode->next;
    }
}











/**
 * vm_stock.c this is the file where you will implement the
 * interface functions for managing the stock list.
 **/

/**
 * Some example functions:
 * create list, free list, create node, free node, insert node, etc...
 */
