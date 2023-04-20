#include <stdio.h>      
#include <stdlib.h>     
#include "IsraeliQueue.h"

//creating the nodes of people in our list with the relevant values
typedef struct person {
  int friendsPassed;
  int enemyHeldBack;
struct Person* next;
} Person;

struct IsraeliQueue_t
{
  struct person* head;
  int friendshipCounter; //for realloc and free
  FriendshipFunction* friendshipFunctions; 
  ComparisonFunction compare;
  int friendship_th;
  int rivalry_th;

};
IsraeliQueue IsraeliQueueCreate(FriendshipFunction* friendFunctions, ComparisonFunction compFunction, int friendThres, int rivalTres){
  IsraeliQueue queue = (IsraeliQueue)malloc(sizeof(IsraeliQueue));
  queue->friendshipFunctions = friendFunctions;
  queue->compare = compFunction;
  queue->friendship_th = friendThres;
  queue->rivalry_th = rivalTres;
  return queue;
}
void IsraeliQueueDestroy(IsraeliQueue queue){
  struct person* p = queue->head;
  while(p != NULL){
    struct person* temp = p;
    p = p->next;
    free(temp);
  }
}



