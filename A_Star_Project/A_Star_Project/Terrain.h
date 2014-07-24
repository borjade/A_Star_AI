#pragma once
#include <iostream>
using namespace std;
/*
* Terrain Nodes class: quite simply hold the necessary data about a cell in terms of it's terrain.
*/
class Terrain
	{
	public:
		Terrain(void);
		Terrain(char type, int positionZ, int positionX, int ID);
		~Terrain(void);

		void setType(char type){
			t = type;
			switch(t)
			{
			case 'W':
				terrainCost = 9;
				traversible = false;
				break;
			case 'P':
				terrainCost = 1;
				traversible = true;
				break;
			case 'D':
				terrainCost = 2;
				traversible = true;
				break;
			case 'F':
				terrainCost = 4;
				traversible = true;
				break;
			case 'X':
				terrainCost = 9;
				traversible = true;
			}
			}
		char getType(){return t;}

		bool getTraversible(){return traversible;}

		int getCost(){return terrainCost;}
		int getID(){return i;}

	protected:
		int z;
		int x;
		char t; 
		bool traversible;
		int terrainCost;
		int i;
	};
ostream& operator << (ostream& outStream, Terrain out);
