#include<iostream>

using namespace std;

void printGrid(int **grid, int h,int w, int hX) 
{
	for(int row =hX; row<h; row++)
	{
		cout<<endl;
		for(int col=0; col<w; col++)
			cout << " "<<grid[row][col];
	}
	cout<<endl;
	
}
bool isValid(int **grid,int row, int col, int h, int w)
{

	return row>-1 && row<h && col>-1 && col<w;

}

void funcRecTest1(int **grid,int &coins,int row, int col, int &h, int w, int &hX)
{

	int current = grid[row][col];
        int deltaX[] = {0 ,0,0};
        int deltaY[] = {-1,1,0};
        int dsize =  sizeof(deltaX)/sizeof(deltaX[0]);
	
	cout << "current -> "<< current << "[ row "<<row << ", col "<<col<<"]"<<endl;


	/*
	 *	1. move to the left, right or stay
	 *	2. check how many enemies are here and if there are coins
	 *	3. moves one step up.
	 */
	int enemies =0;
	for(int idx =0; idx < dsize; idx++)
	{
		int nextRow = row + deltaX[idx];
		int nextCol = col + deltaY[idx];
		if(isValid(grid,nextRow,nextCol,h,w))
		{
			cout << "valid "<<endl;
			int next = grid[nextRow][nextCol];
			if(next == 2)
			{
				enemies+=1;
				coins-=1;
			}
			else if (next == 1)
			{

				coins+=1;
				//break;
				// moves UP
				//recursion OR break ??

				if (isValid(grid,nextRow-1,nextCol,h,w))//moves UP in ROW 
				{
					cout << "VALID UP "<<endl;
			 		//funcRecTest1(grid,coins,row, col,h,w, hX);
				}
			}
		}
	}
	cout << " coins "<<coins << " enemies "<<enemies <<endl;
}

void func1(int **grid, int h, int &res)
{

	//Starts here
	//
int hX = h-5;// above limit
int w = 5;

int curX = h -1; //start position in X
int curY = 2;	//start position in Y
int coins =0;
cout << "top limit  "<< hX << " width "<<w << " height "<<h <<endl;
printGrid(grid,h,w,0);


funcRecTest1(grid,coins,curX,curY,h,w,hX);

}
int main()

{
	freopen("input.txt","r",stdin);

	int T,res=0;
	cin>>T;

	for(int tc=1; tc<=1; ++tc)
	{
		int h;
		cin>> h;

		int **grid = new int*[h];
		int val;
		for(int row =0; row<h; row++)
		{
			grid[row] = new int[h];
			for(int col=0; col<5; col++)
			{
				cin>>val;
				grid[row][col]=val;
			}

		}
		cout<<endl;
		func1(grid,h,res);
		cout << "#"<<tc<<":"<<res<<endl;

	}


	return 0;
}
