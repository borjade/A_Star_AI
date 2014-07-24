#include "Terrain.h"

Terrain::Terrain(void)
	{
		z = 0;
		x = 0;
		t = 'W';
		terrainCost = 9999999;
		traversible = false;
	};

Terrain::Terrain(char type, int positionZ, int positionX, int ID)
	{	
		z = positionZ;
		x = positionX;
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
			i = ID;
	}


Terrain::~Terrain(void)
	{
	}


ostream& operator <<(ostream& outStream, Terrain out)
	{
		outStream <<" " <<out.getType() << "("<<out.getID()<<") ";
		return outStream;
	}