CXX = g++
# CXX = clang++ # has better error messages

CFLAGS = -c -Wall 


all: prog1  
	

prog1: main.o HashHeap.o Hash.o Heap.o 
	$(CXX) $^ -o $@
	
	
main.o: main.cpp 
	$(CXX) $(CFLAGS) main.cpp 
	
HashHeap.o: HashHeap.cpp 
	$(CXX) $(CFLAGS) HashHeap.cpp
	
Heap.o: Heap.cpp
	$(CXX) $(CFLAGS) Heap.cpp  
	
Hash.o: Hash.cpp 
	$(CXX) $(CFLAGS) Hash.cpp 
	
	
clean:
	rm *o prog1