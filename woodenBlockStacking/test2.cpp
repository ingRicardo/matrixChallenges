#include <iostream>
using namespace std;
int res=0;


void rec(int n, int ** blocks_arr, int size, bool **visited)
{
    if(n >4)
    {
        cout << "return n "<<n<<endl;
        return;
    }
    /*
    int  row = blocks_arr[n][0];
    int  col = blocks_arr[n][1];
    cout << " ------ "<<endl;
    cout << "row " << row<< " col "<< col<<endl;
    int cc =0;
   for(int t= 0; t< size; t++)
   {
        int  nextrow = blocks_arr[t][0];
        int  nextcol = blocks_arr[t][1];
        cout << " nextrow  "<< nextrow << " nextcol "<< nextcol <<endl;
        if ( (row > nextrow && col >nextcol ) || (row > nextcol && col >nextrow) ||
              (row >= nextrow && col >nextcol )  || (row > nextcol && col >= nextrow)  )
        {
            cc+=1;
            cout << "contains -> "<< nextrow << ", "<< nextcol <<endl;
        }
   }
    cout << row << ", "<<col << " contains "<< cc<<endl;*/
    rec(n+1, blocks_arr, size, visited);
}

void func2(int ** blocks_arr, int size)
{

    bool **visited = new bool*[size];

    for (int b =0; b<size; ++b)
    {
        visited[b] = new bool [2];
        visited[b][0]=false;
        visited[b][1]=false;

        cout << visited[b][0] << ", "<<  visited[b][1];
        cout<<endl;
    }                

    //sorting 
   // int max [][] ={}; 
  // int **blocks_tmp = new int*[2];

   for (int p=0; p<= size; p++)
   {
    int r = blocks_arr[p][0];
    int c = blocks_arr[p][1];
    for (int s =p+1; s< size; s++)
    {
        if ( (r >  blocks_arr[s][0] && c >blocks_arr[s][1] ) || (r > blocks_arr[s][1] && c >blocks_arr[s][0]) /*||
                (r >=  blocks_arr[s][0] && c >blocks_arr[s][1]  )  || (r > blocks_arr[s][1] && c >=blocks_arr[s][0])*/  )
            {
                cout << "max ->  "<<r <<","<<c <<endl;
            }
    }
   
   }

    int n =0;
     
    rec(n, blocks_arr, size, visited);

   


    /*bool **visited = new bool *[row];

    for(int r =0; r< row; r++)
    {
        visited[r] = new bool[r];
        for(int c =0; c< col; c++)
        {
            visited[r][c] = false;
            cout << " "<< visited[r][c] ;
        }
        cout<<endl;
    }*/
  
    /*
        2,2<5,5 = 1
        2,2<3,6 = 1
        2,2<3,6<4,7 = 2
        2,2<3,6<4,7<10,8 = 4

    */


}

int main()
{
    cout <<" wooden block stacking"<<endl;


    freopen("input.txt","r",stdin);

    int t,blocks=0;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=1; ++tc)
    {
        cin>> blocks;
        int **blocks_arr = new int*[blocks];
       

        int x,y;
        for (int b =0; b<blocks; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            blocks_arr[b][1]=y;
 
            cout << blocks_arr[b][0] << ", "<<  blocks_arr[b][1];
            cout<<endl;
        }                
        cout<<endl;
        func2(blocks_arr,blocks);

        cout << "#"<<tc<<":"<<res<<endl;
        res =0;

    }


    return 0;
}