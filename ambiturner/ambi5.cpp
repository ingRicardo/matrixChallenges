#include <iostream>
using namespace std;

void printVisit( bool **visited ,int h, int w )
{

	for(int i=0; i< h; i++)
	{
		for(int j=0; j<w; j++)
		{

			cout << visited[i][j]<< " ";
		}
		cout << endl;
	}

}
bool isValid(int **grid, bool **visited, int h, int w , int row, int col)
{

    return row>-1 && row<h && col >-1 && col<w /*&& grid[row][col] ==48*/ && !visited[row][col];

}



void recursion2(bool &right,bool &down, bool &left, bool up, int startX, int startY,int &direc ,int &spins ,int &curdirec, int **grid, bool **visited, int h, int w, int row, int col, int &max)
{
        //R,D,L,U
        //0,1,2,3
 
   // 85 //UP
   // 82 //RIGTH
   // 68 // DOWN
   // 76 //LEFT
 
   int deltaRow [] = {0,1, 0,-1};
   int deltaCol [] = {1,0,-1, 0};
  	
   int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);


	/*
	 *	if( oldDirec == 0 )
	 *		CANT GO TO  3
	 *	if ( oldDirec == 1 )
	 *		CANT GO TO 0
	 * 	if (odDirec == 2 )
	 *		CANTO GO 1
	 *	if (oldDirec == 3 )
	 *		CANT GO TO 2
	 *
	 */

   int current = grid[row][col];
   visited[row][col]=true;
   max++;
  if (current == 85)
  	direc = 3;	

    
   cout << " direc "<<direc <<endl; 

    for(int idx =0; idx<deltaSize; idx ++)
   {
        //R,D,L,U
        //0,1,2,3
 	if (direc == 3 && idx ==2 )
  	 //   idx = 0;
	     return;
      
        int nextRow = row + deltaRow[idx];
        int nextCol = col + deltaCol[idx];
   

       	if(isValid(grid,visited,h,w,nextRow,nextCol) && grid[nextRow][nextCol] !=1  )
       	{
			int next = grid[nextRow][nextCol];
			direc = idx;
			recursion2(right,down,left,up,startX, startY,direc,spins,curdirec,grid,visited,h,w,nextRow,nextCol,max);    
	}
   }

}
void recursion(int startX, int startY,int &direc ,int &spins ,int **grid, bool **visited, int h, int w, int row, int col, int &max)
{
        //R,D,L,U
        //0,1,2,3
    
   int deltaRow [] = {0,1, 0,-1};
   int deltaCol [] = {1,0,-1, 0};
   
   //int deltaRow [] = {0,1,-1};
   //int deltaCol [] = {1,0, 0};

   int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
      //cc++;
   visited[row][col]=true;
   max++;

   // 85 //UP
   // 82 //RIGTH
   // 68 // DOWN
   // 76 //LEFT
  // 48 //cero 0
  // 49 //one 1
/*
#1:4
#2:12
#3:6
#4:53
#5:27
#6:1300
#7:25
#8:1
#9:524
#10:69
*/



   for(int idx =0; idx<deltaSize; idx ++)
   {
        //R,D,L,U
        //0,1,2,3
 
        int nextRow = row + deltaRow[idx];
        int nextCol = col + deltaCol[idx];
	if ( (  ( direc == 3   && idx ==2    ) || (   direc == 0 && idx == 3  )    )  && (isValid(grid,visited,h,w,nextRow,nextCol) && grid[nextRow][nextCol] !=1 ) )
		{
		cout << "SHOULD RETURN max "<< max<<endl;
			return;
		}

        if(isValid(grid,visited,h,w,nextRow,nextCol) && grid[nextRow][nextCol] !=1  /*&& ( direc !=3 && idx!=2 ) */)
        {
		int next = grid[nextRow][nextCol];
	/*
		if(idx == 0)
 		cout << " valid "<< nextRow <<", "<< nextCol<<   " idx "<<idx <<"  RIGHT "<< " direc "<<direc<< endl;
		else if(idx == 1)
 		cout << " valid "<< nextRow <<", "<< nextCol<<   " idx "<<idx <<"  DOWN   direct "<< direc<< endl;
		else if(idx == 2)
 		cout << " valid "<< nextRow <<", "<< nextCol<<   " idx "<<idx <<"  LEFT   direct " << direc<< endl;
        	else if(idx == 3)
 		cout << " valid "<< nextRow <<", "<< nextCol<<   " idx "<<idx <<"  UP     direct "<< direc<< endl;
	*/
		if (  ( direc == 3   && idx ==2    ) || (   direc == 0 && idx == 3  )    )
	       		return;	

		direc = idx;
		recursion(startX, startY,direc,spins,grid,visited,h,w,nextRow,nextCol,max);     
		

		if (idx == 2)
		{

		cout << "back to left is visited "<< visited[row][col]<<" direc "<< direc<< endl;
		}	

		if(startX == row && startY == col /*|| idx == 2 && direc == 3*/ )
		{
		cout << "backtrack return "<<max<<endl;	
			return;
		}
        }
    }

}

