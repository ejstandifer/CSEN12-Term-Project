#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dataset.h"

#define arr_offset 18
#define num_lists 13
#define max_age 30

DS* createDataSet(void)
{
  DS *ds;
  ds = malloc(sizeof(DS));
  assert(ds != NULL);
  ds->lists = malloc(num_lists * sizeof(NODE*));
  assert(ds->lists != NULL);
  for(int i = 0; i<num_lists; i++)
  {
    ds->lists[i] = (NODE*)malloc(sizeof(NODE));
    ds->lists[i]->id = 0;
    ds->lists[i]->age = 0;
    ds->lists[i]->next = ds->lists[i];
    ds->lists[i]->prev = ds->lists[i];
  }
  return ds;

}

void destroyDataSet(DS *ds)
{
  assert (ds != NULL);

  for(int i = 0; i<num_lists; i++)
  {
    NODE *head = ds->lists[i];
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
  free(ds->lists);
  free(ds);
  return;
}

void searchAge(DS *ds, int age)
{
  assert(ds != NULL);

  NODE *head = ds->lists[age - arr_offset];
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

 for(int i = 0; i<num_lists; i++)
 {
   NODE *head = ds->lists[i];

   NODE* current = head->next;

   while(current != head)
   {
     if(current->id == search_id)
     {
       printf("Student #%d Found; Age: %d\n", search_id, current->age);
       return;
     }

     if(current->id < search_id)
     {
       break;
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

  NODE *head = ds->lists[new_age - arr_offset];
  new->next = head->next;
  new->prev = head;
  head->next = new;
  new->next->prev = new;

  return;

}

void deletion (DS *ds, int search_id)
{
 assert(ds != NULL);

 for(int i = 0; i<num_lists; i++)
 {
   NODE *head = ds->lists[i];

   NODE* current = head->next;

   while(current != head)
   {
     if(current->id == search_id)
     {
       int temp = current->id;
       current->prev->next = current->next;
       current->next->prev = current->prev;
       free(current);

       printf("Deleted Student #%d\n", temp);
      
       return;
     }

     if(current->id < search_id)
     {
       break;
     }
     current = current->next;
    }
  }
  printf("Student #%d Not Found; Deletion Unsuccessful\n", search_id);
  return;
  
}

void maxAgeGap (DS *ds)
{
  assert(ds != NULL);

  int min = max_age + 1;
  int max = arr_offset - 1;

  for(int i = 0; i<num_lists; i++)
  {
    NODE *head = ds->lists[i];

    if(head->next != head)
    {
      if((i + arr_offset) < min)
      {
        min = i + arr_offset;
      }

      if((i + arr_offset) > max)
      {
        max = i + arr_offset;
      }
    }
  }

  printf("Maximum Age Gap: %d\n", max - min);
  return;
}
