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
  //  cout << "function 2 "<<endl;

    bool **visited = new bool*[size];
    int  **blocks_aux = new int*[size];
    int  *countVect = new int[size];
    int  *insideVect = new int[size];
    for (int b =0; b<size; ++b)
    {
        visited[b] = new bool [2];
        visited[b][0]=false;
        visited[b][1]=false;
        blocks_aux[b] = new int [2];
        blocks_aux[b][0] =blocks_arr[b][0];
        blocks_aux[b][1] =blocks_arr[b][1];
        countVect[b] = 0;
        insideVect[b] = 0;
       // cout << visited[b][0] << ", "<<  visited[b][1];
       // cout<<endl;
    }                
 /*  int restmp =0,inside=0,nomatch=0,max=0,restmp2=0; 
   int cct=0,cct2=0;
    bool ent = false;
    for (int n = 0; n< size ; n++)
    {
        inside =0;
        nomatch =0;
        int r = blocks_arr[n][0];
        int c = blocks_arr[n][1];
        cout << "\ncurrent "<< r << ", "<< c <<endl;
        for(int i=0;i<size;i++)
        {
            if( ((r > blocks_arr[i][0] && c > blocks_arr[i][1])  ||
                (r > blocks_arr[i][0] && c >= blocks_arr[i][1]) ||
                (r >= blocks_arr[i][0] && c > blocks_arr[i][1])) 
                 ) 
            {
                // cout << "normal "<<  blocks_arr[i][0]<< ", "<<  blocks_arr[i][1]<<endl;
                int rr= blocks_arr[i][0];
                int cc = blocks_arr[i][1];
                    cout << "\nSECOND current "<< rr << ", "<< cc <<endl;
                    cct =2;
                    for(int j=0;j<size;j++)
                    {
                        if( ((rr > blocks_arr[j][0] && cc > blocks_arr[j][1]) || (rr > blocks_arr[j][0] && cc >= blocks_arr[j][1]) || (rr >= blocks_arr[j][0] && cc > blocks_arr[j][1]) ) ||
                        ( (rr > blocks_arr[j][1] && cc > blocks_arr[j][0]) || (rr > blocks_arr[j][1] && cc >= blocks_arr[j][0]) || (rr >= blocks_arr[j][1] && cc > blocks_arr[j][0]) )// ||
                              )
                        {
                                cout << "  "<<  blocks_arr[j][0]<< ", "<<  blocks_arr[j][1];
                                cct++;
                        }
                        if (  ( rr ==  blocks_arr[j][1] && cc == blocks_arr[j][0] ) &&  ( rr !=  blocks_arr[j][0] && cc != blocks_arr[j][1])  )
                        {
                            cct++;
                            cout << "\n +1 "<<endl;
                            
                        }
                        if ( ( rr ==  blocks_arr[j][0] && cc == blocks_arr[j][1] ) && i!=j)
                        {
                             cct++;
                             cout << "\n ++1 "<<endl;
                        }
                    }
            }//if
            cout << "\n cct => " << cct << endl;
            if (cct > restmp)
               restmp = cct;
            if (((c > blocks_arr[i][0] && r > blocks_arr[i][1])  ||
                (c > blocks_arr[i][0] && r >= blocks_arr[i][1]) ||
                (c >= blocks_arr[i][0] && r > blocks_arr[i][1])))
                {
                int rr= blocks_arr[i][0];
                int cc = blocks_arr[i][1];
                    cout << "\nSECOND current "<< rr << ", "<< cc <<endl;
                    cct2 =2;
                    for(int j=0;j<size;j++)
                    {
                        if( ((rr > blocks_arr[j][0] && cc > blocks_arr[j][1]) || (rr > blocks_arr[j][0] && cc >= blocks_arr[j][1]) || (rr >= blocks_arr[j][0] && cc > blocks_arr[j][1]) ) ||
                        ( (rr > blocks_arr[j][1] && cc > blocks_arr[j][0]) || (rr > blocks_arr[j][1] && cc >= blocks_arr[j][0]) || (rr >= blocks_arr[j][1] && cc > blocks_arr[j][0]) )// ||
                              )
                        {
                                cout << "  "<<  blocks_arr[j][0]<< ", "<<  blocks_arr[j][1];
                                cct2++;

                        }
                        if (  ( rr ==  blocks_arr[j][1] && cc == blocks_arr[j][0] ) &&  ( rr !=  blocks_arr[j][0] && cc != blocks_arr[j][1])  )
                        {
                            cct2++;
                            cout << "\n +1 "<<endl;
                            
                        }
                        if ( ( rr ==  blocks_arr[j][0] && cc == blocks_arr[j][1] ) && i!=j)
                        {
                             cct2++;
                             cout << "\n ++1 "<<endl;
                        }
                    }             
                }// if 
            cout << "\n cct2 => " << cct2 << endl;
            if (cct2 > restmp2)
               restmp2 = cct2;

        }//2nd for

        
    }
     */   

        int restmp =0,inside=0,nomatch=0,max=0,restmp2=0; 
   int cct=0,cct2=0;
    bool ent = false;
    for (int n = 0; n< size ; n++)
    {
        inside =0;
        nomatch =0;
        int r = blocks_arr[n][0];
        int c = blocks_arr[n][1];
        cout << "\ncurrent "<< r << ", "<< c <<endl;
        for(int i=0;i<size;i++)
        {
            if( ((r > blocks_arr[i][0] && c > blocks_arr[i][1])  ||
                (r > blocks_arr[i][0] && c >= blocks_arr[i][1]) ||
                (r >= blocks_arr[i][0] && c > blocks_arr[i][1])) 
                 ) 
            {
                // cout << "normal "<<  blocks_arr[i][0]<< ", "<<  blocks_arr[i][1]<<endl;
                int rr= blocks_arr[i][0];
                int cc = blocks_arr[i][1];
                    cout << "\nSECOND current "<< rr << ", "<< cc <<endl;
                    cct =0;
                   int tmr=0,tmc=0;
                    for(int j=0;j<size;j++)
                    {
                        if( ((rr > blocks_arr[j][0] && cc > blocks_arr[j][1]) ||
                            (rr > blocks_arr[j][0] && cc >= blocks_arr[j][1]) ||
                            (rr >= blocks_arr[j][0] && cc > blocks_arr[j][1]) )
                              )
                        {
                            //normal
                            cout << "  normal  "<<  blocks_arr[j][0]<< ", "<<  blocks_arr[j][1];
                            tmr = blocks_arr[j][0]; tmc= blocks_arr[j][1];
                            cct++;
                        }
                        if (  ( rr ==  blocks_arr[j][1] && cc == blocks_arr[j][0] ) && 
                              ( rr !=  blocks_arr[j][0] && cc != blocks_arr[j][1])  )
                        {
                            cct++;
                            cout << " equals in rotation  "<<  blocks_arr[j][0]<< ", "<<  blocks_arr[j][1];
                            
                        }
                        if ( ( rr ==  blocks_arr[j][0] && cc == blocks_arr[j][1] ) && i!=j)
                        {
                             cct++;
                             cout << " equals dont know "<<endl;
                        }

                        if (( (rr > blocks_arr[j][1] && cc > blocks_arr[j][0]) || 
                              (rr > blocks_arr[j][1] && cc >= blocks_arr[j][0]) || 
                              (rr >= blocks_arr[j][1] && cc > blocks_arr[j][0]) )  && (tmr !=blocks_arr[j][1] && tmc != blocks_arr[j][0] ) )
                        {

                            //rotation
                            cout << "  rotation  "<<  blocks_arr[j][1]<< ", "<<  blocks_arr[j][0];
                            cct++;
                        }
                    }
            }//if
            cout << "\n cct => " << cct << endl;
            if (cct > restmp)
               restmp = cct;
            /*
            if (((c > blocks_arr[i][0] && r > blocks_arr[i][1])  ||
                (c > blocks_arr[i][0] && r >= blocks_arr[i][1]) ||
                (c >= blocks_arr[i][0] && r > blocks_arr[i][1])))
                {

                    //rotation
                int rr= blocks_arr[i][0];
                int cc = blocks_arr[i][1];
                    cout << "\nSECOND current "<< rr << ", "<< cc <<endl;
                    cct2 =2;
                    for(int j=0;j<size;j++)
                    {
                        if( ((rr > blocks_arr[j][0] && cc > blocks_arr[j][1]) || (rr > blocks_arr[j][0] && cc >= blocks_arr[j][1]) || (rr >= blocks_arr[j][0] && cc > blocks_arr[j][1]) )

                              )
                        {
                            //normal
                                cout << "  "<<  blocks_arr[j][0]<< ", "<<  blocks_arr[j][1];
                                cct2++;

                        }

                        if (  ( (rr > blocks_arr[j][1] && cc > blocks_arr[j][0]) || (rr > blocks_arr[j][1] && cc >= blocks_arr[j][0]) || (rr >= blocks_arr[j][1] && cc > blocks_arr[j][0]) ))
                        {

                            //rotation
                        }

                        if (  ( rr ==  blocks_arr[j][1] && cc == blocks_arr[j][0] ) &&  ( rr !=  blocks_arr[j][0] && cc != blocks_arr[j][1])  )
                        {
                            cct2++;
                            cout << "\n +1 "<<endl;
                            
                        }
                        if ( ( rr ==  blocks_arr[j][0] && cc == blocks_arr[j][1] ) && i!=j)
                        {
                             cct2++;
                             cout << "\n ++1 "<<endl;
                        }
                    }             
                }
                
               // if 
            cout << "\n cct2 => " << cct2 << endl;
            if (cct2 > restmp2)
               restmp2 = cct2;
            */
        }//2nd for

        
    }


        res = restmp;
    
        cout<<endl;

}

int main()
{
    cout <<" wooden block stacking"<<endl;


    freopen("input.txt","r",stdin);

    int t,blocks=0;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=7; ++tc)
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