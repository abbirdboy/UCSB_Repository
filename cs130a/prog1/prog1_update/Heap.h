#ifndef __HEAP__
#define __HEAP__
#include <vector>

/* MIN_HEAP IMPLEMENTATION */

using namespace std;

class Heap
{

   public:
      Heap();
      ~Heap();
      bool insert(int);
      bool delete_val(int);
      
      int delete_min();
      
      void print_tree(int node=1, int indent=0);
      void print_list();
      int size();
   
   private:
      int parent(int);
      int left_child(int);
      int right_child(int);
      int minimum_child_index(int);
      
      void percolate_up(int);
      void percolate_down(int);
      
      
      vector<int> min_heap;

};


#endif