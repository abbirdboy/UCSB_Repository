#include "HashHeap.h"
#include <iostream>

using namespace std;

// constructor 
HashHeap::HashHeap()
{
   hash_table = Hash();
   heap_tree = Heap();
   
}
HashHeap::~HashHeap()
{
   
   
}


// public
void HashHeap::insert(int i)
{
   if(hash_table.insert(i))
   {
      heap_tree.insert(i);
   }
   else
   {
      cout << "error : item already exists" << endl;
   }
         
}
void HashHeap::lookup(int i)
{
   if(hash_table.lookup(i))
   {
      cout << i << endl;
      
   }
   else
   {
      
      cout << i << " not found" << endl;
      
   }
   
}
void HashHeap::delete_min()
{
   int temp = heap_tree.delete_min();
   
   hash_table.delete_val(temp);
   
   cout << temp << endl;

}
void HashHeap::delete_val(int i)
{
   
   if(hash_table.delete_val(i))
   {
      heap_tree.delete_val(i);
   }
   else
   {
      cout << "error : item not present" << endl;
      
   }
   
}
void HashHeap::print()
{
   for(int i = 0; i < heap_tree.size(); ++i)
   {
      int temp = heap_tree.delete_min();
      
      hash_table.delete_val(temp);
      
      cout << temp << " ";
      
   }
   
   cout << endl;
   
}