// ShorestPathTest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

void print(int ** grid, int N){

	for (int i = 0; i < N; i++){
		cout << "\n";
		for (int j = 0; j < N; j++){

			cout << " " << grid[i][j];
		}

	}
	cout << endl;

}

void print_bool(bool ** grid, int N){

	for (int i = 0; i < N; i++){
		cout << "\n";
		for (int j = 0; j < N; j++){

			cout << " " << grid[i][j];
		}

	}
	cout << endl;

}


struct Point{

	int x;
	int y;

};

struct queueNode{

	Point pt;
	int dist;

};

bool isValid(int row, int col, int N){

	return row > -1 && row < N && col >-1 && col < N;

}
int rowDelta []= {0, 1, 1, 1, 0, -1, -1, -1};
int colDelta []=  {1, 1, 0, -1, -1, -1, 0, 1};

int deltaSize = sizeof(rowDelta) / sizeof(rowDelta[0]);

int BFS(int **grid, Point src, Point dest , int N){
	//cout << " src " << grid[src.x][src.y] << "\n";
	if (grid[src.x][src.y] == 1 || grid[dest.x][dest.y] == 1){
		cout << "\n out here" << "\n";
		return -1;
	}
		
	
	bool ** visited = new bool*[N];
	for (int i = 0; i < N; i++)
		visited[i] = new bool[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;

	//print_bool(visited, N);

	//bool visited[N][N];
	//memset(visited, false, sizeof visited);

	visited[src.x][src.y] = true;

	// Create a queue for BFS 
	queue<queueNode> q;

	// Distance of source cell is 0 
	queueNode s = { src, 1 };
	q.push(s);  // Enqueue source cell 

	// Do a BFS starting from source cell 
	while (!q.empty())
	{
	
		queueNode curr = q.front();
		Point pt = curr.pt;

		// If we have reached the destination cell, 
		// we are done 
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// Otherwise dequeue the front cell in the queue 
		// and enqueue its adjacent cells 
		q.pop();

		for (int i = 0; i < deltaSize; i++)
		{
			
			int row = pt.x + rowDelta[i];
			int col = pt.y + colDelta[i];

			// if adjacent cell is valid, has path and 
			// not visited yet, enqueue it. 
			if (isValid(row, col,N) && grid[row][col]==0 && !visited[row][col]){
				//cout << "\n adjacent \n";
				// mark cell as visited and enqueue it 
				visited[row][col] = true;
				queueNode Adjcell = { { row, col },curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	return -1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case){

		cout << "\n test case " << test_case << "\n";
		int N = 0, num =0;

		cin >> N;

		cout << "\nN " << N << "\n";

#define ROW N
#define COL N
	
		int ** grid = new int *[N];

		for (int i = 0; i < N; i++)
			grid[i] = new int[N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				cin >> num;
				grid[i][j] = num;
			}

		print(grid, N);

		Point source = { 0, 0 };
		Point dest = { N-1, N-1 };

		int dist = BFS(grid, source, dest,N);

		if (dist != INT_MAX)
			cout << "Shortest Path is " << dist;
		else
			cout << "Shortest Path doesn't exist";

		cout << endl;


	}


	return 0;
}

