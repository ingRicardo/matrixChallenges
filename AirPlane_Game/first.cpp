/*
		Airplane Game
		Ricardo Alfredo Macias Olvera
		Software Engineer
*/
#include <iostream>
using namespace std;
void func1(int grid[7][5], int x, int y, int limX)
{
	cout<<"limitX-> "<<limX<<endl;
	cout<<"current-> "<<grid[x][y]<<endl;
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
int limitX= h-5;
int limitY= 0;
//Down

int endX = 0;
int endY = 0;
//current
int curX = h-1;
int curY = 2;

	func1(mat,curX,curY,limitX);
	return 0;
}
