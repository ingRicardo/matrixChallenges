#include <iostream>

using namespace std;

bool isValid (int row, int col, int n, bool **visited)
{
    
    return row>-1 && row < n && col>-1 && col<n && !visited[row][col];

}
void pvisited(bool **visited, int n)
{
    for(int row =0; row< n; row++)
    {
        cout << endl;
        for(int col=0; col<n; col++)
        {
            cout << " "<< visited[row][col]; 

        }
    }
    cout << endl;
}
void recursion(int **grid, bool**visited, int n, int acc, int &min ,int &max, int row, int col)
{

    int deltaRow[] = {0,1,0,-1};
    int deltaCol[] = {1,0,-1,0};
    int deltasize = sizeof(deltaRow)/ sizeof(deltaRow[0]);
    int current = grid[row][col];
    int lr=0,lc=0;
    bool move =false;
    visited[row][col] = true;
   
    for(int idx =0; idx < deltasize; idx++)
    {
        int nextRow = row + deltaRow[idx];
        int nextCol = col + deltaCol[idx];
        if(isValid(nextRow,nextCol,n,visited))
        {
            int next = grid[nextRow][nextCol];
            if (min>next)
            {
                min = next;
                move=true;
                lr = nextRow;
                lc= nextCol;
            }
            
        }

    }


    if(move)
    {
        
            acc+=1;
           // cout << " "<<grid[lr][lc];
            recursion(grid,visited,n,acc,min,max,lr,lc);

       
    }
    
    
    visited[row][col] = false;

    if(acc>max)
        max=acc;

    if(!move)
        return;
}

void getAns(int **grid, bool ** visited, int n, int &max)
{

    int acc=1;
    int min =100000;
    for(int row =0; row<n; row++){
        for(int col =0; col<n; col++){
            recursion(grid,visited,n,acc,min, max,row,col);
            min=10000;
            //cout << "visited"<<endl;
          //  pvisited(visited,n);
         //   acc=1;
         // for(int row =0; row< n; row++)
        //        for(int col=0; col<n; col++)
        //          visited[row][col]=false; 

                
            
        }
    }
    
}
int main()
{
    int T,n,val,max=0;
    //freopen("input_large.txt","r",stdin);
    freopen("input.txt","r",stdin);
    cin>> T;
    for(int tc =1; tc<=3; tc++)
    {
        max=0;
        cin >> n;
        int **grid = new int*[n];
        bool **visited = new bool*[n];
        for(int row =0; row<n; row++)
        {
        //    cout << endl;
                grid[row] = new int[n];
                visited[row] = new bool[n];
                for(int col =0; col < n; col++)
                {
                    
                    cin>> val;
                    grid[row][col] = val;
                    visited[row][col] = false;
    //                cout << " "<< grid[row][col];
                }

        }
    //    cout<<endl;
        getAns(grid,visited,n,max);
       // cout << endl;
        cout << "#"<<tc<<":"<<max<<endl;
    }




    return 0;
}