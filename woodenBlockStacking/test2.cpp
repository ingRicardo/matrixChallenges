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
/*   res =0;
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
                    cout <<" CONTAINS -> "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] << " res ++ "<< res<< endl;
                    contain++;
            }
            else if((r != blocks_arr[i][0] && c != blocks_arr[i][1]) /*||(r != blocks_arr[i][1] && c != blocks_arr[i][0])*//* )
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
    }*/
    /*
    int rotr;
    int rotc;
    res=0;
    for (int rot = 0; rot< 2; rot++)
    {
        if (rot ==0)
        {
            rotr = 0;
            rotc = 1 ;
        }
        else if (rot == 1)
        {
            rotr = 1;
            rotc = 0 ;
        }
        for (int n = 0; n< size ; n++)
        {
            int r = blocks_arr[n][rotr];
            int c = blocks_arr[n][rotc];
            int inside =0, contain =0,notmatch=0,resu=1;

            if (rotr == 0 && rotc == 1)
            {
            // normal
                cout << "--- current  normal "<< r << ", "<< c <<endl;
            }
            else 
            {
           // rotation
                cout << "--- current  rotation "<< r << ", "<< c <<endl;
            }
            for(int i=0;i<size;i++)
            {
                    if( (r > blocks_arr[i][0] && c > blocks_arr[i][1]) || 
                       (r >= blocks_arr[i][0] && c > blocks_arr[i][1]) ||
                       (r > blocks_arr[i][0] && c >= blocks_arr[i][1]) )
                    { 
                        cout <<"contains : "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                    }
                    else if( (r < blocks_arr[i][0] && c < blocks_arr[i][1]) || 
                       (r <= blocks_arr[i][0] && c < blocks_arr[i][1]) ||
                       (r < blocks_arr[i][0] && c <= blocks_arr[i][1]) )
                    { 
                        cout <<"inside of "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                    }
                    else if((r != blocks_arr[i][0] && c != blocks_arr[i][1]) &&
                            (c != blocks_arr[i][0] && r != blocks_arr[i][1])  )
                    {
                        cout <<" NOT MATCH -> "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] <<endl;
                        countVect[i] +=1;
                    }
                //rotation
                 //   cout << "current rotation "<< c << ", "<< r <<endl;
            }
        }
        cout << " ------- "<<endl;
    } // main for
        int exclude = countVect[0];
        int indx =0;
        for (int co =1; co <= size; co++)
        {
            cout << " "<< countVect[co] ;
            if(countVect[co] > exclude  )
            {
                exclude = countVect[co];
                indx = co;
            }
        }
        if (exclude>0)
        {
            cout << "\nexlude this frecuency -> "<< exclude<< " index -> "<< indx<< " block "<< blocks_arr[indx][0]<<", "<<blocks_arr[indx][1]<<endl;
            cout << endl;
            for (int e =0; e<size; e++)
            {
                
                if (blocks_arr[e][0] != blocks_arr[indx][0] && blocks_arr[e][1] != blocks_arr[indx][1])
                    res+=1;
            }
        }
        else 
            res = size;

    cout <<endl;
    */

   /*
2 2
5 5
7 4
3 6
10 8

*/
/*
    for (int n = 0; n< size ; n++)
    {
        int r = blocks_arr[n][0];
        int c = blocks_arr[n][1];
        int inside =0, contain =0,notmatch=0,resu=1;
        cout << "current "<< r << ", "<< c <<endl;
        for(int i=0;i<size;i++)
        {
                if((r > blocks_arr[i][0] && c > blocks_arr[i][1]) ||(r > blocks_arr[i][1] && c > blocks_arr[i][0]) )
                {
                        // normal - rotation 
                        //contain++;
                        cout <<" con -- "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] ;
                        countVect[n] = countVect[n] +1; 
                }
                else if((r < blocks_arr[i][0] && c < blocks_arr[i][1]) ||(r < blocks_arr[i][1] && c < blocks_arr[i][0]) )
                {
                    insideVect[n] = insideVect[n] + 1;
                    cout <<" in -- "<< blocks_arr[i][0] << ", "<< blocks_arr[i][1] ;
                }

        }
        cout << "\n contains "<< countVect[n]<<endl;
        cout << "\n inside "<< insideVect[n]<<endl;
    } 


    // IF "INSIDE" IS EQUALS TO SOME OTHER ONE 
    //  CHECK WHO HAS THE MAXIMUN "CONTAIN"
   int i, j, rep=10000;
    printf(" Repeating elements are "); 
    for(i = 0; i < size; i++) 
        for(j = i + 1; j < size; j++) 
        if(insideVect[i] == insideVect[j]) 
        {
             rep = insideVect[i];
            cout << rep << " "; 
           
        }

        
    cout << " rep : "<< rep<<endl;     
    cout <<endl;

    int de= 100000;
    //check min contain
    cout << " min contain : "<<endl;
    int no =10000;
    for(i = 0; i < size; i++) 
    {
        if(insideVect[i] == rep) 
        {
        if (countVect[i]< de)
        {
            de = countVect[i];
            cout <<" "<< countVect[i]<< " -> "<< blocks_arr[i][0]<< ", "<< blocks_arr[i][1]<< " idx "<< i<<endl;
            no = i;
        }
            
        
        }
    }
    cout << " no "<<no <<endl;
    cout << "\n res : "<<endl; 
    int r=0;
 
     for(int u = 0; u < size; u++) 
    {
         if ( u != no)
         {
             cout << " "<< blocks_arr[u][0] << ", "<< blocks_arr[u][1] <<endl;
             r++;
         }
    }
    res = r;
    cout <<endl;

    */

  // int ** blocks_arr, int size
  /*
    int restmp =0,inside=0,nomatch=0,max=0; 

    for (int n = 0; n< size ; n++)
    {
        restmp =0;
        inside =0;
        nomatch =0;
        int r = blocks_arr[n][0];
        int c = blocks_arr[n][1];
        cout << "current "<< r << ", "<< c <<endl;
        for(int i=0;i<size;i++)
        {

                if( (r >= blocks_arr[i][0] && c >= blocks_arr[i][1]) ||
                    (c >= blocks_arr[i][0] && r >= blocks_arr[i][1]) 
                    
                    ) 

                {
                 //    cout << "  "<<blocks_arr[i][0] << ", "<< blocks_arr[i][1];
                    restmp++;
                    
                }

                else if ( ( (r <= blocks_arr[i][0] && c <= blocks_arr[i][1]) ||
                    (c <= blocks_arr[i][0] && r <= blocks_arr[i][1]) 
                    
                    ) ) 
                    {
                     //   cout << "\n --- inside of  "<<blocks_arr[i][0] << ", "<< blocks_arr[i][1]<<endl;
                        inside++;
                    }
                else if ( ( (r != blocks_arr[i][0] && c != blocks_arr[i][1]) ||
                    (c != blocks_arr[i][0] && r != blocks_arr[i][1]) ))
                    {
                     //   cout << "\n --- no match "<<blocks_arr[i][0] << ", "<< blocks_arr[i][1]<<endl;
                        nomatch++;
                    }
                    
        }
        cout << "\n --- contains "<< restmp <<" inside "<< inside << " nomatch "<< nomatch << endl;
        if (restmp>max)
            max = restmp;
        else if (max == restmp)
            max++;

        
        cout << "MAX -> "<< max<<endl;
    }
    res = restmp;
    */

   int restmp =0,inside=0,nomatch=0,max=0; 
  int cct=0;
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
            if( (r > blocks_arr[i][0] && c > blocks_arr[i][1])  ||
                (r > blocks_arr[i][0] && c >= blocks_arr[i][1]) ||
                (r >= blocks_arr[i][0] && c > blocks_arr[i][1]) ) 
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
                           /* (rr ==  blocks_arr[i][1] && cc == blocks_arr[i][0]) */    )
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

                        if ( ( rr >  blocks_arr[j][1] && cc > blocks_arr[j][0] ) )
                        {
                            // cct++;
                            // cout << "\n ++1 "<<endl;
                            // check the rotation 
                            cout << " rot "<<endl;
                        }


                    }
                    cout<<"\n cct => "<< cct<<endl;
                    if(cct>restmp)
                        restmp = cct;


            }



                            /*
                            int rr= blocks_arr[i][0];
                            int cc = blocks_arr[i][1];
                            if (r!=rr && c !=cc)
                            {
                                cout << "\nSECOND current "<< rr << ", "<< cc <<endl;
                                cct=1;
                              
                                for(int i=0;i<size;i++)
                                {
                                    if( (rr >= blocks_arr[i][0] && cc >= blocks_arr[i][1]) ||
                                    (cc >= blocks_arr[i][0] && rr >= blocks_arr[i][1])                                               
                                        ) 
                                        { 

                                                    ent = true;
                                                    if (rr == blocks_arr[i][0] && cc == blocks_arr[i][1])
                                                    {

                                                    }                                                        
                                                    else
                                                    {
                                                        cct++;                                                  
                                                        cout << "  "<<blocks_arr[i][0] << ", "<< blocks_arr[i][1];
                                                        
                                                    }
                                                    
         
                                                
                                        }       
                                }  //end for  
                                //cct+=2;
                              
                                if (cct >=  restmp)
                                {
                                    restmp =cct;
                                }

                            }*/
                //}

                    
        }
     //   cout << "\n --- contains "<< restmp<<endl;
 
        
 
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