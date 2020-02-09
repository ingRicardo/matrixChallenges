#include <iostream>
using namespace std;
void printVisi(bool **visited, int h, int w)
{

    for(int row =0; row<h; row++)
    {
        cout<<endl;
        for(int col =0; col<w; col++)
        {
            cout << " "<< visited[row][col];
        }
        
    }
    cout<<endl;
}

bool isValid(int **grid, bool **visited, int h, int w , int row, int col)
{

    return row>-1 && row<h && col >-1 && col<w && grid[row][col] ==48 /*&& !visited[row][col]*/;

}
void recursion(int &deltaID,int &spins ,int **grid, bool **visited, int h, int w, int row, int col, int &max)
{
        //R,D,L,U
        //0,1,2,3
    
    if(grid[row][col] == 85)//UP
            deltaID = 3;
    if(grid[row][col] == 82) //RIGTH
            deltaID = 0;
    if(grid[row][col] == 68) // DOWN
            deltaID = 1;
    if(grid[row][col] == 76) //LEFT
            deltaID =2;

    int deltaRow [] = {0,1, 0,-1};
    int deltaCol [] = {1,0,-1, 0};
    int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
        
    if(!visited[row][col])
        max +=1;
    
        visited[row][col]=true;
    
    do
    {
        int nextRow = row + deltaRow[deltaID];
        int nextCol = col + deltaCol[deltaID];
          if(isValid(grid,visited,h,w,nextRow,nextCol)  )
          {
              recursion(deltaID,spins,grid,visited,h,w,nextRow,nextCol,max);     
          }else {
                if(deltaID ==3)
                    deltaID=0;
                else if(deltaID == 0)
                    deltaID =1;
                else if (deltaID == 2)
                    deltaID =3;
                else if (deltaID == 1)
                    deltaID =2;
           
            spins+=1;
          }
    }while (spins <=120);
}
void getAns(int **grid, bool ** visited, int h, int w, int &max)
{

    int direct=100,spins=0,deltaID=0; 

 bool stop =false;
    for(int row =0 ; row < h; row++)
    {
        for(int col = 0; col< w; col++)
        {
            if(grid [row][col ] == 85 || grid [row][col ] == 82 || grid [row][col ] == 68 || grid [row][col ] == 76)
            {
                recursion(deltaID,spins,grid,visited,h,w,row, col,max);
                stop =true;
              //  printVisi(visited,h,w);
                break;

            }
        }
        if(stop)
            break;
    }
    

}
int main()

{

    freopen("input.txt", "r", stdin);


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
        //    cout << endl;
            grid[row] = new int[h];
            visited[row] = new bool[h];
            for(int col =0; col< w; col++)
            {   
                cin >> c;
                num = (int)c;
               // cin>> num;
                grid[row][col] = num;
                visited[row][col] = false;
        //        cout << " "<< grid[row][col];
            }
        }

        getAns(grid, visited, h,w,max);
        //cout<<endl;
     cout << "#"<<tc<<":"<<max<<endl;   
    }


    return 0;
}