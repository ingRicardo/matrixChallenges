#include <iostream>
using namespace std;
int res=0,minPress=0, minTest=10000,rr=0;
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
    }
    cout << endl;
}

int operation2(int inflate[], int deflate[], int size, int k)
{
	int i;
	int ts = k, t=0,r=1000;
	for(int p=k; p>=0;p--)
	{ 
		ts = p;
		bool damaged = false, minimized = false;
		for(i=0; i<size; i++)
		{
			int curX = inflate[i]; 
			int curY = deflate[i];

			ts +=   curX - curY;
			if(ts <0 || ts>k)
			{
				damaged = true;
				break;
			}
			if (ts == 0   )
			{
				r=p;
				minimized= true;
			}
		}//end N for
		int test3=0;
		if( !damaged && minimized)
		{
			test3 = ts - 2*p;
		} 
		if(r<minPress)
		{
			minPress=r;
			cout << " minPress "<< minPress<<endl;
		}
		if(test3>0 && test3<minTest)
		{
			minTest=test3;
			rr = p;
		}
	}//end K for
	return minPress;
}


/*

*/
int operation3(int inflate[], int deflate[], int size, int k, int time)
{
	int i,ts = 0, t=0,r=1000;
	bool damaged = false, minimized = false;
	int x =0,locar=0;
	cout << " time => "<<time<<endl;

	for(x =0; x<=k; x++)
	{

		ts =x;
		damaged = false;
		for(i=0; i<size; i++)
		{
			int curX = inflate[i]; 
			int curY = deflate[i];

			ts +=   curX - curY;
		//	cout <<" ts "<< ts<<endl;
			if(ts <0 || ts>k)
			{
				damaged = true;
			//	locar = -1;
				break;
			//	cout << "== Damaged =="<<endl;
				//return minPress;
			}
			else if (ts == 0)
			{
				cout << " minimized x => "<<x <<" index "<< i<<" damaged => "<< damaged <<endl;
			}
		}
	
		

		if(i>=size)
		{
			if(ts >=0 || ts<=k)
			{
				//cout << " "<< ts<<"=>"<<x ;
			}
		}

		if(ts<minPress && !damaged)
		{
			minPress=ts;
			//r=x;
			cout << "\n minPress "<< minPress<<" k "<< k << " x "<< x<<  endl;
		}

	}//end for pressure 0-100 (K)

	return minPress;
}

void permutation(int *arrX,int *arrY, int start, int end, int &k,int &time,int maxPressure, bool &found)
{
    if(start==end)
    {
        //printarray2D(arrX, arrY, end+1);
		time+=1;
		int pre =k,indx=100;
		for(int e=0; e<end+1; e++)
		{
			pre +=  arrX[e] - arrY[e];
			if(pre<0 || pre>maxPressure)
			{
				pre = -1;
				break;
			}

			if (pre == 0 /*&& e == 0*/ && !found )
			{
				found = true;
				indx = e;
			}
		}//end for
		if (pre > 0)
		{
				found = true;
		}
		else
		{
			found = false;
		}
		if (found /*&& indx == 0*/ && indx!=100)
		{
			printarray2D(arrX, arrY, end+1);
			cout << " found "<< found << " pre "<< pre<< " Indx "<< indx<< " currentPressure "<< k<<endl;
			res =k;
		}
        return;
    }// end if
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap2D((arrX+i), (arrX+start), (arrY+i), (arrY+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arrX, arrY,start+1, end,k,time,maxPressure, found);
        swap2D((arrX+i), (arrX+start), (arrY+i), (arrY+start));
    }
}
int main()
{
int T,N,K,inf,def;
bool found = false;
freopen("input.txt","r",stdin);
cin>> T;

for(int tc =1; tc<=3; ++tc)
{
	res =-1;minPress=500,rr=-1;
	int time =0;
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
	int maxPressure =K;
	for(int x =K; x>=0; x--)
	{
		
		//permutation(inflate,deflate, 0, N-1,K,time); 
		permutation(inflate,deflate, 0, N-1,x,time,maxPressure, found); 
	}
	

	cout << "#"<<tc<<":"<<res<<endl;
}

return 0;
}
