#ifndef DATASETH
#define DATASETH

typedef struct node {

  int age;
  int id;
  struct node *next;
  struct node *prev;
} NODE;

typedef struct ds {
  NODE* lp;
  int min_age;
  int max_age;
} DS;

ds createDataSet (void);
void destroyDataSet (DS *ds);
void searchAge (DS *ds, int age);
void searchID (DS *ds, int id);
void insertion (DS *ds, int id, int age);
void deletion (DS *ds, int id);
void maxAgeGap (DS *ds);

#endif

