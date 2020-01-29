#include <iostream>

using namespace std;
bool isValid(int **grid, bool **visited,int n,int row, int col)
{

	return row>-1 && row<n && col>-1 && col<n && grid[row][col] !=0 && !visited[row][col]; 

}

void recursion(int **grid, bool **visited, int n, int &acc, int &max, int row, int col )
{
	
	int deltaRow [] = {0,1,0,-1};

	int deltaCol [] = {1,0,-1,0};
	int deltasize = sizeof(deltaRow)/sizeof(deltaRow[0]);

	visited[row][col]= true;
	acc+=1;
	for(int idx =0; idx<deltasize; idx++)
	{

		int nextRow = row + deltaRow[idx];
		int nextCol = col + deltaCol[idx];

		if(isValid(grid,visited,n, nextRow, nextCol))
		{

			recursion(grid,visited,n,acc,max,nextRow,nextCol);

		}
	}
	
	if(acc>max)
		max =acc;

	
}

void getAns(int **grid,int n,  bool **visited,int& max, int &constNumb )
{

	int acc=0;	
	for(int row =0; row< n; row++){
		for(int col=0; col<n; col++){
			if(grid[row][col] ==1 && !visited[row][col]){
				constNumb+=1;
				recursion(grid,visited,n,acc,max,row,col);
				acc =0;

			}
		}
	}
}


int main()
{

	freopen("input.txt","r",stdin);
	
	int T,n=0,num=0,acc=0,max=0,constNumb=0;

	cin>>T;

	for(int tc=1; tc<=T; ++tc)
	{
		max=0;
		constNumb=0;
		cin>>n;
		int **grid = new int*[n];
		bool **visited = new bool*[n];
		for(int row=0; row<n; row++){
		cout <<endl;
			grid[row] = new int[n];
			visited[row] = new bool[n];
			for(int col=0; col<n; col++)
			{
				cin>>num;
				grid[row][col] = num;
				visited[row][col] = false;
				cout<< " "<<grid[row][col];

			}	

		}

	cout<<endl;
	getAns(grid,n,visited,max,constNumb);
		cout << "#"<<tc<<":   "<< constNumb << "  "<<max<<endl;

		

	}
	
	
return 0;
}
