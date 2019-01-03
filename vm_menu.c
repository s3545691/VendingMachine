/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_menu.h"

/**
 * vm_menu.c handles the initialisation and management of the menu array.
 **/

/**
 * In this function you need to initialise the array of menu items
 * according to the text to be displayed for the menu. This array is
 * an array of MenuItem with text and a pointer to the function
 * that will be called.
 **/
void initMenu(MenuItem * menu)
{
    int i=0;

  strcpy(menu[1].text, "Display Item");
        menu[1].function = displayItems;

  strcpy(menu[2].text, "Purchase Item");
         menu[2].function = &purchaseItem;

  strcpy(menu[3].text, "Save and Exit");
         menu[3].function = &saveAndExit;

  strcpy(menu[4].text, "Add Item");
         menu[4].function = &addItem;

  strcpy(menu[5].text, "Remove Item");
        menu[5].function = &removeItem;

  strcpy(menu[6].text, "Display Coins");
         menu[6].function = &displayCoins;
  
  strcpy(menu[7].text, "Reset Stock");
         menu[7].function = &resetStock;

  strcpy(menu[8].text, "Reset Coins");
         menu[8].function = &resetCoins;

  strcpy(menu[9].text, "Abort Program");
         menu[9].function = &abortProgram;
         
         
         
         printf("Main Menu:\n");
  for(i = 1; i < 4; i++)
    printf("%i. %s\n", i, menu[i].text);

  printf("Administrator-Only Menu:\n");
  for(i = 4; i < 10; i++)
    printf("%i. %s\n", i, menu[i].text);

  printf("Select your option (1-9): ");


}

/**
 * Gets input from the user and returns a pointer to the MenuFunction
 * that defines how to perform the user's selection. NULL is returned
 * if an invalid option is entered.
 **/
MenuFunction getMenuChoice(MenuItem * menu)
{
    /*
    int x;
    char userIn[80];
    x= atoi(fgets(userIn, 80, stdin));
        return x; */ 
    
  
    
    
    
    
    
    
    
    
    
    
    
    
    /*char userIn[80];
    int i;
    fgets(userIn, 80, stdin);
    i = strlen(userIn);
        if (userIn[ i ] == '\n')
            userIn[i] = '\0';

    if(isdigit(userIn[0]))
    {
      i = atoi(userIn);
      if (i > 0 && i <= 9)
      {
        return menu[i].function;
        
      }

    }
    return NULL;*/
    return NULL;
}
    
    
