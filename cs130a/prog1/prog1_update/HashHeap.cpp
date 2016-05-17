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
   
   if(temp == -99999)
   {
      cout << "error" << endl;
      return;
   }
      
   cout << temp << endl;

}
void HashHeap::delete_val(int i)
{
   
   if(hash_table.delete_val(i))
   {
      heap_tree.delete_val(i);
      
      // cout << __FILE__ << " " << __LINE__ << endl;
//       cout << "Print hash_table after delete: " << endl;
//
//       hash_table.print_table();
//
//       cout << "Print heap_tree after delete: " << endl;
//
//       heap_tree.print_list();
      
      
   }
   else
   {
      
      cout << "error : item not present" << endl; 
      
      // cout << __FILE__ << " " << __LINE__ << endl;
//       cout << i << " isn't present" << endl;
   }
   
}
void HashHeap::print()
{
   // for(int i = 0; i < heap_tree.size(); ++i)
//    {
//       int temp = heap_tree.delete_min();
//
//       hash_table.delete_val(temp);
//
//       cout << temp << " ";
//
//    }
//
//    cout << endl;
   
   int temp = heap_tree.delete_min();
   hash_table.delete_val(temp);
   
   while(temp != -99999)
   {
      cout << temp << " ";
      
      temp = heap_tree.delete_min();
      hash_table.delete_val(temp);
      
   }

   cout << endl;
   
}