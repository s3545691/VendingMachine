/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_options.h"


Node * currentNode;
Stock * stock;
Stock * newStock;
Node * newNode;
/**
 * vm_options.c this is where you need to implement the system handling
 * functions (e.g., init, free, load, save) and the main options for
 * your program. You may however have some of the actual work done
 * in functions defined elsewhere.
 **/

/**
 * Initialise the system to a known safe state. Look at the structure
 * defined in vm_system.h.
 **/
Boolean systemInit(VmSystem * system)
{
  listCreate(system);
  return FALSE;
}

/**
 * Free all memory that has been allocated. If you are struggling to
 * find all your memory leaks, compile your program with the -g flag
 * and run it through valgrind.
 **/
void systemFree(VmSystem * system)
{
listFree(system);
}

/**
 * Loads the stock and coin data into the system. You will also need to assign
 * the char pointers to the stock and coin file names in the system here so
 * that the same files will be used for saving. A key part of this function is
 * validation. A substantial number of marks are allocated to this function.
 **/
Boolean loadData(
    VmSystem * system, const char * stockFileName, const char * coinsFileName)
{
    return FALSE;
}

/**
 * Loads the stock file data into the system.
 **/
Boolean loadStock(VmSystem * system, const char * fileName)
{
    int i;
    
    FILE *fp;
    char buffer[150];
    
    
    /* Open the file for reading in the stock */
  /*  printf ("File, %s, being opened to load stock\n", fileName); */
    
    fp = fopen (fileName,"r");
    if (fp == NULL) {
        printf ("File, %s, cannot be opened", fileName);
        return FALSE;
    }
   /* printf("\n hello %s \n", fileName); */
    while(fgets(buffer, 150, fp) != NULL)
    {
        i = strlen(buffer) - 1;
        if (buffer[ i ] == '\n')
            buffer[i] = '\0';
        /*string toks on buffer */
      /*  printf("Buffer checking: %s. \n", buffer); */
       newStock=stockTok(buffer);
       newNode = createNode(newStock);
      insertNode(system->itemList, newNode);      
    }
    fclose(fp);
    return FALSE;
}

/**
 * Loads the coin file data into the system.
 **/
Boolean loadCoins(VmSystem * system, const char * fileName)
{
    return FALSE;
}

/**
 * Saves all the stock back to the stock file.
 **/
Boolean saveStock(VmSystem * system)
{
    FILE * fp;
    Node * curr;
    Stock * stock;

   /* List *current,*head,*previous; */

    fp = fopen("stock.dat", "w");

    if(fp == NULL)
      return FALSE;

    
    curr = system->itemList->head;
    
    while(curr != NULL)     
    {
     /* curr = curr->next; */
      stock = curr->data;
      fprintf(fp, "%s|%s|%s|%u.%02u|%u\n",
      stock->id, stock->name, stock->desc,stock->price.dollars, stock->price.cents, stock->onHand);
      curr = curr->next;
    }
    fclose(fp);
    return TRUE;
    listFree(system);
  }


/**
 * Saves all the coins back to the coins file.
 **/
Boolean saveCoins(VmSystem * system)
{
    return FALSE;
}

/**
 * This option allows the user to display the items in the system.
 * This is the data loaded into the linked list in the requirement 2.
 **/
void displayItems(VmSystem * system)
{
    Stock * stock;
    currentNode = system->itemList->head;
    printf("Items Menu\n\n");
    printf("ID    | Name                | Avaliable  | Price\n");
    printf("-----------------------------------------------\n");
    while (currentNode != NULL)
    { 
        stock = currentNode->data;   
        printf("%-6s|", stock->id);
        printf(" %-20s|", stock->name);
     /*   printf("%s|", stock->desc);
        printf("%d.%d|", stock->price.dollars,stock->price.cents); */
        printf(" %-11d|", stock->onHand);
        printf(" %-d.%d\n", stock->price.dollars,stock->price.cents);
        currentNode = currentNode->next;
    }
    menuLoad();
}

/**
 * This option allows the user to purchase an item.
 * This function implements requirement 5 of the assignment specification.
 **/
