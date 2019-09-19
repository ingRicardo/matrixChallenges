// testLinks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Point{

	int x;
	int y;

};

struct queueNode{

	Point pt;
	int dist;

};

struct node
{
	int data;
	node *next;
};


struct Qnode
{
	queueNode data;
	Qnode *next;
};


class linked_list
{
private:
	node *head, *tail;
private:
	Qnode *Qhead, *Qtail;

public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
		Qhead = NULL;
		Qtail = NULL;
	}

	void push(queueNode n)
	{
		Qnode *tmp = new Qnode;
		tmp->data = n;
		tmp->next = NULL;

		if (Qhead == NULL)
		{
			Qhead = tmp;
			Qtail = tmp;
		}
		else
		{
			Qtail->next = tmp;
			Qtail = Qtail->next;
		}
	}


	void add_node(int n)
	{
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}


	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << "data " << temp->data << "\n";
			temp = temp->next;
		}
	}

	void Qdisplay()
	{
		Qnode *temp = new Qnode;
		temp = Qhead;
		while (temp != NULL)
		{

			cout << "data X " << temp->data.pt.x << "\n";
			cout << "data Y " << temp->data.pt.y << "\n";
			cout << "data dist " << temp->data.dist << "\n";
			temp = temp->next;
		}
	}

	bool isEmpty(){
		node *temp = new node;
		temp = head;
		if (temp == NULL)
			return true;
		else
			return false;
	}

	bool isEmptyQ(){
		Qnode *temp = new Qnode;
		temp = Qhead;
		if (temp == NULL)
			return true;
		else
			return false;
	}

	void delete_first()
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void pop()
	{
		Qnode *temp = new Qnode;
		temp = Qhead;
		Qhead = Qhead->next;
		delete temp;
	}

	node front()  {
		node *temp = new node;
		temp = head;
		return *temp;
	}

	Qnode frontQ()  {
		Qnode *temp = new Qnode;
		temp = Qhead;
		return *temp;
	}

};

int deltaRow[] = {0,1,1, 1, 0,-1,-1,-1};
int deltaCol[] = {1,1,0,-1,-1,-1, 0, 1};
int deltaSize = sizeof(deltaRow) / sizeof(deltaRow[0]);

bool isValid(int r, int c, int N, int M){

	return r > -1 && r <N && c>-1 && c < M;
}

int shortestPathBinaryMatrixBFS(int **grid, Point src, Point dest, int N, int M){

	if (grid[src.x][src.y] == 1 || grid[dest.x][dest.y] == 1)
		return -1;

	bool **visited = new bool *[N];
	for (int i = 0; i < N; i++){
		visited[i] = new bool[M];
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	}

	visited[src.x][src.y] = true;

	linked_list q;
	queueNode s = { src, 1 };
	q.push(s);

	while (!q.isEmptyQ()){

		Qnode curr = q.frontQ();
		Point pt = curr.data.pt;

		if (pt.x == dest.x && pt.y == dest.y)
			return curr.data.dist;

		q.pop();
		
		for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++)
		{

			int row = pt.x + deltaRow[deltaIdx];
			int col = pt.y + deltaCol[deltaIdx];

			// if adjacent cell is valid, has path and 
			// not visited yet, enqueue it. 
			if (isValid(row, col, N,M) && grid[row][col] == 0 && !visited[row][col]){
				//cout << "\n adjacent \n";
				// mark cell as visited and enqueue it 
				visited[row][col] = true;
				queueNode Adjcell = { { row, col }, curr.data.dist + 1 };
				q.push(Adjcell);
			}
		}
	}
	return -1;
}
int main()
{
	 freopen("input.txt", "r", stdin);

	 int T;
	 cin >> T;

	 for (int tc = 1; tc <= T; tc++){

		 cout << "T " << tc;
		 cout << endl;

		 int N, M, num;
		 cin >> N;
		 M = N;
		 int **grid = new int *[N];

		 for (int row = 0; row < N; row++){
			 grid[row] = new int[M];
			 cout << " ";
			 for (int col = 0; col < M; col++){
				 cin >> num;
				 grid[row][col] = num;
				 cout << " " << grid[row][col];
			 }
			 cout << endl;

		 }
		 
		 Point source = { 0, 0 };
		 Point dest = { N - 1, M - 1 };

		 int dist = shortestPathBinaryMatrixBFS(grid, source, dest, N,M);

		 if (dist != INT_MAX)
			 cout << "Shortest Path is " << dist;
		 else
			 cout << "Shortest Path doesn't exist";

		 cout << endl;

	 }
	

	return 0;
}