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

void funcRecTest1(int **&gridAux,int &coins,int row, int col, int &h, int w, int &hX, bool &bomb)
{
	int current = gridAux[row][col];
    int deltaX[] = {0 ,0,0};
    int deltaY[] = {1,0,-1};
    int dsize =  sizeof(deltaX)/sizeof(deltaX[0]);
	
	if(current == 1)
		coins+=1;
	else if (current == 2)
			coins-=1;
	
	if( h == 0 )
		return;
	
	int nextRow =0,nextCol =0,passOne = 0,ene=0,space=0,coin=0,moveCoin=0, moveSpace =0, moveEne=0;
	// loop to find a enemy an apply the bomb
	for(int idx =0; idx < dsize; idx++)//move horizontal 
	{
		nextRow = (row + deltaX[idx]) -1 ;
		nextCol = col + deltaY[idx];
	    if(isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==1   )
		{
			coin+=1;
			moveCoin = idx;
			break;
		}
		else  if (isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==2    )
		{
			ene+=1;
			moveEne =idx;
		}
		else  if (isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==0    )
		{
			moveSpace= idx;
			space+=1;	
		}
	}
	
	if (coin >0)
		passOne = moveCoin;
	else if (space >0) 
		passOne = moveSpace;

	if (ene >=2 && !bomb && space == 0 && coin ==0    ||  ( ene >=2 && !bomb &&  moveSpace>1 ) )
	{
        for (int i = hX; i< h ; i++)
            for(int j =0; j<w; j++ )
                if(gridAux[i][j] == 2)
                    gridAux[i][j]=0;

		bomb = true;
		passOne=0;
	}
	//loop for moving horizontally
	for(int idx =passOne; idx < dsize; idx++)//move horizontal 
	{
		nextRow = (row + deltaX[idx]) -1 ;
		nextCol = col + deltaY[idx];
		
        if(isValid(gridAux,nextRow,nextCol,h,w) )
		{
			int next = gridAux[nextRow][nextCol];

			if(hX>0)
				hX-=1;//decrease superior limit 	

			h-=1;//decrease inferior limit
			funcRecTest1(gridAux,coins,nextRow, nextCol,h,w,hX,bomb);
		} 
	}
}

void func1(int **grid, int h, int &res)
{

	//Starts here
	//
	int hX = h-5;// above limit
	int w = 5;
	int coins =0;
	int hAux =h+1;
	//cout << "top limit  "<< hX << " width "<<w << " height "<<h <<endl;
	int **gridAux = new int*[hAux];
	
	for(int row =0; row<hAux; row++)
	{
		gridAux[row] = new int[hAux];
		for(int col=0; col<5; col++)
		{
			gridAux[row][col] = 6;
		}

	}
	
	for(int row =0; row<h; row++)
		for(int col=0; col<5; col++)
			gridAux[row][col] = grid[row][col];
	
	//printGrid(gridAux,hAux,w,0);
	//printGrid(gridAux,hAux,w,hX);
	int curX = hAux -1; //start position in X
	int curY = 2;	//start position in Y
	bool bomb = false;
	funcRecTest1(gridAux,coins,curX,curY,h,w,hX,bomb);
	//printGrid(gridAux,h,w,hX);
	res = coins;
}
int main()
{
	freopen("input.txt","r",stdin);

	int T,res=0;
	cin>>T;

	for(int tc=1; tc<=T; ++tc)
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
//		cout<<endl;
		func1(grid,h,res);
		cout << "#"<<tc<<":"<<res<<endl;

	}
	return 0;
}
