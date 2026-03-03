#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

#define max_ids 3000

int main (void)
{
  srand(time(NULL));

  DS *ds = createDataSet(max_ids);

  int id = rand() % 2 + 1;
  int age = rand() % (30 - 18 + 1) + 18;
  insertion(ds, id, age);

  for (int i = 1; i<1000; i++)
  {
    id = id + rand() % 2 + 1;
    age = rand() % (30 - 18 + 1) + 18;
    insertion(ds, id, age);
  }

  int random_id = rand() % (2000) + 1;

  searchID (ds, random_id);

  deletion (ds, random_id);

  deleteDataSet (ds);

  return 0;

}
