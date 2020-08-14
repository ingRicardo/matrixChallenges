//https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
#include <iostream>
using namespace std;
int res=0;
void printArray(int arr[], int bulbs)
{
	for(int i=0; i<bulbs; ++i)
	{
		cout <<" "<< arr[i] ;
	}
	cout<<endl;
}

void swap(int *a, int *b)
{
	int temp;
	temp =*a;
	*a = *b;
	*b = temp;

}

void permut(int *arrayBulbs, int *switches, int start, int bulbsSize, int totalBulbsDown, int switchSize)
{
	if (start == switchSize)
	{
		//printArray(switches,swSize);
		int *arrTmp = new int [bulbsSize+1];
		for(int i=0; i<bulbsSize+1; i++)
		{
			arrTmp[i] = arrayBulbs[i]; 
		}
		for (int s=0; s < 3; ++s) // attempts
		{
			totalBulbsDown=0;
			for (int  i =switches[s]-1 , j =0 ; j < bulbsSize+1; i+=switches[s]+1, j++)
        	{
				if( i < bulbsSize+1 && arrTmp[i] == 1 )
				{
					arrTmp[i] = 0;
				}
				else if (i < bulbsSize+1 && arrTmp[i] == 0 )
				{
					arrTmp[i] = 1;
				}
				
				if( !arrTmp[j])
				{
					totalBulbsDown+=1;
				}
				
			}
			if ( totalBulbsDown > res)
            	res = totalBulbsDown;
			
		} 
				
		return;
	}
	
	int i;
	for (i=start; i<switchSize; i++)
	{
		swap( (switches+i),(switches+start));
		permut(arrayBulbs,switches,start+1,bulbsSize, totalBulbsDown,switchSize);
		swap((switches+i),(switches+start));
	}

}

void funcTest(int *arrayBulbs, int switchSize, int start, int bulbsSize, int totalBulbsDown)
{
	int *switches = new int[switchSize];
	int val=1;
	for (int s=0; s< switchSize; ++s,val++)
	{
		switches[s] = val;
	}
	permut(arrayBulbs,switches, start, bulbsSize, totalBulbsDown, switchSize);
}
int main()
{
	freopen("input.txt","r",stdin);
	int t,totalBulbsDown;
	cin>>t;
	for (int tc=1; tc<=t; ++tc)
	{
		int bulbs,switchSize;
		totalBulbsDown=10000;
		res=0;
		cin >> bulbs;  cin >>switchSize;
		int *bulbVec = new int [bulbs];
		for (int b=0; b<bulbs; ++b)
		{
			int bulbval;
			cin >> bulbval;
			bulbVec[b] = bulbval;
			
		}
		funcTest(bulbVec,switchSize,0,bulbs-1,totalBulbsDown);
		cout<<"#"<<tc<<":"<<res<<endl; 
	}
	return 0; 
}
