#include "A_Star.h"



A_Star::A_Star(void)
	{
		LoadFile("hexTypess.txt"); //file with the hexes (I tried to make it like the example on the assignment, but this was done manually, so it might be abit different!)
		int i = 0;
		int offset = 5;

		Node* temp;
		int start= 0;
		//Ugly way to set it all up, but we set the first half of our hexagon
		for(int z = -5; z  < 1; z++)
		{
			for(int x = start; x < 6; x++)
				{
					temp = new Node(z,x,&node_map,i);
					if(types[i] == 'X'){
						shipZ = temp->getZ(); shipX = temp->getX(); // this is our ship!
						}
					byID[i].x = temp->getX();
					byID[i].z = temp->getZ();
					terrain_type_map.fillCell(new Terrain(types[i],z,x,i),z,x);
					node_map.fillCell(temp,z,x);
					i++;
				}
			start--;
		}
		//then the second half
		int guard = 5;
		for(int z = 1; z < 6; z++)
			{
				for(int x = -5; x < guard;x++)
					{
						temp = new Node(z,x,&node_map,i);
						byID[i].x = temp->getX();
						byID[i].z = temp->getZ();
						terrain_type_map.fillCell(new Terrain(types[i],z,x,i),z,x);
						node_map.fillCell(temp,z,x);
						i++;
					}
				guard--;
			}
		//fill the neighbours for all our cells
		for(int j = 0; j <90; j++)
			{
				node_map.getCell(byID[j].x,byID[j].z)->fillNeighbours();
			}
	}

//Function to check whether our cell is already in the OL
bool A_Star::checkOpenList(priority_queue<Node*,vector<Node*>,Compare> open_list, Node* Q)
	{
	priority_queue<Node*,vector<Node*>,Compare>  temp = open_list;
	while (!temp.empty()){
		if(*temp.top() == *Q) 
			{
				return true;
			}
			temp.pop();
		}
	return false;
	}

void A_Star::path_planning(int n)
	{
	if( terrain_type_map.getCell(byID[n].x,byID[n].z)->getType() == 'W'){ cout << "Cant place city on water!";} // first lets make sure we are placing the city on land
	else{
		Node* goal = (node_map.getCell(byID[n].x,byID[n].z)); // this is where we want to go

		Node* start = (node_map.getCell(shipX,shipZ)); // this is the enemy ship!

		//our lists!

		priority_queue<Node*,vector<Node*>,Compare> open_list; 
		vector<Node*> closedList;
		
		//set the start f,g & h!
		start->setH(node_map.getDistance(shipX,shipZ,goal->getX(),goal->getZ()));
		start->setG(terrain_type_map.getCell(shipX,shipZ)->getCost());
		start->setF();
		
		//put our start cell in ol
		open_list.push(start);

		//P is the cell with lowest F, right now, just the initial
		Node * P = open_list.top();
		P->fillNeighbours();
		Node * Q;
		while(*P != *goal) //While we haven't reached our goal
			{
				if(open_list.empty()) // if lis tis empty, we can't get there!
					{
						cout << "\nNO PATH!\n";
						break;
					}
				for(int i =0; i<6; i++) //for all the neighbours...
					{
						Q = P->GetNeighbour(i);
						if(!(Q == NULL)) { //if it's empty, skip it (so not the edges)
							if(terrain_type_map.getCell(Q->getX(),Q->getZ())->getTraversible() == true)  //if we have a traversible cell
							{
							//calculate f g h
							int h = node_map.getDistance(Q->getX(),Q->getZ(),goal->getX(),goal->getZ()) * terrain_type_map.getCell(Q->getX(),Q->getZ())->getCost();
							int g = terrain_type_map.getCell(Q->getX(),Q->getZ())->getCost();
							int f = g + h;

							//check we are in open list
							if(checkOpenList(open_list,Q) == true)
								{
									if(f<P->getF())
										{
											Q->setParent(P);
											Q->setH(h);
											Q->setG(g);
											Q->setF();
										}
								}
							else // or ad it.
								{
									Q->setH(h);
									Q->setG(g);
									Q->setF();
									open_list.push(Q);
									Q->setParent(P);
								}
							}
						}
					}
				closedList.push_back(P); // add p to the closed list
				P = open_list.top(); // set P as the lowest f in OL

				
			}

		//Simply trace back through the path and print the final cost out
		Node* next = goal;
	   int finalCost = next->getF();
	   cout << "Path: ";
		while (*next != *start)
			{
				cout << next->getID() << " <- ";
				finalCost += next->getF();
				next = next->getParent();
			}
		cout << start->getID();
		cout << " Cost: " << finalCost;
		}
	}

A_Star::~A_Star(void)
	{

	}

//Helper function : file loader
void A_Star::LoadFile(const string &filename) {
	ifstream f(filename);

	if(!f) {
		
	}

	for(int i = 0; i<121; i++)
		{
			f >> types[i];
		}
	f.close();
}

//print our map!
void A_Star::PrintMap()
	{
		terrain_type_map.Print();
	}

