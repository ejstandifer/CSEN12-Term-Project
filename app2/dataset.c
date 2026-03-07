//By: Eddie Standifer
//
//CSEN 12 Term Project Due: 3/6/26
//App 2 dataset.c
//
//Implemntation of functions pertaining to app 2 requirements using a
//calloced array size 3000, where each index of the array corresponds
//to stundet ID#, (effectively a hash table with direct indexing)


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dataset.h"

//Creates dataset ptr and allocates memory for the array. Calloc needed
//to zero out elemenets

DS* createDataSet(int max_students)
{
  DS *ds = malloc(sizeof(DS));
  assert(ds != NULL);

  ds->array = (int*)calloc(max_students, sizeof(int));
  assert(ds->array != NULL);

  ds->max_students = max_students;

  return ds;
} 

//Deletes dataset by freeing pointers

void destroyDataSet (DS* ds)
{
  assert(ds != NULL);

  free(ds->array);
  free(ds);

  return;
}

//Finds student by accessing [id - 1] in the array

void searchID (DS* ds, int id)
{
  assert(ds != NULL && id > 0 && id <= ds->max_students);

  if(ds->array[id - 1] != 0)
  {
    printf("Student ID#%d Found; Age: %d\n", id, ds->array[id - 1]);

    return;
  }

  else
  {
    printf("Student ID#%d Not Found During Search\n", id);
  }
  return;
}

//Inserts new student into the array[i - 1]

void insertion (DS* ds, int id, int age)
{
  assert(ds != NULL && id > 0 && id <= ds->max_students);

  ds->array[id - 1] = age;

  return;
}


//Looks for student id# at array[i - 1] and sets elt to 0 if found

void deletion (DS* ds, int id)
{
  assert(ds != NULL);
  if(ds->array[id - 1] != 0)
  { 
    int temp_age = ds->array[id - 1];
    ds->array[id - 1] = 0;
    printf("Student ID#%d Deleted; Age: %d\n", id, temp_age);
    
    return;
  }

  else
  {
    printf("Student ID#%d Not Found; Not Deleted\n", id);
  }

  return;
}

