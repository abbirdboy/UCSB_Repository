#include "Heap.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

// constructors
Heap::Heap() { min_heap.resize(1, 0); }
Heap::~Heap() { }

// public
bool Heap::insert(int k)
{
   
   min_heap.push_back(k);

   percolate_up(min_heap.size()-1); // index of last element

   return true;  
          
}

bool Heap::delete_val(int k)
{
   if(min_heap.size() == 1)
      return -99999;
   
   int i = find(min_heap.begin(), min_heap.end(), k) - min_heap.begin();
   
   if((unsigned)i >= min_heap.size()) // checks bounds: not found
      return false;
   
   min_heap[i] = min_heap[min_heap.size()-1];
   
   min_heap.pop_back();
   
   percolate_up(i);
   percolate_down(i);
   
   return true;
   
}

int Heap::delete_min()
{
   if(min_heap.size() == 1)
      return -99999;
   
   int temp = min_heap[1];
   
   min_heap[1] = min_heap[min_heap.size()-1];
   
   min_heap.pop_back();
   
   // print_list(); // remove later
   
   percolate_down(1);
   
   return temp;
}

void Heap::print_tree(int node, int indent)
{  
   if((unsigned)node < min_heap.size())
   {
      print_tree(left_child(node), indent+4);
      print_tree(right_child(node), indent+4);
      if(indent)
      {
         cout << std::setw(indent) << ' ';
         
      }
      cout << min_heap[node] << "\n";
      
   }
   // if(p != NULL) {
//            if(p->left) postorder(p->left, indent+4);
//            if(p->right) postorder(p->right, indent+4);
//            if (indent) {
//                std::cout << std::setw(indent) << ' ';
//            }
//            cout<< p->data << "\n ";
//        }
}

void Heap::print_list()
{
   
   cout << "Printing List: " << endl;
   for(unsigned int i = 0; i < min_heap.size(); i++)
      cout << "Index: " << i << " Value: " << min_heap[i] << endl;

}

// private
void Heap::percolate_up(int i)
{
   
   if(i < 2) // stop at root
   {
      return;
   }
   else if(min_heap[parent(i)] < min_heap[i]) // parent less than child
   { 
      return;
   }
   else if(min_heap[parent(i)] > min_heap[i]) // swap if parent is greater than child
   {
      swap(min_heap[parent(i)], min_heap[i]);
   
      percolate_up(parent(i));
      
   }  
  
}
void Heap::percolate_down(int i)
{
   if((unsigned)i >= min_heap.size())
   {
      return;
   }
   else if((unsigned)left_child(i) > min_heap.size()-1 && (unsigned)right_child(i) > min_heap.size()-1)
   {
      return;
   }
   else if(min_heap[i] > min_heap[minimum_child_index(i)])
   {
      
      int minimum_child = minimum_child_index(i);
      // cout << "Swapping :" << i << " and " << minimum_child_index(i) << endl;
      swap(min_heap[i], min_heap[minimum_child]);
      
      // print_list(); // remove later
      
      percolate_down(minimum_child);
      
      
   }
   else
   {
      return;
   }
   
   
}

int Heap::minimum_child_index(int i)
{
   unsigned int left = left_child(i);
   unsigned int right = right_child(i);
   
   
   if(left > min_heap.size()-1)
   {
      
      return right;
      
   }
   else if(right > min_heap.size()-1)
   {
      
      return left;
      
   }
   else if(min_heap[left] < min_heap[right])
   {
      return left;
   }
   else
   {
      return right;
   }
   
}

int Heap::size()
{
   return min_heap.size();
   
}

int Heap::parent(int i) { return (i/2); } // index to parent
int Heap::left_child(int i) { return (2*i); } // index to left child
int Heap::right_child(int i) { return ((2*i) + 1); } // index to right child




