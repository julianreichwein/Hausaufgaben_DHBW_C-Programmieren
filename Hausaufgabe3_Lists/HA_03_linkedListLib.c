#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HA03_linkedListLib.h"

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}

void printList(listElement *start){
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int i = 0;
        listElement *currElem = start;
        printf("\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                printf("%d.)",i); i++;
                printf("\tlast Name: %s\n",currElem->lastName);
                printf("\tfirst Name: %s\n",currElem->firstName);
                printf("\tage : %d\n",currElem->age);
            } while (currElem->nextElem != NULL);
    printf("\n");
    }
}

void delListElem(listElement *start){

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");
    
 

    /* YOUR CODE HERE */
    /* ---------------- 


        1.) Check if fopen() was successful.
            Otherwise exit function with return and inform the user about the canceled task.

    */     

	if (fPtr == NULL)
  {
		printf("\nCould not open dim file.\n");
	}
	else
  {
		printf("\nOpening file was successful.\n");
	}
/*
        2.) Use fprintf() to write length of list as first value to the text file.
            This will be the first information needed by the loadList function.
            
            */

      int length = getLenOfList(start);
      printf("length is: %d\n", length);
 	    fprintf(fPtr, "%d\n", length);
        

/*
        3.) Use fprintf() to write every field of the structs to the text file.
            Consider to loop over the listelements for this task.
            It might be handy to use an iteration pointer on this stage :-*
*/
        
          int i = 0;
          listElement *currElem = start;
          do{
            currElem = currElem->nextElem;
            fprintf(fPtr, "%d.)",i); i++;
            fprintf(fPtr, "\tlast Name: %s\n",currElem->lastName);
            fprintf(fPtr, "\tfirst Name: %s\n",currElem->firstName);
            fprintf(fPtr, "\tage : %d\n",currElem->age);
          }while (currElem->nextElem != NULL);
        
/*
        4.) The user needs to be informed about the successful saving process.
            Don't forget to close the file stream!
*/
    printf("\n\nif you wonna know wether it was successful, then open se liste\n");
    delay(2000);
    printf("just kiddin'  \n");
    if(currElem->nextElem == NULL)
    {
      printf("saved successfully\n\n");
    }
/*
    */
		fclose(fPtr);
}

void loadList(listElement *start){
	
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("ls *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");
	
    /* 1.) Check if fopen() was successful.
           Otherwise exit function with return and inform the user about the canceled task.*/
        if (fPtr == NULL)
        {
          printf("\nCould not open dim file.\n");
        }
        else
        {
          printf("\nOpening file was successful.\n");
        }
/*

        2.) Use fscanf() to read the first value of the text file.
            This will be the information about the length of the list to be loaded.*/
        int length = 0;
        fscanf (fPtr, "%d", &length);
        printf("length of list amounted to: %d\n", length);
/*

        3.) Use fscanf() to read every field of the structs from text file.
            Consider to loop over the listelements for this task.
            You need to create a new instance listElement every iteration. 
            It might be handy to use an iteration pointer on this stage :-) */ 
          int i = 0;
          listElement *currElem = start;
          do{
            currElem = currElem->nextElem;
            fscanf(fPtr, "%d.)",&i); i++;
            fscanf(fPtr, "\tlast Name: %s\n",currElem->lastName);
            fscanf(fPtr, "\tfirst Name: %s\n",currElem->firstName);
            fscanf(fPtr, "\tage : %d\n",&currElem->age);
          }while (currElem->nextElem != NULL);
        
        if(currElem->nextElem == NULL){
          printf("loading completed");
        }

	
    
	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}