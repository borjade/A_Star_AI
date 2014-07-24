#include "Node.h"
/*
* This is the node class, Nodes are the objects that are used to calculate the path planning
* Terrain data is isolated from nodes in their own class.
* Nodes contains a pointer to the map it's sitting on.
*
*/

Node::Node(void)
	{
		
	}

Node::Node(int xPos, int zPos, Grid<Node*>* map, int newID)
	{
		ID = newID;
		x = xPos;
		z = zPos;
		parentMap = map;

		parent_ = NULL;

	
	}


Node::~Node(void)
	{
//		delete [] neighbours;
//		delete parentMap;
	}

void Node::fillNeighbours()
	{
		neighbours[0] = parentMap->getCell(x,z-1);
		neighbours[1] = parentMap->getCell(x+1,z-1);
		neighbours[2] = parentMap->getCell(x-1,z);
		neighbours[3] = parentMap->getCell(x+1,z);
		neighbours[4] = parentMap->getCell(x-1,z+1);
		neighbours[5] = parentMap->getCell(x,z+1);
	}

Node* Node::GetNeighbour(int i)
	{
		return neighbours[i];
	}