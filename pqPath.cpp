#include<exception> 
#include<string>
#include <array>

#include "priorityQueue.h"


int main(int argc, char** argv)
{
	priorityQueue pq1;
	
	//int nums[] = {8, 9, 5, 3, 1, 6};
	
	array<int,6> nums{8, 9, 5, 3, 1, 6};
	
	for(auto& n: nums)
		pq1.insert( nodePath(n) );
			
	cout << "root: " << pq1.top().edgeCountTotal << "\tsize: " << pq1.getSize() << endl;
	
	for( auto& E: pq1.QueContents() )
		cout << E.edgeCountTotal << "\t";
	
	cout << endl;
	
	cout << "has 10: " << pq1.contains(10) << "\thas 3: " << pq1.contains(3);
	cout << endl;
	
	cout << "removed: " << pq1.getMin().edgeCountTotal << endl;
	
	for( auto& E: pq1.QueContents() )
		cout << E.edgeCountTotal << "\t";
	
	cout << endl;
	
	cout << "isEmpty: " << pq1.isEmpty() << "\tnotEmpty: " << pq1.notEmpty();
	
	cout << endl;
	
	/* pq1.chgPriority(2, 12);
	
	for( auto& E: pq1.getQueContents() )
		cout << E << "\t";
	
	cout << endl; */
	
	return 0;
} 