#ifndef DATASETH
#define DATASETH

//Data Type Declaration
typedef struct ds {
  int* array;
  int max_students;
} DS;

//Functions

DS* createDataSet (int max_students);
void deleteDataSet (DS *ds);
void searchID (DS *ds, int id);
void insertion (DS *ds, int id, int age);
void deletion (DS *ds, int id);

#endif
