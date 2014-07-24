#pragma once
#include "Grid.h"
class Node
	{
	public:
		Node(void);
		Node(int xPos, int zPos, Grid<Node*>* map, int newID);
		~Node(void);

		inline int getID(){return ID;};
		inline int getX(){return x;}
		inline int getZ(){return z;}

		int getF(){return f;}
		void setF(){f = g+h;}

		int getG(){return g;}
		void setG(int newG){g = newG;}

		int getH(){return h;}
		void setH(int newH){h = newH;}


		void setParent(Node* prev){parent_ = prev;}
		Node* getParent(){return parent_;}

		void fillNeighbours();
		Node* GetNeighbour(int i);

		bool operator<(const Node &other) const { return f < other.f;}
		bool operator <=(const Node &other) const { return f <= other.f;}
		bool operator >=(const Node &other) const { return f >= other.f;}
		bool operator>(const Node &other) const { return f>other.f;}
		bool operator!=(const Node &other) const { return ID != other.ID;}
		
		bool operator==(const Node &other) const { return ID == other.ID;}

	protected:
	//ID of the node
		int ID;
		int z; //axial coords
		int x;

		//values needed for the a*
		int f;
		int g;
		int h;

		Grid<Node*>* parentMap;

		//the neighbours IDs
		Node* neighbours[6];

		Node* parent_;
		//Node* next_;

	};

