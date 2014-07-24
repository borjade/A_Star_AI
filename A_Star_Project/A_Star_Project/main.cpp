#pragma once
#include <iostream>
#include "A_Star.h"

using namespace std;
int main ()
	{
		A_Star a;
		int i =0;
		char t; 
		int o = 0;
		a.PrintMap();

		cout << "==========Type 1 to place city, 2 to change cell type=======\n";

		while(true)
			{
				cin >> o;
				if(o == 1){
					cout << "\nWhere is the city going to be (enter cell ID from 0- 90):\n";
					cin >> i;
					a.path_planning(i);
					cout << "\nCompleted!\n";
					}
				else if(o == 2)
					{
						cout << "\nWhich cell to terraform? (0 - 90):\n";
						cin >> i;
						cout << "\n To what? (P,F,D,W):\n";
						cin >> t;
						a.setCell(i,t);
						cout <<"\nDone!\n";
						system("cls");
						a.PrintMap();
					}
			}
	}