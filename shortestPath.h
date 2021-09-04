#ifndef DSPATH
#define DSPATH

#include<iostream>
#include<vector>
#include<tuple>
#include<map>

using namespace std;

#endif

#include "graph.h"
#include "priorityQueue.h"


class dsPath
{
	priorityQueue openSet;
	graph spGraph;
	vector<nodePath> closedSet;
	
		// color map to determine whether or not and edge is used in the
		// shortest path calculation
	map<eCLR, bool> cMap;
	
		// returns true if given node is in the closed set
	bool nodeInClosedSet(int n);
	
		// Dijkstra's Algorithm is implemented here
	nodePath getNodePath(int sN, int dN);
	
	public:
			// constructor takes a graph object as input, and appropriately
			// initializes the open and closed set, nodes visited tracker
		dsPath(graph G = graph(),
				priorityQueue OS = priorityQueue(),
				vector<nodePath> CS = vector<nodePath>(),
				map<eCLR, bool> M = map<eCLR, bool> { {eCLR::RED, true}, {eCLR::YLLW, true}, {eCLR::GRN, true} } ): 
									spGraph(G), openSet(OS), closedSet(CS),
									cMap(M) {}
					
		 	// find shortest path between from node u to node w and returns the
		 	// sequence of vertices representing shortest path between them
		vector<int> getPath(int u, int w)
			{ nodePath snP = getNodePath(u, w); return snP.nodeList; }
		
			// returns the path cost associated with the shortest path between
			// nodes u and w 
		int getPathSize(int u, int w)
			{ nodePath snP = getNodePath(u, w); return snP.ect; }
		
		void setColor(eCLR C, bool B) { cMap[C] = B; }
		bool getColor(eCLR C) { return cMap[C]; }
};
