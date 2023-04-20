#include <stdio.h>      
#include <stdlib.h>     
#include "IsraeliQueue.h"

//creating the nodes of people in our list with the relevant values
typedef struct person {
  int friendsPassed;
  int enemyHeldBack;
struct person* next;
} person;

struct funcNode{
  FriendshipFunction func;
  struct funcNode *next;
};

struct IsraeliQueue_t
{
  struct person* head;
  struct funcNode* funcList;
  //int friendshipCounter; //for realloc and free
  //FriendshipFunction* friendshipFunctions;
  ComparisonFunction compare;
  int friendship_th;
  int rivalry_th;

};
IsraeliQueue IsraeliQueueCreate(FriendshipFunction* friendFunctions, ComparisonFunction compFunction, int friendThres, int rivalTres){
  IsraeliQueue queue = (IsraeliQueue)malloc(sizeof(IsraeliQueue));
  //queue->friendshipFunctions = friendFunctions;
  queue->compare = compFunction;
  queue->friendship_th = friendThres;
  queue->rivalry_th = rivalTres;
  if(friendFunctions[0] != NULL){
    queue->funcList = (struct funcNode*)(malloc(sizeof(struct funcNode)));
    queue->funcList->func = friendFunctions[0];
    struct funcNode *temp = queue->funcList;
    for(int i = 1 ; friendFunctions[i] != NULL ; i++){
      temp->next = (struct funcNode*)(malloc(sizeof(struct funcNode)));
      temp->next->func = friendFunctions[i];
      temp = temp->next;
    }
  }
  return queue;
}
void IsraeliQueueDestroy(IsraeliQueue queue){
  struct person* p = queue->head;
  while(p != NULL){
    struct person* temp = p;
    p = p->next;
    free(temp);
  }
  struct funcNode* f = queue->funcList;
  while(f != NULL){
    struct funcNode* temp = f;
    f = f->next;
    free(temp);
  }
}
IsraeliQueueError IsraeliQueueUpdateFriendshipThreshold(IsraeliQueue queue, int threshold){
    queue->friendship_th = threshold;
    if(queue->friendship_th == threshold) return ISRAELIQUEUE_SUCCESS;
    return ISRAELI_QUEUE_ERROR;
}
IsraeliQueueError IsraeliQueueUpdateRivalryThreshold(IsraeliQueue queue, int threshold){
    queue->rivalry_th = threshold;
    if(queue->rivalry_th == threshold) return ISRAELIQUEUE_SUCCESS;
    return ISRAELI_QUEUE_ERROR;
}



