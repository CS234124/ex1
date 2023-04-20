#include <stdio.h>      
#include <stdlib.h>     
#include "tools/israeliqueue.h"

//creating the nodes of people in our list with the relevant values
typedef struct Person 
{
int friendsPassed;
int enemyHeldBack;
struct Person* next;
} Person;

struct IsraeliQueue
{
 person* head;
 int friendshipCounter=0; //for realloc and free
   FriendshipFunction* friendshipFunctions; 
   ComparisonFunction compare;
 int friendship_th;
 int rivalry_th;

}
IsraeliQueue IsraeliQueueClone(IsraeliQueue q)
{


}


