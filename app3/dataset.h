#ifndef DATASETH
#define DATASETH

//Data Type Declartation
typedef struct node {

  int age;
  int id;
  struct node *next;
  struct node *prev;
} NODE;

//Functions 

typedef struct ds {
  NODE** lists;
} DS;

DS* createDataSet (void);
void destroyDataSet (DS *ds);
void searchAge (DS *ds, int age);
void searchID (DS *ds, int id);
void insertion (DS *ds, int id, int age);
void deletion (DS *ds, int id);
void maxAgeGap (DS *ds);

#endif

