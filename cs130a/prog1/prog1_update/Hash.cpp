#include "Hash.h"
#include <iostream>
#include <stddef.h>

using namespace std;

const int TABLE_SIZE = 101;

// constructors 
Hash::Hash()
{
   table = new Node*[TABLE_SIZE];
   
   for(int i = 0; i < TABLE_SIZE; ++i) 
      table[i] = NULL;
   
}

Hash::~Hash()
{
   // for(int i = 0; i < TABLE_SIZE; ++i)
//    {
//       if(table[i] != NULL)
//       {
//          for(Node *p = table[i]; p != NULL; p = p->next)
//          {
//             delete p;
//          }
//       }
//
//    }
//
   // delete[] table;
   
}


// public 

bool Hash::insert(int i)
{
   if(table[hash_func(i)] != NULL) // chaining 
   {
      
      for(Node *p = table[hash_func(i)]; p != NULL; p = p->next)
      {
         
         if(p->data == i) // returns if already there
         {            
            return false;  
         }
         else if(p->next == NULL)
         {
            
            p->next = new Node(i);
            
            return true;
            
         }
            
         
      }
        
   }
   else 
   {
      
      table[hash_func(i)] = new Node(i);
      
      return true;
      
   }
   
   return false;
}

bool Hash::lookup(int i)
{
   if(table[hash_func(i)] == NULL)
      return false;
   
   for(Node *p = table[hash_func(i)]; p != NULL; p = p->next)
      if(p->data == i)
         return true;
   
   
   return false;
   
}

bool Hash::delete_val(int i)
{
   Node *p = table[hash_func(i)]; 
   
   
   if(p == NULL)
   {
      
      return false;
      
   }
   else if(p->next == NULL && p->data == i)
   {
       
      delete p; 
      
      table[hash_func(i)] = NULL;
      
      return true;
   }
   else if(p->data == i && p->next != NULL)
   {
      
      p = p->next; 
      
      return true;
   }
   else // deletes from inside chain
   {
      
      // cout << "third if being called" << endl;
      
      Node *j = p;
      
      p = p->next; 
      
      while(p != NULL) // staggered loop 
      {
                  
         if(p->data == i)
         {
            j->next = p->next;
      
            delete p;
            
            return true;   
            
         }
           
         j = j->next;
         
         p = p->next;
         
      }
      
      
      
   }
   
   
   return false;
   
}


// private
int Hash::hash_func(int i)
{
   
   return i % TABLE_SIZE;
   
}

void Hash::print_table()
{
   for(int i = 0; i < TABLE_SIZE; i++)
      if(table[i] != NULL)
         for(Node *p = table[i]; p != NULL; p = p->next)
            cout << "data: " << p->data << " at position " << i << endl;
      
}


