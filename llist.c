#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

 //Name: Danny Nsouli


struct LList* createLList() {
  /* Create an empty linked list. */
  /* DO NOT MODIFY THIS CODE */
  struct LList* list = malloc(sizeof(struct LList));
  list->head = NULL;
  return list;
}

void printList(struct LList *list)
{
  /* Print a list from head to tail. */
  /* DO NOT MODIFY THIS CODE */
  struct LNode *entry;
  if(list == NULL) {
    printf("List has not been initialized!\n");
    return;
  }
  entry = list->head;
  printf("List Contents:\n");
  while(entry != NULL)
  {
    printf("  %s is at %f, %f\n", entry->name, entry->latitude, entry->longitude);
    entry = entry->next;
  }
}


int addNode(struct LList *list, char* name, double lat, double lon) {
  /*  Add a new entry to the linked list. 
      Return the index number of the new entry 
  */
  struct LNode *newNode = (struct LNode*) malloc (sizeof(struct LNode)); //allocates space for the newNode to be added
  newNode->name = name;
  newNode->latitude = lat;
  newNode->longitude = lon;
  newNode->next = NULL;
  if (list->head == NULL) {
    
        list->head = newNode;     //if head is null then its an empty list so place new node at head
        return 0;
    } 
    else {
        struct LNode *cNode = list->head;
        int counter = 1;
    
        while (cNode->next != NULL) {       //otherwise go through the list until the next node after the current is null
            cNode = cNode->next;            //when loop stops means you have reached the end where the newNode will be placed
            counter++;
        }
        cNode->next = newNode;
      return counter;
    }
}


int remNode(struct LList *list, char* name)
{
 if (list->head == NULL) {
        printf("Error, empty list!");   //if empty list then nothing to delete
        return -1;
    }
  // strcmp(s1, s2)
   if(strcmp(list->head->name, name) == 0){
     struct LNode *temp = list->head;
      list->head=list->head->next;        //if both strings are the same strcmp will return 0
     free(temp);                         //if head has the targeted name then remove the head
     printf("\nCounter: %d\n", 0);
      return 0;
    }
    else {
        
        struct LNode *cNode = list->head;
        int counter = 1;
        while (cNode->next != NULL) {
            if(strcmp(cNode->next->name, name) == 0){
                                                              //if both strings are the same strcmp will return 0
            struct LNode *temp2 = cNode->next;              //then must free that node with the same name being targeted
            cNode->next= cNode->next->next;
            free(temp2);
            printf("\nCounter: %d\n", counter);
            return counter;
              
            }
          
          counter++;
          cNode = cNode->next;
        }
      printf("Error!! Name not found in list");
      return -1;
      
    }
  
}

int addSortedNode(struct LList *list, char* name, double lat, double lon)
{
  /*  Add a point to the list, sorted by longitude in ascending order. 
      Returns the position of the new point.
  */
   struct LNode *newNode = (struct LNode*) malloc (sizeof(struct LNode)); //allocates space for the newNode to be added
   newNode->name = name;
   newNode->latitude = lat;
   newNode->longitude = lon;
    if (list->head == NULL) {
      
        list->head = newNode;     //if the list is empty then place the newNode as the head
      
        return 0;
    }
    
    if (list->head->longitude >= newNode->longitude){
      
      newNode->next = list->head;                //if the head has a larger or equal longitude to the newNode then make
                                                  //the head the newNode and make the head point to the second element in the list
      list->head=newNode;
      return 0;
    }         
    else {
       struct LNode *cNode = list->head;
        int counter = 1;
    
        while (cNode->next != NULL) {                   //otherwise go through the list until there is a node that has a larger
                                                          //longitutude and then place the newNode before it
            if(cNode->next->longitude >= newNode->longitude){
             newNode->next = cNode->next;
              
            cNode->next = newNode;
            return counter;
            
            }
          
          
            counter++;
            cNode = cNode->next;
        }
       
      newNode->next = cNode->next;
              
      cNode->next = newNode;
      return counter;
      
    }
  
}

int clearList(struct LList *list) 
{
  /* Delete list and free all of the memory associate with its LNodes. */
  struct LNode *cNode = list->head;
    
    int counter = 0;
    if (list->head == NULL) {       //if empty list then nothing can be deleted
        return 0;
    } 
    
    while (cNode != NULL) {
    struct LNode *temp;
    temp = cNode->next;
    cNode->name = "";
    cNode->latitude = 0;        //otherwise sets everything to 0, string is set to nothing as well
    cNode->longitude = 0;       
    cNode = temp;
      
    counter++;
    
    
    }
    
    list->head = NULL;        //also head is set to null to signify an empty list
    
    return counter;
  
}
