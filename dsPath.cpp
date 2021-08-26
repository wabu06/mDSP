#include<exception> 
#include<string>

#include "graph.h"


int main(int argc, char** argv)
{
	graph G1(100, 0.579, 33), G2(50, 0.72, 10), G3(50, 0.94, 10);
	graph G4(35, 0.64, 18), G5(187), OG;
	graph G6( vector<int>{1,2,3,4,5,6,7,8,9} );
	
	cout << "Neighbors of G2, G3, & G4:" << endl;
	
	for(auto& E: G2.getNeighbors(6) )
		cout << E << "\t";
	
	cout << endl;
	
	for(auto& E: G3.getNeighbors(7) )
		cout << E << "\t";
	
	cout << endl;
	
	for(auto& E: G4.getNeighbors(9) )
		cout << E << "\t";
	
	cout << endl;
	
	cout << "G4 Edge Value: " << G4.getEdgeValue(10, 22) << endl;
	
	cout << "Vertex count in G4: " << G4.getVertexCount() << endl;
	
	cout << "G3 Edge Value: "<< G3.getEdgeValue(10, 22) << endl;
	
	cout << "Vertex count in G3: " << G3.getVertexCount() << endl;
	
	cout << "G2 Edge Value: " << G2.getEdgeValue(10, 22) << endl;
	
	cout << "G2 edge count: " << G2.getEdges() << endl;
	
	cout << "G1 adjacent: " << G1.isAdjacent(12, 45);
	cout << "\t" << G1.isAdjacent(45, 12) << endl;
	
	cout << "G3  node <1> Average Path Length: " << G3.avePathLength(1) << endl;
	
	G6.addEdge(1, 2, 8);
	
	cout << G6.getEdgeValue(1, 2) << "\t" << G6.getEdgeValue(2, 1) << endl;
	
	cout << G6.getVertexCount() << endl;
	
	return 0;
} 