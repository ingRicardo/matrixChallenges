#include <iostream>
using namespace std;


bool isValid(int **grid, bool **visited, int h, int w , int row, int col)
{

    return row>-1 && row<h && col >-1 && col<w && grid[row][col] ==48 && !visited[row][col];

}
void recursion(int cc ,int &spins ,int **grid, bool **visited, int h, int w, int row, int col, int &max)
{
        //R,D,L,U
        //0,1,2,3
    
   int deltaRow [] = {0,1, 0,-1};
   int deltaCol [] = {1,0,-1, 0};
   int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
        
   visited[row][col]=true;
   cc++;
   // 85 //UP
   // 82 //RIGTH
   // 68 // DOWN
   // 76 //LEFT
  // 48 //cero 0
  // 41 //one 1
  if(grid[row][col] == 85   )
   {
	cout << "\n UP "<< grid[row][col]<< endl;	

   }
   else if (   grid[row][col]==82 )  
   {
	cout << " \nRIGHT "<< grid[row][col]<<endl;
   }
  else if (  grid[row][col]==68 )
  {
	cout<< "\n DOWN"<< grid[row][col]<< endl;

  }
  else if (   grid[row][col]==76  )
  {
	cout<<"\nLEFT"<< grid[row][col]<< endl;

  }
  else
  {

//	return;
  }

 int sp =0;  	
   for(int idx =0; idx<deltaSize; idx ++)
   {
	sp++;
        int nextRow = row + deltaRow[idx];
        int nextCol = col + deltaCol[idx];
        if(isValid(grid,visited,h,w,nextRow,nextCol)  )
        {
              recursion(cc,spins,grid,visited,h,w,nextRow,nextCol,max);     
        }
    }

   if(sp ==4)
   {
	   return;

   }
   cc--;
   visited[row][col]=false;

}


void getAns(int **grid, bool ** visited, int h, int w, int &max)
{

   int deltaID =0, spins =0,row=0, col=0;

   recursion(deltaID,spins ,grid, visited,h, w, row, col, max);


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
