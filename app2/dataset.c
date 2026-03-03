#include <stdio.h>
#include <stdlib.h>
#include "dataset.h"

int* createDataSet(int max_students)
{
  int *array = (int*)calloc(max_students, sizeof(int));

  return array;
} 

void deleteDataSet (int *array)
{
  free(array);

  return;
}

void searchID (int* array, int id)
{
  if(array[id - 1] != 0)
  {
    printf("Student ID#%d found; Age: %d\n", id, array[id - 1]);

    return;
  }

  else
  {
    printf("Student ID#%d Not Found During Search\n", id);
  }
  return;
}

void insertion (int *array, int id, int age)
{
  array[id - 1] = age;

  return;
}

void deletion (int *array, int id)
{
  if(array[id - 1] != 0)
  {
    array[id - 1] = 0;
    printf("Student ID#%d Deleted\n", id);
    
    return;
  }

  else
  {
    printf("Student ID#%d Not Found; Not Deleted\n", id);
  }

  return;
}