void purchaseItem(VmSystem * system)
{
    Node * currentNode;
    char inputItem[80]; 
    Stock * stock;
    int i;
    
    printf("Please enter the id of the item you wish to purchase: ");
    fgets(inputItem, 80, stdin);
            i = strlen(inputItem) - 1;
        if (inputItem[ i ] == '\n')
            inputItem[i] = '\0';
    currentNode = system->itemList->head;

    while (currentNode != NULL)
    {
        stock = currentNode->data;
        if (strcmp(currentNode->data->id, inputItem)== 0)
        {
         printf("You have selected \"%s\". This will cost you $%d.%d.\n",stock->desc,stock->price.dollars,stock->price.cents);
         printf("Please hand over the money - type in the calue of each note/coin in cents.\n");
         printf("Press enter on a new and empty line to cancel this purchase:\n");
       /*  printf("ID: %s\n", stock->id); */
        /* printf("Stock: %s\n", stock->name); */
            /*to break from loop */
         payForItem(system,stock);
         return;
        }
        else {
            currentNode=currentNode->next;
        }
    }
    printf("ERROR please enter a valid item\n");
    menuLoad();

 
}



/**
 * You must save all data to the data files that were provided on the command
 * line when the program loaded up, display goodbye and free the system.
 * This function implements requirement 6 of the assignment specification.
 **/
void saveAndExit(VmSystem * system)
{
    saveStock(system);
    abortProgram(system);

}

/**
 * This option adds an item to the system. This function implements
 * requirement 7 of of assignment specification.
 **/
void addItem(VmSystem * system)
{
    Stock * stock;
    char * test;
    int tempNum;
    char tempNumStr[80];
    char stringOneTemp[80];
    int newNum;
    int intOne;
    int intTwo;
    int intThree;
    int intFour;
    int charCount;
    int m;
    int i;
    char userInTwo[80];
    char userInThree[1000];
    char userInFour[80];
    char itemName[80];
    char itemDesc[1000];
    char itemPrice[80];
    char finalString[80];
    Node *currentNode;
    
    currentNode = system->itemList->head;
   /* while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }*/
    if (currentNode != NULL) 
    { 
        stock = currentNode->data;
        if(stock == NULL)
        {
          printf("No item by ID: %s\n",stock->id );
        }
        else
        {
            test=stock->id;
            /*printf("output is: %c %c %c %c %c\n", test[1], test[2], test[3], test[4], test[5]); */
            intOne = test[1] - '0';
            intTwo = test[2] - '0';
            intThree = test[3] - '0';
            intFour = test[4] - '0';
            tempNum=((intOne*1000) + (intTwo*100)+ (intThree*10) + (intFour*1));
       /*     printf("tempNum is: %i",tempNum); */
            /*printf("Output 2 is: %i + %i + %i + %i = %i\n",intOne * 1000, intTwo * 100, intThree * 10, intFour, tempNum); */
            newNum=tempNum + 1;
            /*printf("The new number is: %i\n", newNum); */
            sprintf(tempNumStr,"%d",newNum);
           /* itoa(newNum, tempNumStr, 10); */
            charCount = 0;
            for(m=0; tempNumStr[m]; m ++)
            {
                if (tempNumStr[m] != ' ')
                {
                    charCount ++;
                }
            }
            if (charCount == 1)
            {
                strcpy(stringOneTemp, tempNumStr);
              /*  printf("sstringOneTemp= %s\n", tempNumStr); */
                strcpy(tempNumStr,"I000");
                /*printf("tempNumStr= %s\n", tempNumStr);*/
                strcat(tempNumStr,stringOneTemp);
                /*printf("tempNumStr= %s\n", tempNumStr); */
            }
            if (charCount == 2)
            {
                strcpy(stringOneTemp, tempNumStr);
              /*  printf("sstringOneTemp= %s\n", tempNumStr); */
                strcpy(tempNumStr,"I00");
                /*printf("tempNumStr= %s\n", tempNumStr);*/
                strcat(tempNumStr,stringOneTemp);
                /*printf("tempNumStr= %s\n", tempNumStr); */
            }
            if (charCount == 3)
            {
                strcpy(stringOneTemp, tempNumStr);
              /*  printf("sstringOneTemp= %s\n", tempNumStr); */
                strcpy(tempNumStr,"I0");
                /*printf("tempNumStr= %s\n", tempNumStr);*/
                strcat(tempNumStr,stringOneTemp);
                /*printf("tempNumStr= %s\n", tempNumStr); */
            }
            if (charCount == 4)
            {
                strcpy(stringOneTemp, tempNumStr);
              /*  printf("sstringOneTemp= %s\n", tempNumStr); */
                strcpy(tempNumStr,"I");
                /*printf("tempNumStr= %s\n", tempNumStr);*/
                strcat(tempNumStr,stringOneTemp);
                /*printf("tempNumStr= %s\n", tempNumStr); */
            }
           /* printf("Output test 2 is : %s", tempNum); */
            printf("This new meal item will have the item id of %s\n", tempNumStr);
            printf("Enter the item name: ");
            fgets(userInTwo, 100, stdin);
                

        /* remove newline, if present */
        i = strlen(userInTwo) - 1;
        if (userInTwo[ i ] == '\n')
            userInTwo[i] = '\0';
        
         strcpy(itemName,userInTwo);
         
         printf("Enter the item description: ");
            fgets(userInThree, 100, stdin);
                

        /* remove newline, if present */
        i = strlen(userInThree) - 1;
        if (userInThree[ i ] == '\n')
            userInThree[i] = '\0';
        
         strcpy(itemDesc,userInThree);
         
         
         printf("Enter the Price for this item: ");
            fgets(userInFour, 100, stdin);
                

        /* remove newline, if present */
        i = strlen(userInFour) - 1;
        if (userInFour[ i ] == '\n')
            userInFour[i] = '\0';
        
         strcpy(itemPrice,userInFour);
       
         
         
         
         finalString[0] = 0;
         strcat(finalString,tempNumStr);
         strcat(finalString,"|");
         strcat(finalString,itemName);
         strcat(finalString,"|");
         strcat(finalString,itemDesc);
         strcat(finalString,"|");
         strcat(finalString,itemPrice);
         strcat(finalString,"|");
         strcat(finalString,"20");
                 
         /*printf("All of em ay: %s , %s , %s\n", itemName, itemDesc, itemPrice);
         printf(finalString);*/
         
         newStock=stockTok(finalString);
         newNode = createNode(newStock);
         insertNode(system->itemList, newNode);
         
         menuLoad();
       
        
        
        
        }
   }
    
}

