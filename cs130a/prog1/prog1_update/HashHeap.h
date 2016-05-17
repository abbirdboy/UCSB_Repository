#ifndef __HASH_HEAP__
#define __HASH_HEAP__

#include "Hash.h"
#include "Heap.h"

class HashHeap
{



   public:
      HashHeap();
      ~HashHeap();
      
      void insert(int);
      void lookup(int);
      void delete_min();
      void delete_val(int);
      void print();
   
   private:
      Hash hash_table;
      Heap heap_tree; 


};


#endif