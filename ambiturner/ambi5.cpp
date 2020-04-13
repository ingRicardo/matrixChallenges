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

    return row>-1 && row<h && col >-1 && col<w && grid[row][col] ==0 /*&& !visited[row][col]*/;

}


void recursion3(bool &right,bool &down, bool &left, bool up, int startX, int startY,int &direc ,int &spins ,int &curdirec, int **grid, bool **visited, int h, int w, int row, int col, int &max)
{
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

  int deltaRow [] = {0,1, 0,-1};
  int deltaCol [] = {1,0,-1, 0};
  int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
  int current = grid[row][col];
 
  if (current == 85)
  {
	up = true;
  	direc = 3;	
  }
  if(current == 82)
  {	 
	  right = true;
	  direc = 0;
  }
  if(current == 68)
  {	
       	down = true;
	direc = 1;
  }
  if(current == 76)
  {
	left = true;
	direc = 2;
  }
 //R,D,L,U
 //0,1,2,3
 if(!visited[row][col] )
	max++;
  
  visited[row][col]=true;
  do
  {
        int nextRow = row + deltaRow[direc];
        int nextCol = col + deltaCol[direc];
	
	if(isValid(grid,visited,h,w,nextRow,nextCol) /*&& grid[nextRow][nextCol] !=1*/  )
	{
		recursion3(right,down,left,up,startX, startY,direc,spins,curdirec,grid,visited,h,w,nextRow,nextCol,max);    
	}	
	else 
	{
            if(direc ==3)
                    direc=0;
             else if(direc == 0)
                    direc =1;
             else if (direc == 2)
                    direc =3;
             else if (direc == 1)
                    direc =2;
    
		spins++;
	}
  }while(spins <=120);

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
	recursion3(right,down,left,up,start[0],start[1],deltaID,spins ,curdirec, grid, visited,h, w, start[0],start[1], max);
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
