#ifndef DATASETH
#define DATASETH

int* createDataSet (int max_students);
void deleteDataSet (int *array);
void searchID (int *array, int id);
void insertion (int *array, int id, int age);
void deletion (int *array, int id);

#endif
