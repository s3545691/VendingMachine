/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#ifndef VM_STOCK_H
#define VM_STOCK_H

#include "vm_coin.h"

/**
 * The default stock level that all new stock should start with and the value
 * to use when restting stock.

 **/
#define DEFAULT_STOCK_LEVEL 20

#define STOCK_DELIM "|"

/*forward declaring functions */
void listFree(VmSystem * system);
Stock * searchStock(List * listToBeSearched, char * idToBeFound);
void defaultStock(List * myList);
void removeStock(List * list, Stock * stock);
void nodeFree(Node * myNode);
void stockFree(Stock * myStock);
Boolean listCreate(VmSystem * system);
Stock * stockTok(char * stock);
void insertNode(List * list, Node * new);
Node * createNode(Stock * myStock);
void resetStock(VmSystem * system);

#endif
