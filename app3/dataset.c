#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dataset.h"


DS* createDataSet(void)
{
  DS *ds;
  ds = malloc(sizeof(DS));
  assert(ds != NULL);
  ds->lp = malloc(13 * sizeof(NODE*));
  assert(ds->lp != NULL);
  for(int i = 0; i<13; i++)
  {
    ds->lp[i] = (NODE*)malloc(sizeof(NODE));
    ds->lp[i]->id = 0;
    ds->lp[i]->age = 0;
    ds->lp[i]->next = ds->lp[i];
    ds->lp[i]->prev = ds->lp[i];
  }
  return ds;

}

void destroyDataSet(DS *ds)
{
  assert (ds != NULL);

  for(int i = 0; i<13; i++)
  {
    NODE *head = ds->lp[i];
    NODE *current = head->next;
    NODE *next;

    while(current != head)
    {
      next = current->next;
      free(current);
      current = next;
    }
    free(head);
  }
  free(ds->lp);
  free(ds);
  return;
}

void searchAge(DS *ds, int age)
{
  assert(ds != NULL);

  NODE *head = ds->lp[age - 18];
  NODE *current = head->next;

  if(head->next == head)
  {
    printf("No Students Age %d\n", age);
    return;
  }

  while(current != head)
  {
    printf("Student Age %d Found; ID#%d\n", age, current->id);
    current = current->next; 
  }
  return;
}

void searchID(DS *ds, int search_id)
{
 assert(ds != NULL);

 for(int i = 0; i<13; i++)
 {
   NODE *head = ds->lp[i];

   if(head->next->id > search_id || head->prev->id < search_id)
   {
     continue;
   }
   NODE* current = head->next;

   while(current != head)
   {
     if(current->id == search_id)
     {
       printf("Student #%d Found; Age: %d\n", search_id, current->age);
       return;
     }
     current = current->next;
   }
 }
 printf("Student #%d Not Found\n", search_id);
 
 return;
}

void insertion (DS *ds, int new_id, int new_age)
{
  assert(ds != NULL);

  NODE *new = malloc(sizeof(NODE));
  assert(new != NULL);
  new->id = new_id;
  new->age = new_age;

  NODE *head = ds->lp[new_age - 18];
  new->next = head->next;
  new->prev = head;
  head->next = new;
  new->next->prev = new;

  return;

}

void deletion (DS *ds, int search_id)
{
 assert(ds != NULL);

 for(int i = 0; i<13; i++)
 {
   NODE *head = ds->lp[i - 18];

   if(head->next->id > search_id || head->prev->id < search_id)
   {
     continue;
   }
   NODE* current = head->next;

   while(current != head)
   {
     if(current->id == search_id)
     {
       int temp = current->id;
       current->prev->next = current->next;
       current->next->prev = current->prev;
       free(current);

       printf("Deleted Student#%d\n", temp);
      
       return;
     }
     current = current->next;
    }
  }
  printf("Student#%d Not Found\n", search_id);
  return;
  
}

void maxAgeGap (DS *ds)
{
  assert(ds != NULL);

  int min = 0;
  int max = 0;

  for(int i = 0; i<13; i++)
  {
    NODE *head = ds->lp[i];

    if(head->next != head)
    {
      if((i + 18) < min)
      {
        min = i + 18;
      }

      if((i + 18) > max)
      {
        max = i + 18;
      }
    }
  }

  printf("Maximum Age Gap: %d\n", max - min);
  return;
}
