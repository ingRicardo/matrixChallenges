
#include <iostream>
using namespace std;
int res=0,minPress=0;;


void swap2D(int *a, int *b, int *c, int *d)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    int temp2;
    temp2 = *c;
    *c = *d;
    *d = temp2;

}

void printarray2D(int arrX[], int arrY[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        cout << "\t"<< arrX[i]<< ", "<<arrY[i] ;
        int curX = arrX[i]; int curY = arrY[i];

   //    cout << endl;
    }
    cout << endl;
}

int operation(int inflate[], int deflate[], int size, int k)
{
    int i,p,minIniPressure=0,tmp=0,tmp2=0,min=10000 ;
	//cout << " size " <<size <<endl; 
	for(p =15; p>0; p--)
	{
		tmp2=0;
		minIniPressure=p;
		for(i=0; i<size; i++)
		{
			//int tmp = p+inflate[i]-deflate[i] ;
		     //minIniPressure =  minIniPressure + inflate[i] - deflate[i]
			//	10+(45)-(55) + (75) -(30) + (80) - (95)
			/*if (i == 0)
			{
				tmp2 += minIniPressure + inflate[i] - deflate[i];	
			}
			else
			{
				//tmp +=  inflate[i];			
				tmp2 +=  inflate[i]  - deflate[i];	 
			}
			*/
			minIniPressure += ( inflate[i] - deflate[i] );
			tmp2 = minIniPressure;
			//	cout <<" "<< p << ","<< tmp2 <<" "<< " i "<< i <<endl;
 
				cout << "tmp2 => "<< tmp2 <<endl;	
		}
cout << endl;
/*
		if(p ==15)
		{
			 
			break;
		}*/
		//cout << "before min "<< min << " tmp2 "<< tmp2<<endl;
		/*if (tmp2 < min)
		{
			min = tmp2;
			minPress =tmp2;
			cout <<" minPress : "<< minPress << ", min : "<< min <<" "<< "  tmp2  "<< tmp2 <<" i "<< i <<endl;
			
		}
			*/
	
		minPress = tmp2;
	}

//	if (tmp2!=0)
//		p=-1;
    cout <<" return the min pressure ==> "<< minPress<<  endl;
	return minPress;
}


int operation2(int inflate[], int deflate[], int size, int k)
{

	int i;
	int ts = k, t=0,r=-1;
	//for(int p=k; p>=0;p--)
	//{ 
		int p=15;
		ts = p;
		cout << " k "<<p<<endl;
		for(i=0; i<size; i++)
		{
		    cout << "\t"<< inflate[i]<< ", "<<deflate[i] ;
			int curX = inflate[i]; int curY = deflate[i];

			ts +=   curX - curY;
			if(ts <0 || ts>k)
			{
				cout << "\n DAMAGED at "<<ts<<endl;
				break;
			}
		//	if (ts == 0   )
		//	{
				r=p;
				cout << "\n min press "<< ts << " at "<< p<< " indx "<< i<< " k "<< k <<endl;
	 

		//	}

		}
	cout <<"\npressure => "<< ts << " i ="<< i<< " r "<< r<< endl;
//}

 
   cout << endl;
	
	return r;
}



void permutation(int *arrX,int *arrY, int start, int end, int k)
{
    if(start==end)
    {
       // printarray(arrX, end+1);
        //printarray(arrY, end+1);
		//cout << " k "<<k<<endl;
       // printarray2D(arrX, arrY, end+1);
	//	cout << "\n minPressure "<< operation(arrX, arrY, end+1, k)<<endl;
		res=operation2(arrX, arrY, end+1, k);
	//	cout << "res "<< res <<endl;
      // int result = buildMat(arrX,arrY,end+1);
	  int result =0;
      //  int re=operation (mat,end+1);
     //   if (result>res)
     //       res = result;

      //  printMat(mat, end+1);

        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
  

        swap2D((arrX+i), (arrX+start), (arrY+i), (arrY+start));

	//	cout << " k "<<k<<endl;
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arrX, arrY,start+1, end,k);
 
        swap2D((arrX+i), (arrX+start), (arrY+i), (arrY+start));
    }
}


int main()
{

	cout << "samsung tire"<<endl;

  /*

	max air pressure k= 100
	initial pressure = 60
	
	inflate = 50  + 60  = 110
	deflate = 40  
	

	inflate = 20
	deflate = 90  

	
	15 + 80 = 95
	95 - 95 = 0

	0 + 75 = 75
	75 - 30 = 45

	45 + 45 = 90
	90 - 55 = 35

	current_pressure = initial_presure
	current_pressure = current_pressure + ( inflate - deflate )
	current_pressure  =  15 + (80 -95) = 15 +(- 15) = 0

	 
	x = x + ( inflate - deflate )
	
	x = initial_pressure = ? 
int start =0, minPressure =0,k=100,N=3;
recursion(start, minPressure, inflate ,  deflate, k , N);
{
	if(k == start || minPressure == 0)
	{

		return;
	}
	for (int p=start; p < N; p++)
	{
		minPressure = k;
		minPressure = minPressure + ( inflate[p] - deflate[p] );
		recursion(start++, minPressure, inflate ,  deflate, k--,N )
	}
	
}

5                                                  // T = 5
3 100                                          // #1, N = 3, K = 100
75 45 80                                    

  */


int T,N,K,inf,def;
freopen("input.txt","r",stdin);

cin>> T;

for(int tc =1; tc<=1; ++tc)
{
	res =0;
	cin>>N;
	cin>>K;
	cout << N<<endl;
	cout << K<<endl;
	int *inflate = new int[N];
	int *deflate = new int[N];

	for(int i =0; i<N; i++)
	{
		cin >> inf;
		inflate[i] = inf;
	}
	for(int i =0; i<N; i++)
	{
		cin >> def;
		deflate[i] = def;
	}
/*
	for(int i =0; i<N; i++)
	{
		cout << inflate[i]<<endl;
		cout << deflate[i]<<endl;
	}
	cout <<endl;*/
	//for (int x =K; x>0; x--)
		permutation(inflate,deflate, 0, N-1,K); 

	cout << "#"<<tc<<":"<<res<<endl;
}



return 0;
}
