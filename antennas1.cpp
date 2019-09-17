// antennas1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;
bool isValid( int row, int col,int N, int M){
	return row > -1 && row <N && col >-1 && col < M;

}
void print_grid(int ** grid, int N, int M){

	for (int row = 0; row < N; row++){

		cout << "\n";
		for (int col = 0; col < M; col++){

			cout << " "<<grid[row][col];

		}
	}
	cout << endl;

}
bool isAntenna(int **grid, int row, int col){

	return grid[row][col] == 2 || grid[row][col] == 3 || grid[row][col] == 4;
}
int removeDuplicateHouses(int antennas){
	if (antennas == 2)
		return 1;
	if (antennas == 3)
		return 2;
	if (antennas == 4)
		return 3;

	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{

	freopen("inputAnte.txt", "r", stdin);
	int test_case = 0;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++){

		cout << " test case " << tc;
		cout << endl;
		int N = 0, M = 0, num=0;
		cin >> N;
		cin >> M;

		int ** grid = new int *[N];

		for (int i = 0; i < N; i++)
			grid[i] = new int[M];

		for (int row = 0; row < N; row++)
			for (int col = 0; col < M; col++){
				cin >> num;
				grid[row][col] = num;
			}

		print_grid(grid, N, M);

		int deltaRow[] = {1,0,0,-1};
		int deltaCol[] = {0,1,-1,0};
		int answer = 0, row=0, col=0, houses=0,
			deltaSize = sizeof(deltaRow) / sizeof(deltaRow[0]),
			nextRow =0, nextCol=0,power=0, antenna=0, totalHouses=0,rt=0,ct=0;

		for (row = 0; row < N; row++)
			for (col = 0; col < M; col++){
				if (isAntenna(grid, row, col)){
					power = grid[row][col] -= 1;
					for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++){
						rt = 0;ct = 0;
						for (int j = 0; j < power; j++){
							rt += deltaRow[deltaIdx];
							ct += deltaCol[deltaIdx];
							nextRow = row + rt;
							nextCol = col + ct;
							if (isValid(nextRow, nextCol, N, M) && grid[nextRow][nextCol] == 1){
									houses++;
									antenna=0;
									for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++){
										nextRow = nextRow + deltaRow[deltaIdx];
										nextCol = nextCol + deltaCol[deltaIdx];
										if ( isValid(nextRow, nextCol, N, M) && isAntenna(grid, nextRow, nextCol) )
												antenna++;
									}
									houses -= removeDuplicateHouses(antenna);
							}
						}
					} // deltas
				} else if (grid[row][col] == 1)
					totalHouses++;
			}
		answer = totalHouses - houses;
		cout << "#" << tc << ":" << answer;
		cout << endl;
		
	}
	return 0;
}

