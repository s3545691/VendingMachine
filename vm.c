/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm.h"
char *userInput;
MenuItem menu;
VmSystem vm;
MenuFunction menuFunction;
int x;
char userInTwo[80];
char * argumentOne;

int main(int argc, char ** argv)
{
    int i = 0;
    if (argc != 2)
    {
        printf("Error no file found");
        return(0);
    }
 for (i = 0; i < argc; i++)
         userInput=argv[i];
    argumentOne = userInput;
 systemInit(&vm);

 (void)loadStock(&vm, userInput);
/* displayItems(&vm);*/
 menuLoad(&vm);
    
    /*

    if(menuFunction != NULL)
        menuFunction(&vm);
      else
          printf("%s", menuFunction);
        printf("!!Invalid Options!!\n");
        
    */
 return EXIT_SUCCESS;
 
    
    /*
    printf("Goodbye. \n\n");
    printf(argv[0]);
    printf(argv[1]);
    printf(argv[2]);

    return EXIT_SUCCESS;
      */
}

void menuLoad()
{
    
    initMenu(&menu);
    
    
    x= atoi(fgets(userInTwo, 80, stdin));
    /*menuFunction=getMenuChoice(&menu); */
    if (x == 1)
        displayItems(&vm);
    if (x == 2)
        purchaseItem(&vm);
    if (x == 3)
    {
        saveStock(&vm);
        abortProgram(&vm);
    }
       /* (void)loadStock(&vm, userInput);
        saveStock(&vm); */
    if (x == 4)
        addItem(&vm);
    if (x == 5)
        removeItem(&vm);
    if (x == 7)
        resetStock(&vm);
    if (x == 9)
        abortProgram(&vm);
    else
    {
        printf("Please enter a valid command\n");
        menuLoad(&vm);
    }
}
