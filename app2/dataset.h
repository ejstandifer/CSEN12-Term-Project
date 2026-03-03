#ifndef DATASETH
#define DATASETH

typedef struct ds {
  int* array;
  int max_students;
} DS;


DS* createDataSet (int max_students);
void deleteDataSet (DS *ds);
void searchID (DS *ds, int id);
void insertion (DS *ds, int id, int age);
void deletion (DS *ds, int id);

#endif
