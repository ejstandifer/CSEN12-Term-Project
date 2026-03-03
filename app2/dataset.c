#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dataset.h"

DS* createDataSet(int max_students)
{
  DS *ds = malloc(sizeof(DS));
  assert(ds != NULL);

  ds->array = (int*)calloc(max_students, sizeof(int));
  assert(ds->array != NULL);

  ds->max_students = max_students;

  return ds;
} 

void deleteDataSet (DS* ds)
{
  assert(ds != NULL);

  free(ds->array);
  free(ds);

  return;
}

void searchID (DS* ds, int id)
{
  assert(ds != NULL);

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

void insertion (DS* ds, int id, int age)
{
  assert(ds != NULL && id > 0 && id < ds->max_students);

  ds->array[id - 1] = age;

  return;
}

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

