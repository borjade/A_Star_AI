#pragma once
#include <algorithm> 
#include <iostream>
#define GRID_SIZE 11;

using namespace std;
template <class T>
class Grid
	{
	public:
		Grid(void)
		{		
		
		N = 5; //N will be the radius of our hexagon
				//initialise it all to null.
				for(int z = 0; z < 11; z++)
					{
					for(int x = 0; x < 11; x++)
						{
							hex_grid[z][x] = NULL;
						}
					}
		
		};

		~Grid(void)
			{
			
			};

		inline T getCell(int r, int q) 
			{
				return hex_grid[r+N][q + N];
			};

		inline void fillCell(T content, int r, int q)
			{
				hex_grid[r+N][q + N] = content;
			};

		//Given one set of co-ords, get distance to second set of co-oordinates
		inline int getDistance(int q1, int r1, int q2, int r2)
			{
				return (abs(q1-q2) + abs(r1-r2) + abs(q1+r1 - q2 - r2))/2;
			};

		void Print()
			{
				for(int r = -5; r < 6; r++)
					{
					for(int q = -5; q < 6; q++)
						{
							if(hex_grid[r+N][q + N] != NULL)
								{
									
									cout << *hex_grid[r+N][q + N];
								}
							else
								{
									cout << "* ";
								}
						}
						cout << "\n";
					}
			}

	protected:
		T hex_grid[11][11];
		int N;
	};

