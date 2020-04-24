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

void funcRecTest1(int **&gridAux,int &coins,int row, int col, int &h, int w, int &hX, bool &bomb, bool &isPath, int &prevDirec)
{

	int current = gridAux[row][col];
        int deltaX[] = {0 ,0,0};
        int deltaY[] = {1,0,-1};


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
	 *		1-move (right/stay/left)
	 *		2-check if there is a coin 
	 *			2.1 -move up
	 *			2.2 -add one to coin
	 *			
	 *		3-check if there is an enemy and bomb == false
	 *			3.1 -apply the bomb and bomb == true
	 *			     move up
	 *			else if there's an enemy and bomb == true
	 *			     move up
	 *			     substract one to coin
	 *
	 *		4-go back to first step
	 *
	 *		-----------------------------------------
	 *		HOW IT'S MOVING HORIZONTALLY?
	 *		IF IT MOVED TO SPECIFIC DIRECTION AND THEN RECURSES IT STAYED WITH THE PREVIOUS DIRECTION OR STARTS AGAIN WITH MOVING TO RIGHT
	 *
	 *
	 *
	 */


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


		/*
		 *
		 *	if bomb == true
		 *
		 *		apply bomb
		 *
		 *	if current == 2
		 *		coins =-1
		 *
		 *
		 */


	}

	if(coins <0 || h == 0 || h==hX )
	{
		cout << " end coins --------------------------------------> "<<coins << " height "<< h<< " hX "<< hX <<" bomb "<<bomb<<" isPath "<<isPath<<endl;
		return;
	}
	isPath = false;
//HOW TO KNOW IF THERE IS A PATH 
//

// NEEDS TO VALIDATE IF THERE IS AN ENEMY TO APPLY THE BOM BEFORE STARTS TO MOVE
//
//
//	CHANGE THE VALID TO MOVE TO 0,1 AND 2
//	AND LOOK FOR THE ONES TO MOVE or GET THE PREVIOUS POSITION WHEN THE TURN STARTS AGAIN
//
//
	

	/*
	 *CHECK IF IN STAY POSITION DOES EXIST AN ENEMY IF TRUE APPLY THE BOMB
	 *
	 *
	 *
	 **************   APPLY THE BOMB AND THEN MOVE IT ????????? THIS NEEDS FOCUS ********
	 */ 	

	int noValid =0;
	int nextRow =0,nextCol =0;


	nextRow = (row + deltaX[0]) -1 ;
	nextCol = col + deltaY[0];
	if(isValid(gridAux,nextRow,nextCol,h,w) &&  gridAux[nextRow][nextCol] == 2) 
	{
		cout << "SHOULD APPLY THE BOMB AT THE START OF THE GAME "<<endl;

	}

	for(int idx =0; idx < dsize; idx++)//move horizontal 
	{
		nextRow = (row + deltaX[idx]) -1 ;
		nextCol = col + deltaY[idx];
		noValid+=1;
		if(isValid(gridAux,nextRow,nextCol,h,w) && ( gridAux[nextRow][nextCol] == 1 ||  gridAux[nextRow][nextCol]==2    )   )
		{
			isPath = true;
			int next = gridAux[nextRow][nextCol];
			prevDirec = idx;
			cout << "valid -----------> "<<next<<": coordinates "<<nextRow<<","<<nextCol<<" moved to ->"<<idx<<endl;
			if(hX>0)
				hX-=1;//decrease superior limit 	


			h-=1;//decrease inferior limit
			funcRecTest1(gridAux,coins,nextRow, nextCol,h,w,hX,bomb,isPath,prevDirec);

		}
	}

	cout <<" isPath "<<isPath <<" noValid "<< noValid<<endl; 
	if(isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol] == 0)
	{

	//	cout << " -> "<<gridAux[nextRow][nextCol]<<endl; 
	//	cout << "end THERE IS NO PATH coins "<<coins << " bomb "<<bomb<<  endl;

	//	if (bomb && coins == 0)
	//		coins =-1;
	//	return;
	//
		if (   gridAux[nextRow][nextCol] ==0) 
		{

			//coins=-1;
			//cout << " END -> COINS "<<coins << " bomb "<< bomb <<endl;
			//return;
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
			gridAux[row][col] = 6;
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
bool isPath = true;
int prevDirec =0;
funcRecTest1(gridAux,coins,curX,curY,h,w,hX,bomb,isPath,prevDirec);
cout << endl;
printGrid(gridAux,h,w,hX);
cout << " coins -> "<<coins <<" h "<<h << " hX "<<hX<< endl;
res = coins;
}
int main()

{
	freopen("input.txt","r",stdin);

	int T,res=0;
	cin>>T;

	for(int tc=1; tc<=4; ++tc)
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
