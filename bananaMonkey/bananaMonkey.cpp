// bananaMonkey.cpp : Defines the entry point for the console application.
//

#include <climits>
#include <iostream>
using namespace std;

class Position{
public:
	int row, col;

};

bool isValid(int **grid,int row, int col, int n, int m, bool **visited)
{
	return row > -1 && row <n && col>-1 && col < m && !visited[row][col];
}

void printVisited(bool **visisted,int n, int m)
{
	for (int row = 0; row < n; row++)
	{
		cout << "\n";
		for (int col = 0; col < m; col++)
		{
			cout << " " << visisted[row][col];
		}
	}

}

void getAns(int **grid, int row, int col, int n, int m, bool **visited, int acc, int &min)
{

		int deltaRow[]{-1, -1, -1};
		int deltaCol[]{-1, 0, 1};
		bool move= false;
		int deltalen = sizeof(deltaCol) / sizeof(deltaCol[0]);
	
		visited[row][col] = true;

		if(acc>min)
			return;

		acc += grid[row][col];
		for (int delta = 0; delta < deltalen; delta++)
		{
			int nextRow = row + deltaRow[delta];
			int nextCol = col + deltaCol[delta];
			if (isValid(grid, nextRow, nextCol, n, m, visited)){
				move= true;

				getAns(grid,nextRow, nextCol,  n, m, visited, acc, min);
			
				visited[nextRow][nextCol] = false;

			}
		}
		if(!move){

			if(acc < min)
				min = acc;

		}
			
}

int main()
{

	freopen("input.txt", "r", stdin);

	int t,acc=0;
	cin >> t;
	int n, m, k, val;
	for (int tc = 1; tc <= t; tc++)
	{
		int min=INT_MAX;

		cin >> n;
		cin >> m;
		cin >> k;
		int **grid = new int *[n];
		
		bool **visited = new bool*[n];
		for (int row = 0; row < n; row++)
		{
			visited[row] = new bool[m];
			for (int col = 0; col < m; col++)
			{
				visited[row][col] = false;
			}
		}
		Position pos;
		pos.row = n-1;
		pos.col = k - 1;
	//	cout << "\n start pos " << pos.row << ", " << pos.col << endl;
		for (int row = 0; row < n; row++)
		{
			grid[row] = new int[n];

			for (int col = 0; col < m; col++)
			{
				cin >> val;
				grid[row][col] = val;
	//			cout << " " << grid[row][col];
			}
//			cout << endl;
		}

			getAns(grid, pos.row, pos.col, n, m, visited, acc, min);
					
		cout << "#" << tc << ":"<<min<<endl;
	}

	return 0;
}

