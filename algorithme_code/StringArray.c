/* ========================================================================= *
 * StringArray.c
 *
 * Partial implementation of the StringArray interface
 * ========================================================================= */

#include <stdlib.h>

#include "StringArray.h"
#include "Set.h"



/* Constant */
static const size_t INITIAL_CAPACITY = 100;

struct StringArray_t
{
    char** values;
    size_t length;
    size_t capacity;

};


StringArray* createEmptyArray()
{

  StringArray* array = (StringArray*) malloc(sizeof(StringArray));
  if(!array)
    return NULL;

  char** values = (char**) malloc(sizeof(char*)*INITIAL_CAPACITY);
  if(!values)
  {
    free(array);
    return NULL;
  }
  array->values = values;
  array->length = 0;
  array->capacity = INITIAL_CAPACITY;

  return array;
}


void freeArray(StringArray* array, bool deleteElements)
{
  if (deleteElements)
  {
    for (size_t i = 0; i < array->length; i++)
      free((char*)array->values[i]);
  }

  free(array->values);
  free(array);
}

bool insertInArray(StringArray* array, char* element)
{
  if(array->length == array->capacity)
  {
    array->capacity *= 2;
    char** newValues = realloc(array->values, array->capacity * sizeof(char*));
    if (!newValues)
      return false;
    array->values = newValues;
  }

  array->values[array->length] = element;
  array->length++;
  return true;
}

size_t arrayLength(const StringArray* array)
{
  return array->length;
}

char* getElementInArray(const StringArray* array, size_t position)
{
  return array->values[position];
}

void shuffleArray(StringArray* array)
{
  // Fisher-Yates shuffling algorithm
  size_t i = array->length - 1;
  size_t j;
  char* temp;

  while (i > 0)
  {
      j = (size_t)rand() % (i + 1);
      temp = array->values[i];
      array->values[i] = array->values[j];
      array->values[j] = temp;
      i--;
  }
}

StringArray* getIntersection(const StringArray* array1, const StringArray* array2)
{
  if (!array1 || !array2)
    return NULL;

  // Build two sets from the arrays (no string copy: we reuse pointers)
  Set* set1 = createEmptySet();
  Set* set2 = createEmptySet();
  if (!set1 || !set2)
  {
    if (set1) freeSet(set1);
    if (set2) freeSet(set2);
    return NULL;
  }

  // Insert all strings from array1 into set1
  for (size_t i = 0; i < arrayLength(array1); i++)
  {
    char* s = getElementInArray(array1, i);
    if (!s) continue;
    if (insertInSet(set1, s) == ALLOC_ERROR)
    {
      freeSet(set1);
      freeSet(set2);
      return NULL;
    }
  }

  // Insert all strings from array2 into set2
  for (size_t i = 0; i < arrayLength(array2); i++)
  {
    char* s = getElementInArray(array2, i);
    if (!s) continue;
    if (insertInSet(set2, s) == ALLOC_ERROR)
    {
      freeSet(set1);
      freeSet(set2);
      return NULL;
    }
  }

  // Compute intersection: iterate on the smaller set for efficiency
  StringArray* inter = NULL;
  if (sizeOfSet(set1) <= sizeOfSet(set2))
    inter = setIntersection(set1, set2);
  else
    inter = setIntersection(set2, set1);

  freeSet(set1);
  freeSet(set2);
  return inter;
}



