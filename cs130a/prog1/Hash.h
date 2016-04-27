#ifndef __HASH__
#define __HASH__ 

#include <stddef.h>

struct Node {

   Node(int d) : data(d), next(NULL) {};
   Node(int d, Node *n): data(d), next(n) {};
   
   int data; 
   Node *next; 

};


class Hash
{


   public:
   
      Hash();
      ~Hash();
      bool insert(int);
      bool lookup(int);
      bool delete_val(int);
      void print_table();
   
   private:
      
      int hash_func(int);
      
      Node **table;


};
#endif 