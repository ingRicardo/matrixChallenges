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

void permutation(int *arrX,int *arrY, int start, int end, int &k,int maxPressure, bool &fend, bool &fstart,
 int &start_indx, int &end_indx, int &fin_press, int &ini_press)
{
    if(start==end)
    {
        //printarray2D(arrX, arrY, end+1);
		int pre =k;
		for(int e=0; e<end+1; e++)
		{
			pre +=  arrX[e] - arrY[e];
			if(pre<0 || pre>maxPressure) // tire was damaged
			{
				pre = -1;
				break;
			}
			if ( (pre == 0 && e == end  && !fend)  ) //found 0 at the end
			{
				fend= true;
			}
			if ( ( pre == 0 && e == 0  && !fstart) ) // found 0 at the start
			{
				fstart= true;
			}
		}//end for
		
		if (fend && pre !=-1 && end_indx ==0) // found 0 at the end , was not damaged and only one time
		{
			end_indx =1;
			fin_press = k;				// get the value to minimize the pressure
		}
		if (fstart && pre !=-1 && start_indx==0) // found 0 at the start , was not dammaged and only one time
		{
			start_indx =1;
			ini_press = k;				// get the value to minimize the pressure
			
		}
		if (ini_press != 0 && fin_press ==0) // initial pressure has value
			res = ini_press;
		else if (fin_press !=0 && ini_press ==0) // final pressure has value
			res = fin_press;
		else if (fin_press !=0 && ini_press !=0 && ini_press != fin_press) // final and start pressure have values and are different
		{
			res = fin_press;
			if (ini_press<fin_press)	// check min value of initial and final pressure
				res = ini_press;
		}
		else if (fin_press !=0 && ini_press !=0 && ini_press == fin_press )  // final pressure is equals to start pressure
		{
			fend = false; fstart= false;	// continue with the next posibility (reset flags)
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
        permutation(arrX, arrY,start+1, end,k,maxPressure, fend, fstart,start_indx, end_indx,fin_press,ini_press);
        swap2D((arrX+i), (arrX+start), (arrY+i), (arrY+start));
    }
}
int main()
{
int T,N,K,inf,def;
bool fstart = false, fend= false;
freopen("input.txt","r",stdin);
cin>> T;

for(int tc =1; tc<=T; ++tc)
{
	res =-1;minPress=500,rr=-1;
	cin>>N;
	cin>>K;
//	cout << N<<endl;
//	cout << K<<endl;
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
	int maxPressure =K,start_indx=0,end_indx=0,ini_press=0,fin_press=0;
	for(int x =K; x>=0; x--)
	{
		//permutation(inflate,deflate, 0, N-1,K,time); 
		permutation(inflate,deflate, 0, N-1,x,maxPressure, fend, fstart,start_indx,end_indx, fin_press,ini_press); 
	}
	
	cout << "#"<<tc<<":"<<res<<endl;
}

return 0;
}
