//By: Eddie Standifer
//CSEN 12 Term Project Due: 3/4/26
//
//App 2 college.c
//
//Main file that generates and inserts random student ids, searches and deletes a random student, and then deletes the dataset


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

#define max_ids 3000 //max id value; length of the id array

int main (void)
{
  srand(time(NULL)); //seed for random int generation

  DS *ds = createDataSet(max_ids);

  int id = rand() % 2 + 1; //generates 1 or 2
  int age = rand() % (30 - 18 + 1) + 18;
  insertion(ds, id, age);

  //generate and insert students
  for (int i = 1; i<1000; i++)
  {
    id = id + rand() % 2 + 1;
    age = rand() % (30 - 18 + 1) + 18;
    insertion(ds, id, age);
  }

  int random_id = rand() % (2000) + 1;

  searchID (ds, random_id);

  deletion (ds, random_id);

  destroyDataSet (ds);

  return 0;

}
