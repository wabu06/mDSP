#include "shortestPath.h"



nodePath dsPath::getNodePath( int sN, int dN)
{
	if( !( spGraph.nodeFound(sN) && spGraph.nodeFound(dN) ) )
		return nodePath(0, vector<int>{-1});
	
	if (sN == dN)
		return nodePath(0, vector<int>{dN});
	
		// initialize open and closed sets, to empty
	openSet.emptyPQ();
	closedSet.clear();
	
		//initialize nodes visited tracker
	nodesVisited.clear();
		
	openSet.insert( nodePath(0, vector<int>{sN}) );
	
	nodePath np = openSet.getMin();
		
	closedSet.push_back(np);
	
	int cn, ev, tempEV;
	
	vector<int> tempNP;
	
	nodePath LP; // last path added to closed set
	
	do {
		cn = np.nodeList.back(); // current node to be examined
		
		for(auto& N: spGraph.getNeighbors( cn ) )
		{
			if (cn == N)
				continue;
			
			tempEV = np.edgeCountTotal;
			tempNP = np.nodeList;
		
			ev = spGraph.getEdgeValue(cn, N);
			
			//cout << ev << endl;
			
			tempEV += ev;
			
			tempNP.push_back(N);
			
				// add new path to open set if the node is leads to isn't
				// already ready visited, if it's already been visited, add it
				// only if it's better path than one already checked/found
			if (nodesVisited[N] == 0)
			{
				openSet.insert( nodePath(tempEV, tempNP) );
				nodesVisited[N] = tempEV;
			}
			else
			{
				if (tempEV < nodesVisited[N])
				{
					openSet.insert( nodePath(tempEV, tempNP) );
					nodesVisited[N] = tempEV;
				}
			}

			//openSet.insert( nodePath(tempEV, tempNP) );
		}
		
		np = openSet.getMin(); // get shortest path currently in open set
		
		//cout << "OS size:\t" << openSet.getSize() << endl;
		
		closedSet.push_back(np);

		LP = closedSet.back(); // get most recent path added to closed set
		
		//cout << "ECT:\t" << LP.edgeCountTotal << endl;
		
			// if final node in the most recent path added to closed set is 
			// "dN", the destination node, then shortest path has been found
		if ( LP.nodeList.back() == dN )
			return LP;
	
	} while( openSet.notEmpty() );
	
		// return empty path list if node "dN" is not reachable from node "sN"
	return nodePath(0, vector<int>{-1});
}
