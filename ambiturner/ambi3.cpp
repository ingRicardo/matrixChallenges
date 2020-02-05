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

    return row>-1 && row<h && col >-1 && col<w && grid[row][col] ==48 && !visited[row][col];

}
void recursion(int &chkCol ,int &direct ,int **grid, bool **visited, int h, int w, int row, int col,bool R,bool D,bool L, bool U, int &max)
{
        //R,D,L,U
        //0,1,2,3

    if(grid[row][col] == 85)//UP
        {
            direct =3;
           
        }  
    if(grid[row][col] == 82) //RIGTH
        {
            direct =0;
              
        }
    if(grid[row][col] == 68) // DOWN
        {
            direct =1;
              
        }
    if(grid[row][col] == 76) //LEFT
        {
            direct =2;
              
        }

    int deltaRow [] = {0,1, 0,-1};
    int deltaCol [] = {1,0,-1, 0};
    int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
        

    visited[row][col] = true;
    
    max +=1;
    chkCol=0;
    for(int deltaID= 0 ; deltaID < deltaSize; deltaID++)
    {
      
        int nextRow = row + deltaRow[deltaID];
        int nextCol = col + deltaCol[deltaID];
        
       chkCol+=1;
       
        if(isValid(grid,visited,h,w,nextRow,nextCol)  )
        {
            chkCol-=1;
            if(direct != deltaID){
                //check old direct 
                if(direct == 0)
                    R=false;
                
                if(direct == 1)
                    D=false;

                if(direct == 2)
                    L=false;

                if(direct == 3)
                    U=false;
                   
                direct = deltaID;
            
           }

                  //   cout << "\n  valid " << nextRow << ", "<<nextCol<<endl;
                    if((deltaID == 2 && !L ) ||  (deltaID == 0 && !R ) ||
                    (deltaID == 1 && !D ) || (deltaID == 3 && !U ) )
                    {
                       
                        return;
                    }
                        
                   //     chkCol = nextCol;
                  //      cout << "\n move to "<< deltaID<< " val -> "<< grid[nextRow][nextCol]<< " D "<< D<< " direct "<< direct<<endl;
                        recursion(chkCol,direct,grid,visited,h,w,nextRow,nextCol,R,D,L,U,max);
                    
                
        }//valid
        
        if(chkCol == 4)
            return;

        
      
    }
    
}
void getAns(int **grid, bool ** visited, int h, int w, int &max)
{

    int direct=100,chkCol=0; 
    bool R=true,D=true,L=true,U=true;

 bool stop =false;
    for(int row =0 ; row < h; row++)
    {
        for(int col = 0; col< w; col++)
        {
            if(grid [row][col ] == 85 || grid [row][col ] == 82 || grid [row][col ] == 68 || grid [row][col ] == 76)
            {
                recursion(chkCol,direct,grid,visited,h,w,row, col,R,D,L,U,max);
                stop =true;
                printVisi(visited,h,w);
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
    for(int tc =1; tc<=3; ++tc)
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

        getAns(grid, visited, h,w,max);
        cout<<endl;
     cout << "#"<<tc<<":"<<max<<endl;   
    }


    return 0;
}