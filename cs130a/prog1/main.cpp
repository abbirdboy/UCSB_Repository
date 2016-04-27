#include <iostream>

#include "HashHeap.h"
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std; 



int main()
{
   string s;
   string b;
   int temp;
   
   HashHeap ts = HashHeap();
   
   while(cin >> s)
   {
      if(s == "insert")
      {
         cin >> b;
         temp = atoi(b.c_str());
         
         ts.insert(temp);
         
      }
      else if(s == "delete")
      {
         cin >> b;
         temp = atoi(b.c_str());
         ts.delete_val(temp);
         
      }
      else if(s == "deleteMin")
      {
         ts.delete_min();
         
      }
      else if(s == "lookup")
      {
         cin >> b;
         temp = atoi(b.c_str());
         ts.lookup(temp);
         
      }
      else if(s == "print")
      {
         
         ts.print();
         
      }
      
   }

   return 0; 
}