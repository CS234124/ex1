#include <stdio.h>      
#include <stdlib.h>     
#include "tools/israeliqueue.h"

//creating the nodes of people in our list with the relevant values
typedef struct person 
{
int friendsPassed;
int enemyHeldBack;
struct person* next;
} person;

struct IsraeliQueue_t
{
 person* head;
 //2 implementation of array of functions one for frindships and one for 
 int friendship_th;
 int rivalry_th;

}