int *getPos ( int **grid , int h, int w , int &c)
{
    int *pos= new int[2];
    for(int row =0 ; row < h; row++)
    {
        for(int col = 0; col< w; col++)
        {
	 	c++;
	 	if(grid[row][col] == 85   )
   		{
			cout << "\n FOUND -----  UP "<< grid[row][col]<< endl;	
			pos[0] = row;
			pos[1] = col;
			return pos ;
  		}		
   		else if (   grid[row][col]==82 )  
  		{

			cout << " \n FOUND -----  RIGHT "<< grid[row][col]<<endl;
			pos[0] = row;
			pos[1] = col;
			return pos ;
  		}
  		else if (  grid[row][col]==68 )
  		{
			cout<< "\n FOUND ------ DOWN "<< grid[row][col]<< endl;
			pos[0] = row;
			pos[1] = col;
			return pos ;
  		}
  		else if (   grid[row][col]==76  )
 		{
			cout<<"\nFOUND ------ LEFT "<< grid[row][col]<< endl;
			pos[0] = row;
			pos[1] = col;
			return pos ;

 		}

	}	
    }
   
    return pos; 
}

void getAns(int **grid, bool ** visited, int h, int w, int &max)
{
	bool up=false,down=false,left=false,right=false;
	int deltaID =0, spins =0,row=0, col=0, c=0,curdirec=0;
	int *start =getPos(grid,h,w,c);
	cout << " START --> "<< start[0] <<", "<< start[1]<<  " c -> "<< c<< endl;
	//recursion(start[0],start[1],deltaID,spins ,grid, visited,h, w, start[0],start[1], max);
	recursion2(right,down,left,up,start[0],start[1],deltaID,spins ,curdirec, grid, visited,h, w, start[0],start[1], max);
	cout<<endl;
	cout<< "print bool "<<endl;
	printVisit(visited,h,w);
}

int main()
{

    freopen("input.txt","r",stdin);
    int T,h,w,num,max =0;
    cin >> T;
    char c;
    for(int tc =1; tc<=T ; ++tc)
    {
        cin >> h; cin >>w;
        max =0;
        int **grid = new int*[h];
        bool **visited = new bool*[w];
        for(int row =0; row<h; row++)
        {
            cout << endl;
            grid[row] = new int[h];
            visited[row] = new bool[h];
            for(int col =0; col< w; col++)
            {   
                cin >> c;
                num = (int)c;
               // cin>> num;
	       //
	       if (num==48 )
		    num = 0;
		else if ( num == 49)
		    num =1;	
                grid[row][col] = num;
                visited[row][col] = false;
               cout << " "<< grid[row][col];
            }
        }
	cout<<endl;
        getAns(grid, visited, h,w,max);
        cout<<endl;
     cout << "#"<<tc<<":"<<max<<endl;   
    }



	return 0;
}
