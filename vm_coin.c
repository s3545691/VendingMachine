/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_coin.h"
    Node * currentNode;
    Stock * stock;
    void menuLoad();
Price convertToPrice (char * str)
{
 char * tok;
  Price tempPrice;
  tempPrice.cents = 0;
  tempPrice.dollars = 0;
  
  
  
  tok = strtok(str, ".");
  if (tok != NULL)
  {
  tempPrice.dollars = atoi(tok);
  }

  tok = strtok(NULL, ".");
  if (tok != NULL)
  {
  tempPrice.cents = atoi(tok);
  }
  
   
      

  return (tempPrice);
  
  
}
Boolean payForItem(VmSystem * system, Stock * item)
{
    int change = 0;
    int refundValue = 0;
    int refundDollars;
    int refundCents;
    int dollars;
    int cents;
    int start;
    int owing;
    char  minusAmount[80 + EXTRA_SPACES];
    int minusAmountInt;
    start = item->price.dollars * 100 + item->price.cents;
    owing = start;
    
    while(owing > 0)
  {
    printf("You still need to give us $%0.02f:", owing / 100.0);
    fgets(minusAmount, 80 + EXTRA_SPACES, stdin);
    
    
    minusAmountInt= atoi(minusAmount);
  /*  printf("%i", minusAmountInt); */
    owing -=minusAmountInt;

    if(minusAmount[strlen(minusAmount) -1] != '\n')
    {
      readRestOfLine();
      printf("Please enter a valid input\n");
    }
    if (strlen(minusAmount) <2)
    {    
        refundValue= ((item->price.dollars * 100 + item->price.cents)-owing);
        refundDollars = refundValue / 100;
        refundCents = refundValue%100;
        printf("Refunding:$%i.%i\n", refundDollars, refundCents);
        
        menuLoad();
        break;
    }
    
 /*   currentNode = system->itemList->head;
    stock = currentNode->data;
     printf(stock->price.dollars);
  * */
    
    
    
}
    
    if (owing <= 0)
    {
        int tempOnHand;
        change = owing-owing-owing;
        dollars = change / 100;
        cents = change%100;
        printf("Thank you. Here is your %s, and your change of $%i.%i\n", item->name, dollars, cents);
        printf("Please come back soon.\n");
        tempOnHand=item->onHand;
        tempOnHand--;
        item->onHand=tempOnHand;
        menuLoad();
    }
    
    
    return(TRUE);
    menuLoad();
}

 
/**
 * Implement functions here for managing coins and the
 * "cash register" contained in the VmSystem struct.
 **/

/**
 * Some example functions:
 * init coins array, insert coin, change coin count for Denomination,
 * convert Denomination to coin value, deducting coins from register, etc...
 */
