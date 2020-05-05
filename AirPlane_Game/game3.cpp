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
	//	if(bomb)
	//	{
				
			coins-=1;
	//	}

	}
	
	if( h == 0 )
	{
		cout << " end coins --------------------------------------> "<<coins << " height "<< h<< " hX "<< hX <<" bomb "<<bomb<<" isPath "<<isPath<<" current "<<current<<endl;
		return;
	}

	isPath = false;

	int noValid =0;
	int nextRow =0,nextCol =0;
	int passOne = 0;	

	
	//NEED TO IMPLEMENT SOMETHING THAT TELLS ME IF THERE'S A 0 IF YES LOOK FOR 1 AND RECURSE

	/*
	 *
	 *	loop moves and check if there are empty space or 0 on the 3 moves if yes move to the first
	 *	loop moves and check if there is a coin or 1 in one of the three moves if yes move to the one 
	 *
	 *
	 *
	 * 		
	 */
	int ene=0,space=0,coin=0;	
	//bool test = false;
	int moveCoin=0, moveSpace =0, moveEne=0;
	// loop to find a enemy an apply the bomb
	for(int idx =0; idx < dsize; idx++)//move horizontal 
	{
		nextRow = (row + deltaX[idx]) -1 ;
		nextCol = col + deltaY[idx];
		noValid+=1;
	       	if(isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==1   )
		{
			//passOne = idx;
			coin+=1;
			moveCoin = idx;
			break;

		}
		else  if (isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==2    )
		{
			ene+=1;
			moveEne =idx;
			if (ene == 2 && !bomb)
			{
	//			test = true;
			//	break;
			}
		}
		else  if (isValid(gridAux,nextRow,nextCol,h,w) && gridAux[nextRow][nextCol]==0    )
		{
			moveSpace= idx;
			space+=1;	

		}

	}
	cout << " how many enemies -> "<< ene << " space "<< space<<" coins "<< coin<< endl;

	if (coin >0)
		passOne = moveCoin;
	else if (space >0) 
	{
		passOne = moveSpace;

/*
		if (space>ene)
			passOne = moveSpace;
		else if (space < ene)
			{
				passOne = moveEne;
			}
		else if (space == ene)
			passOne = moveSpace;
		*/			

	}

	if (ene >=2 && !bomb && space == 0 && coin ==0   /*&& coin == 0 || ( test && !bomb)*/ ||  ( ene >=2 && !bomb && /*space == 1 &&  test && coin ==0 &&*/ moveSpace>1 ) )
	{
			cout <<"********** BOMB APPLIED ***********"<<" h  "<<h << " hX "<< hX<<endl;
                	for (int i = hX; i< h ; i++)
                        	for(int j =0; j<w; j++ )
                                	if(gridAux[i][j] == 2)
                                        	gridAux[i][j]=0;

		/*apply bomb*/
		bomb = true;
		passOne=0;
	}
		
	//
	//NEED TO CHECK AGAIN IF THERE IS A ONE OR COIN 
	//
	

	//loop for moving horizontally
	for(int idx =passOne; idx < dsize; idx++)//move horizontal 
	{
		nextRow = (row + deltaX[idx]) -1 ;
		nextCol = col + deltaY[idx];
		noValid+=1;
		

               	if(isValid(gridAux,nextRow,nextCol,h,w) && (gridAux[nextRow][nextCol]==1 || gridAux[nextRow][nextCol] ==0 /*|| (ene>=2 && space==0) */ || gridAux[nextRow][nextCol] ==2 ) )
		{
		
			int next = gridAux[nextRow][nextCol];
		cout << "valid -----------> "<<next<<": coordinates "<<nextRow<<","<<nextCol<<" moved to ->"<<idx<<endl;

		if(hX>0)
			hX-=1;//decrease superior limit 	

			h-=1;//decrease inferior limit
			funcRecTest1(gridAux,coins,nextRow, nextCol,h,w,hX,bomb,isPath,prevDirec);


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
		cout<<endl;
		func1(grid,h,res);
		cout << "#"<<tc<<":"<<res<<endl;

	}


	return 0;
}