/**
 * Remove an item from the system, including free'ing its memory.
 * This function implements requirement 8 of the assignment specification.
 **/
void removeItem(VmSystem * system)
{
    char inputtedId[80];
    
    int i;
    
    printf("Enter the item id of the item to remove from the menu: ");
    
    fgets(inputtedId, 100, stdin);
                
        /* remove newline, if present */
        i = strlen(inputtedId) - 1;
        if (inputtedId[ i ] == '\n')
            inputtedId[i] = '\0';
        
        stock = searchStock(system->itemList, inputtedId);   
        removeStock(system->itemList, stock);
        printf("\"%s - %s\" has been removed from the system.\n", stock->id, stock->desc);
   /* removeStock(system->itemList, inputtedId); */
        menuLoad();



}

/**
 * This option will require you to display the coins from lowest to highest
 * value and the counts of coins should be correctly aligned.
 * This function implements part 4 of requirement 18 in the assignment
 * specifications.
 **/
void displayCoins(VmSystem * system)
{ }

/**
 * This option will require you to iterate over every stock in the
 * list and set its onHand count to the default value specified in
 * the startup code.
 * This function implements requirement 9 of the assignment specification.
 **/
void resetStock(VmSystem * system)
{
    defaultStock(system->itemList);
    printf("All stock has been reset to the default level of %d", DEFAULT_STOCK_LEVEL);
}

/**
 * This option will require you to iterate over every coin in the coin
 * list and set its 'count' to the default value specified in the
 * startup code.
 * This requirement implements part 3 of requirement 18 in the
 * assignment specifications.
 **/
void resetCoins(VmSystem * system)
{ }

/**
 * This option will require you to display goodbye and free the system.
 * This function implements requirement 10 of the assignment specification.
 **/
void abortProgram(VmSystem * system)
{ 
    listFree(system);
    exit(0);
    printf("Should have exited\n");
}
