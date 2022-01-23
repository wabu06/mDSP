#include<fstream>
#include "shortestPath.h"



int main(int argc, char** argv)
{
	graph G1(100, 0.579, 33), G2(500, 0.2, 50), G3(50, 0.4, 10);
	graph G4(35, 0.64, 18);
		
	cout << boolalpha;

	cout << "Neighbors of node 7 in graph G3:" << endl; int c{1};
	
	for(auto& N: G3.getNeighbors(7) )
	{
		if (c == 15)
			{ cout << N << "\n"; c = 1; }
		else
			{ cout << N << "\t"; ++c; }
	}
	
	cout << endl;
	
		// instance of dsPath class initialized with graph G3
	dsPath gSP(G3); 
	
	auto p7to29 = gSP.getPath(7, 29);
	
	cout << "\nG3 path 7->29:\t";
	
	for(auto& N: p7to29)
		cout << N << '\t';
		
	cout << "\nG3 7->29 distance: " << gSP.getPathSize(7, 29) << endl;
	
	cout << "\nEdge value between nodes 7 & 29 in graph G3:\t";
	
	cout << G3.getEdgeValue(7, 29) << '\t' << G3.getEdgeValue(29, 7) << endl;
	
	cout << "\ngraph G3 node <1> Average Path Length: " << G3.avePathLength(1);
	cout << endl;
	
	cout << "G3 7 & 29 color: " << G3.getEdgeColor(7, 29) << '\t';
	cout << G3.getEdgeColor(29, 7) <<endl;
	
	cout << "\n\n\nNeighbors of node 15 in graph G2:" << endl;

	for(auto& N: G2.getNeighbors(15) )
		cout << N << "\t";
	
	cout << endl;

	//graph G2(50, 0.2, 10);
	
		// instance of dsPath class initialized with graph G2
	gSP = dsPath(G2);
	
	auto p15to41 = gSP.getPath(15, 41);
	
	cout << "\nG2 path 15->41:\t";
	
	for(auto& N: p15to41)
		cout << N << '\t';
		
	cout << "\nG2 15->41 distance: " << gSP.getPathSize(15, 41) << endl;
	
	cout << "\nEdge value between nodes 15 & 41 in graph G2:\t";
	
	cout << G2.getEdgeValue(15, 41) << '\t' << G2.getEdgeValue(41, 15) << endl;
	
	cout << "\ngraph G2 node <1> Average Path Length: " << G2.avePathLength(1);
	cout << endl;
	
	ifstream fin("graph.dat"); // open file and connect it to a stream
	
	if ( fin.bad() )
	{
		cerr << "Error opening file!!" << endl;
		return 1;
	}
	
	int gsize; // node count
	
	fin >> gsize; // read in from the file the node count
	
	int v1, v2, w; // node pairs and their edge cost
	
	vectOfTuples edgeW; // vector to store the edges and their costs
	
		// read in from the file the edges and the cost associated with each
		// edge, and store that into a vector
	while( fin.good() )
	{
		fin >> v1 >> v2 >> w;
		
		edgeW.push_back( intTup{v1, v2, w} );
	}
	
	fin.close();

	gSP = dsPath{ graph(edgeW) }; gSP.setColor(eCLR::YLLW, false);
	
	auto p3to17 = gSP.getPath(3, 17);
	
	cout << "\ngraph from file path 3->17:\t";
	
	for(auto& N: p3to17)
		cout << N << '\t';
		
	cout << "\ngraph from file 3->17 distance: " << gSP.getPathSize(3, 17);
	cout << endl;
	
	//cout << "\nEdge value between nodes 3 & 17 in graph from file:\t";
	
	//cout << G2.getEdgeValue(3, 17) << '\t' << G2.getEdgeValue(17, 3) << endl;
	
	//cout << "\ngraph G2 node <1> Average Path Length: " << G2.avePathLength(1);
	//cout << endl;
	
	return 0;
}
