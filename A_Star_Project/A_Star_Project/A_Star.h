#pragma once
#include "Node.h"
#include "Grid.h"
#include "Terrain.h"
#include <fstream>
#include <queue>
#include <vector>
#include <iostream>
#define cost 5;

struct Compare {
    bool operator()(Node* const & p1, Node* const & p2) {
        // return "true" if "p1" is ordered before "p2", for example:
		if(p1->getF() == p2->getF())
			{
				return p1->getH()> p2->getH();
			}
        return p1->getF() > p2->getF();
    }
};

struct position
	{
		int z;
		int x;
	};

using namespace std;
class A_Star
	{
	public:
		A_Star(void);
	   ~A_Star(void);

		void path_planning(int i);

		void LoadFile(const string& filename);

		void PrintMap();

		bool checkOpenList(priority_queue<Node*, vector<Node*>, Compare> open_list, Node* Q);
		
		void PopNeighbours();

		void setCell(int i,char t){terrain_type_map.getCell(byID[i].x,byID[i].z)->setType(t);}

	protected:
		Grid<Node*> node_map;
		Grid<Terrain*> terrain_type_map;
		Node shipLocation;

		int shipX;
		int shipZ;


		position byID[90];
		char types[121];
	};

