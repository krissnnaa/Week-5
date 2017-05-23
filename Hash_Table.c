#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct hash_table {
   int key;
   int value;      
};

struct hash_table* hash_array[SIZE]; 
struct hash_table* item;

void insert(int key,int value) {

   struct hash_table *item = (struct hash_table*) malloc(sizeof(struct hash_table));
   item->value = value;  
   item->key = key;
   int index = hash_function(key);

   while(hash_array[index] != 0 && hash_array[index]->key != -1) {
      index=index +1;
      index=index % SIZE;
   }
	
   hash_array[index] = item;
}

struct hash_table *search(int key) {
   // To get the hash value 
   int index = hash_function(key);  
   //move in array until an empty 
   while(hash_array[index] != 0) {
	
      if(hash_array[index]->key == key)
         return hash_array[index]; 
			
       index=index +1;
       index=index % SIZE;
   }        
	
   return 0;        
}

int hash_function(int key) {
   return (key % SIZE);
}


void show() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hash_array[i] != 0)
         printf(" (%d,%d)",hash_array[i]->key,hash_array[i]->value);
   }
	
   printf("\n");
}

int main() {
  int i,n,m;
  struct hash_table *item = (struct hash_table*) malloc(sizeof(struct hash_table));
   item->value = -1;  
   item->key = -1;
  for(i=1;i<=10;i++)
  {
	printf ("Enter value in %d index",i);
	scanf("%d",&n);
	insert(i, n);
  }
	
   // To display the key and value pairs contain in hash table
   show();

   printf("Enter a key to search a respective value=");
   scanf("%d",&m);
   item = search(m);

   if(item != 0) {
      printf("Element found: %d\n", item->value);
   } else {
      printf("Element not found\n");
   }

}