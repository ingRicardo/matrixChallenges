/*
		Airplane Game
		Ricardo Alfredo Macias Olvera
		Software Engineer
*/
#include <iostream>
using namespace std;

bool isValid(int grid [7][5],int width, int height, int x, int y ,int hX)
{

	return x>-1 && x < height && y>-1 && y< width;

}

void func1(int grid[7][5], int x, int y, int height, int width,int hX,int coins )
{
	cout<<"height -> "<<height <<endl;
	cout <<"width -> "<<width<<endl;

	cout <<"hX -> " << hX<<endl;
	cout<<"current_val -> "<<grid[x][y]<<endl;
        cout <<"coins -> "<<coins<<endl;	
	int current = grid[x][y];

	int deltaX[] = {0 ,0,0};
	int deltaY[] = {-1,1,0};

	int dsize =  sizeof(deltaX)/sizeof(deltaX[0]);

	cout << "deltaSize "<< dsize <<endl;

	for (int idx = 0; idx < dsize; idx ++)
	{

		int nextX = deltaX[idx] + x;
		int nextY = deltaY[idx] + y;
		if( isValid( grid, width,height,nextX, nextY ,hX))
		{
			int next =  grid[nextX][nextY];
			if( next == 1)
				coins+=1;
			else if (next == 2 )
				coins-=1;

			next = grid[ nextX-1][nextY];// move Up


		}


	}
	/*
	 *
	 *      if coins < 0 OR height == 0
	 *		END GAME
	 *      	
	 *	move to the left or right or stay
	 *		if left == 1
	 *			move = left
	 *		else if right = 1
	 *			move right
	 *		else if stay == 1
	 *			move = stay
	 *		else 
	 *			move = left
	 *
	 *	check if there's 1 or 2
	 *
	 *		if current == 1 
	 *			add 1 to coins
	 *		else if current == 2
	 *			susbtract 1 to coins
	 *	
	 *	if left == 2 AND right == 2 AND current == 2
	 *		apply the bomb
	 *
	 *		for (int i = hX; i< height ; i++)
	 *			for(int j =0; j<width; j++ )
	 *				if(grid[i][j]) == 2)
	 *					grid[i][j]=0;
	 *
	 *			
	 *
	 *     SHRINK THE GAME ZONE
	 *     		if hX >1
	 *     			hX -=1
	 *
	 *     		height -=1
	 *
	 *      recursion 
	 *
	 *
	 *
	 *
	 *
	 */

	

}
int main()
{


	/*
	 *	height =N , width = 5
	 *	DELIMITED AREA = 5X5
	 * 	GAME AREA = x =  startHeighValue = N-width , y = width 
	 *		variable height_START every step DECREASE
	 *	2. 4.	variable height_END   every step DECREASE
	 *	CONTROL AREA = Initial position (coordenates x,y)   
	 *	width of the map is always five and the airplane starts at center			
	 *			center	x=0,y=2
	 *      1. MOVES = for loop  left,right,0
	 *	INITIAL POSITION MAP DESCENDS ONE STEP = if(x!=0) x-=1  
	 *	3. IF ( coins < 0 )
	 *		RETURN
	 *
	 *
	 *	IF( position == 2 ) 
	 *		coins -=1 
	 *	ELSE IF (position == 1 )
	 *		coins+=1;
	 *
	 *	0
	 *      0
	 *      X,Y   ^
	 *
	 *
	 *
	 *	0    ^
	 *      X,Y  ^
	 *     
	 *    5. IF height_START == height_END 
	 *    		RETURN
	 *
	 *    	IF LEFT ==2 AND RIGHT ==2 AND CURRENT =2
	 *    		USE THE BOMB 	
	*/	 
	cout << "Airplane Game under construction "<<endl;
int h=7;
	int mat[h][5] =   { 
			     { 1,2,0,0,1}, 
			     { 2,0,0,1,0}, 
			     { 0,1,2,0,1}, 
			     { 1,0,0,2,1}, 
			     { 0,2,1,0,1}, 
			     { 0,1,2,2,2}, 
			     { 1,0,1,1,0} 
			} ;   
//Top

int hX= h-5;
int height =  h ;
int width= 5;
//Down

int endX = 0;
int endY = 0;
//current
int curX = h-1;
int curY = 2;
int coins =0;
	func1(mat,curX,curY,height,width,hX,coins);
	return 0;
}
