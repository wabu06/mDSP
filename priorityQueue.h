#ifndef DSPATH
#define DSPATH

#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

#endif

	// used to represent list of nodes, corresponding to a particular path
	// and the total edge cost of that path
class nodePath
{
	public:
		int edgeCountTotal;
		vector<int> nodeList;
		
		nodePath(int T = 0, vector<int> NL = vector<int>()):
					edgeCountTotal(T), nodeList(NL) {}
};

class priorityQueue
{
	vector<nodePath> pqArray;
	int size;
	
		// make subtree with root at given index priority queue compliant
	void heapify(int);
	
		// get parent node index of node at index i
	int parent(int i) { return (i-1)/2; }
	
		// get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    	// get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
	
	public:
		priorityQueue(int S = 0) { size = S; pqArray = vector<nodePath>(size); }
	
			// removes the top element of the queue
		nodePath getMin(); 

			// does the queue contain the value queue element "QE"
			// if so return the index, if not return -1
		int contains(int EC);
		
			// insert queue element "OE" into queue
		void insert(nodePath QE);
		
			// returns the top element of the queue.
		nodePath top() { return pqArray[0]; }
		
			// returns the number of queue elements
		int getSize() { return size; } 
		
		vector<nodePath> getQueContents();
		
		bool isEmpty() { return size == 0 ? true: false; }
		
		bool notEmpty() { return size > 0 ? true: false; }
		
			// emtpy out the Priority Queue
		void emptyPQ()
		{
			pqArray.clear();
			size = 0;
		}
};
