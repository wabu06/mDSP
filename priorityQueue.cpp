#include "priorityQueue.h"

void PQswap(nodePath& x, nodePath& y)
{
    nodePath temp = x;
    x = y;
    y = temp;
}

	// make subtree with root at given index priority queue compliant
void priorityQueue::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	
	if (l < size && pqArray[l].edgeCountTotal < pqArray[i].edgeCountTotal)
    	smallest = l;

	if (r < size && pqArray[r].edgeCountTotal < pqArray[smallest].edgeCountTotal)
    	smallest = r;

	if (smallest != i)
	{
    	PQswap(pqArray[i], pqArray[smallest]);
    	heapify(smallest);
	}
}

	// removes the top element of the queue
nodePath priorityQueue::getMin()
{
	if (size <= 0)
    	return nodePath(0, vector<int>{-1});

	nodePath root;

	if (size == 1)
	{
    	size--;
		
		root = pqArray[0];
		pqArray.pop_back();
		
    	return root;
	}
	
	root = pqArray[0];
	
	pqArray[0] = pqArray[size-1];
	
	size--;
	
	heapify(0);
	
	pqArray.pop_back();
	
	return root;
}


	// does the queue contain the value queue element "QE"
	// if so return the index, if not return -1
int priorityQueue::contains(int EC)
{
	for(int i = 0; i < size; i++)
	{
		if (pqArray[i].edgeCountTotal == EC)
			return i;
	}
	
	return -1;
}


	// insert queue element "OE" into queue
void priorityQueue::insert(nodePath QE)
{
	size++;
	int i = size - 1;
	
	pqArray.push_back(QE);
	
		// make priority queue compliant
    while (i != 0 && pqArray[parent(i)].edgeCountTotal > pqArray[i].edgeCountTotal)
    {
       PQswap(pqArray[i], pqArray[parent(i)]);
       i = parent(i);
    }
}

vector<nodePath> priorityQueue::getQueContents()
{
	vector<nodePath> elements;
	
	for(auto& E: pqArray)
		elements.push_back(E);
	
	return elements;
}
