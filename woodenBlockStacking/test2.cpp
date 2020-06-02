#include <iostream>
using namespace std;
int res=0;


void rec(int n, int ** blocks_arr, int size, int nextRow, int nextCol,int &cc)
{
    if(n >=(size-1))
    {
        cout << "return n "<<n<<endl;
        return;
    }
    int r = nextRow;
    int c = nextCol;
    cout << " current -> "<< r << ", "<<c <<endl;
    if ( (r> blocks_arr[n+1][0] && c > blocks_arr[n+1][1])  || 
        (r>= blocks_arr[n+1][0] && c > blocks_arr[n+1][1]) ||
        (r> blocks_arr[n+1][0] && c >= blocks_arr[n+1][1]) ||
        (r>= blocks_arr[n+1][0] && c >= blocks_arr[n+1][1]) )
    {
        cout << "normal "<<blocks_arr[n+1][0] << ", "<< blocks_arr[n+1][1]<<endl;
        nextRow = blocks_arr[n+1][0]; nextCol = blocks_arr[n+1][1];
        cc+=1;
    }
    else if ( ( r > blocks_arr[n+1][1] && c > blocks_arr[n+1][0] )  ||
            ( r >= blocks_arr[n+1][1] && c > blocks_arr[n+1][0] )  ||
            ( r > blocks_arr[n+1][1] && c >= blocks_arr[n+1][0] ) ||
            ( r >= blocks_arr[n+1][1] && c >= blocks_arr[n+1][0] )
      )
    {
        cout << "rotation "<<blocks_arr[n+1][1]<<", "<<  blocks_arr[n+1][0]<<endl;
        nextRow = blocks_arr[n+1][1];nextCol = blocks_arr[n+1][0];
        cc+=1;

    }
    
    rec(n+1, blocks_arr, size, nextRow, nextCol,cc);
}

void func2(int ** blocks_arr, int size)
{
    cout << "function 2 "<<endl;

    bool **visited = new bool*[size];
    int  **blocks_aux = new int*[size];
    for (int b =0; b<size; ++b)
    {
        visited[b] = new bool [2];
        visited[b][0]=false;
        visited[b][1]=false;
        blocks_aux[b] = new int [2];
        blocks_aux[b][0] =blocks_arr[b][0];
        blocks_aux[b][1] =blocks_arr[b][1];
        cout << visited[b][0] << ", "<<  visited[b][1];
        cout<<endl;
    }                
    //sorting 
   // int max [][] ={}; 
  // int **blocks_tmp = new int*[2];
/*
    int n =0;
    int r = blocks_arr[n][0];
    int c = blocks_arr[n][1];

    for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if( ( blocks_arr[i][0] < blocks_arr[j][0] && blocks_arr[i][1] < blocks_arr[j][1] ))
			{
				r  =blocks_arr[i][0];
                c = blocks_arr[i][1];

				blocks_arr[i][0]=blocks_arr[j][0];
                blocks_arr[i][1]=blocks_arr[j][1];
				blocks_arr[j][0]=r;
                blocks_arr[j][1]=c;
			}
		}
	}
	//print sorted array elements
	cout<<"Sorted (Descending Order) Array elements:"<<endl;
	for(int i=0;i<size;i++)
		cout<<blocks_arr[i][0]<<", "<< blocks_arr[i][1] << "\t";
	cout<<endl;	
    int cc =1;
    rec(n, blocks_arr, size, blocks_arr[n][0],blocks_arr[n][1],cc);
    res = cc;
    cout << "res ------> "<<res <<endl;*/
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
   res =0;
   int nextRow = 0, notRow=0;
   int nextCol = 0, notCol=0;
   int maxNotMatch =0;
    //int 
    for (int n = 0; n< size ; n++)
    {
        int r = blocks_arr[n][0];
        int c = blocks_arr[n][1];
        int inside =0, contain =0,notmatch=0,resu=1;

        cout << "current "<< r << ", "<< c <<endl;
        for(int i=0;i<size;i++)
        {
            if((r < blocks_arr[i][0] && c < blocks_arr[i][1]) ||(r < blocks_arr[i][1] && c < blocks_arr[i][0]) )
            {
                cout <<" iNSIDE OF -> "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                nextRow = blocks_arr[i][0]; nextCol =  blocks_arr[i][1];
                // implentation of the blocks_aux loop to compare with the next
                inside++;
  
                
            }
            else  if((r >= blocks_arr[i][0] && c > blocks_arr[i][1]) ||
                     (r > blocks_arr[i][1] && c >= blocks_arr[i][0]) )
            {
                if (blocks_arr[i][0] != notRow && blocks_arr[i][1] != notCol)
                {
                    cout << "RES -> "<< blocks_arr[i][0] << ", "<<blocks_arr[i][1] <<endl; 
                    resu++;
                    if(res < resu)
                        res = resu;
                }
                    cout <<" CONTAINS -> "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                    contain++;
            }
            else if((r != blocks_arr[i][0] && c != blocks_arr[i][1]) /*||(r != blocks_arr[i][1] && c != blocks_arr[i][0])*/ )
            {
                 cout <<" NOT MATCH -> "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                notmatch++;
            }
            
        }
        if(notmatch > maxNotMatch)
        {
            notRow = r;
            notCol = c;
            maxNotMatch = notmatch;

        }
            

        cout << "total inside "<< inside << " AND total contains "<< contain<<" notmatch "<< notmatch<< " MAX NOT MATCH "<< notRow<<", "<<notCol;
        cout << " res "<< resu <<endl;
     
           
        
    }

}

int main()
{
    cout <<" wooden block stacking"<<endl;


    freopen("input.txt","r",stdin);

    int t,blocks=0;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=5; ++tc)
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
       

    }


    return 0;
}