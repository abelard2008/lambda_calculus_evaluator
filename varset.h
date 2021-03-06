/***************************************************************/
/* File: varset.h                                              */
/* Definition of the data structure of free variable set.      */
/* Author: Minjie Zha                                          */
/***************************************************************/

#ifndef _VARSET_H_
#define _VARSET_H_

/* Size of the hash table. */
#define SIZE 211

/* Bucket in the hash table. */
typedef struct bucketList {
    char * name;
    struct bucketList * next;
} * BucketList;

/* Free variable set. */
typedef struct varset {
    BucketList hashset[SIZE];
} VarSet;

/* Free variable list. */
typedef struct varsetlist {
    char *name;
    struct varsetlist *next;
} VarSetList;

/* Create a variable set. */
VarSet * newVarSet(void);

/* Deallocate the variable set. */
void deleteVarSet(VarSet * varSet);

/* Add a variable to set. */
void addVar(VarSet* varSet, const char * var);

/* Delete a variable from set. */
void deleteVar(VarSet* varSet, const char *var);

/* Take the union of two sets. */
void unionVarSet(VarSet* newSet, VarSet* set1, VarSet* set2);

/* Test if the set contains the variable. */
int contains(VarSet* set, const char *var);

/* Returns true if the set is empty. */
int vs_empty(VarSet* set);

/* Returns the variable set as a list. */
VarSetList* vs_asList(VarSet *set);

/* Deletes the variable set list. */
void vs_deleteVarSetList(VarSetList *list);
#endif
