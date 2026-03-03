#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

#define max_ids 3000

int main (void)
{
  srand(time(NULL));

  int *array = createDataSet(max_ids);

  int id = 0;

  for (int i = 0; i<1000; i++)
  {
    int prev_id = rand() % 2 + 1;
    id = id + prev_id;
    int age = rand() % (30 - 18 + 1) + 18;
    insertion(array, id, age);
  }

  int random_id = rand() % (2000) + 1;

  searchID (array, random_id);

  deletion (array, random_id);

  deleteDataSet (array);

  return 0;

}
