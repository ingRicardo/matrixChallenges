#include<iostream>

using namespace std;

void printGrid(int **grid, int h) 
{
	for(int row =0; row<h; row++)
	{
		cout<<endl;
		for(int col=0; col<5; col++)
			cout << " "<<grid[row][col];
	}
	cout<<endl;
	
}

void func1(int **grid, int h, int &res)
{

	//Starts here
	//
	
	printGrid(grid,h);

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
