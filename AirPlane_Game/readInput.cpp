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
        int deltaY[] = {-1,1,0};
        int dsize =  sizeof(deltaX)/sizeof(deltaX[0]);
	

cout << "current  -> "<< gridAux[row][col] <<" : "<< row<<","<<col<<endl;

	/*
	 *	1. move to the left, right or stay
	 *	2. check how many enemies are here 
	 *		if(enemies == 2 )
	 *			apply the bomb
	 *
	 *	3. moves one step up.
	 *
	 *
	 *	IM AM ON THE CENTER IN THE CONTROL AREA (what is the control area?)
	 *	MOVE RIGHT 
	 *	MOVE UP ONE STEP ON THE INFERIOR LIMIT AND MOVE UP ONE STEP ON THE SUPERIOR LIMIT OF THE GAME AREA
	 *
	 *	
	 *	IF CURRENT == COIN 
	 *		ADD 1 TO COINS
	 *
	 *
	 *
	 *
	 *
	 */

	if(coins <0 )
	{
		cout << " end coins -> "<<coins << " height "<< h<< " hX "<< hX <<" bomb "<<bomb<<endl;
		return;
	}

	if(current == 1){

		coins+=1;

	}
	else if (current == 2)
	{
		if(!bomb)
		{
			//next step is how to apply the bomb
                	cout <<"********** BOMB APPLIED ***********"<<" h  "<<h << " hX "<< hX<<endl;
                	for (int i = hX; i< h ; i++)
                	{
                        	for(int j =0; j<w; j++ )
                        	{
                                	if(gridAux[i][j] == 2)
                                	{
                                        	gridAux[i][j]=0;
                                	}
                        	}
                	}
		//
			bomb = true;	
		}else
		{
			coins-=1;
		}

	}
	for(int idx =0; idx < dsize; idx++)//move horizontal 
	{
		int nextRow = row + deltaX[idx] -1 ;
		int nextCol = col + deltaY[idx];
		if(isValid(gridAux,nextRow,nextCol,h,w)  )
		{
			int next = gridAux[nextRow][nextCol];
			cout << "valid "<<next<<":"<<nextRow<<","<<nextCol<<endl;
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
cout << "top limit  "<< hX << " width "<<w << " height "<<h <<endl;
int **gridAux = new int*[hAux];
	for(int row =0; row<hAux; row++)
	{
		gridAux[row] = new int[hAux];
		for(int col=0; col<5; col++)
		{
			gridAux[row][col] = 0;
		}

	}
	
	for(int row =0; row<h; row++)
		{
			for(int col=0; col<5; col++)
			{
				gridAux[row][col] = grid[row][col];
			}

		}
cout<<endl;
cout <<"Augmented grid "<<endl;
printGrid(gridAux,hAux,w,0);

cout<<endl;
cout << "game Area "<<endl;
printGrid(gridAux,hAux,w,hX);

int curX = hAux -1; //start position in X
int curY = 2;	//start position in Y
//cout << "current position -> "<< gridAux[curX][curY] <<" : "<< curX<<","<<curY<<endl;
bool bomb = false;
funcRecTest1(gridAux,coins,curX,curY,h,w,hX,bomb);
cout << endl;
printGrid(gridAux,h,w,hX);
cout << " coins -> "<<coins <<endl;
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
