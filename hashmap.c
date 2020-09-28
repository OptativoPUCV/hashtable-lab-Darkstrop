#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;
int enlarge_called=0;

struct Pair {
     char * key;
     void * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) 
{
int posit= hash(key,map->capacity), k;
Pair* exe= createPair(key,value);
k=posit;
while(posit <= map -> capacity)
{
  if((map->buckets[k]==NULL)||(exe->key==NULL))
  {
    map->buckets[k]=exe;
    map->size++;
    break;
  }
  else
  {
      if(k==(map->capacity - 1))
      {
        k=0;
      }
  }    
  k++;
}
}

void enlarge(HashMap * map) 
{
    enlarge_called = 1; //no borrar (testing purposes)


}
HashMap * createMap(long capacity) 
{
  HashMap* map=(HashMap*)malloc(sizeof(HashMap));
  map->buckets=(Pair**)malloc(sizeof(Pair*)*capacity);
  map->capacity=capacity;
  map->current=-1;
  map->size=0;

  return map;
}

void eraseMap(HashMap * map,  char * key) 
{    


//Pair->key= NULL;

}

void * searchMap(HashMap * map,  char * key) 
{   
  long oxo= hash(key,map->capacity);
  long i;
  for(i=oxo;i< map->capacity ;i++)
  {
    if((map->buckets[i]==NULL)||(map->buckets[i]->key==NULL))
    {
     return NULL;
    }
    if(is_equal(map->buckets[i]->key, key))
    {
      return map->buckets[i]->value;
    }
  }
  if((float)map->size/(float)map->capacity > 0.7)
  {
    enlarge(map); 
  }

   return NULL;
}

void * firstMap(HashMap * map) 
{

    return NULL;
}

void * nextMap(HashMap * map) 
{

    return NULL;
}
