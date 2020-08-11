//https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
#include <iostream>
using namespace std;
int res=10000;
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

void permut(int *array,int bulbs, int *switches, int swdown, int start, int end, int totalBulbs, int swSize)
{
	//if (start == end)
	if (start == end)
	{
		//printArray(switches,swSize);

		for (int s=0; s < 3; ++s)
		{
			for (int  i =switches[s] , j =0 ; j < end; i+=switches[s], j++)
        	{
				if(array[i])
				{
					array[i] = !array[i];
				}
				else
				{
					array[i] = array[i];
				}
				if( array[j] == 0)
				{
					totalBulbs+=1;
				}
			}
			if ( totalBulbs < res)
            	res = totalBulbs;

		}
		return;
	}
	
	int i;
	for (i=start; i<=end; i++)
	{

		//cout << " i "<< i << " start "<< start << " end "<< end<< endl;
		swap( (switches+i),(switches+start));
		permut(array,bulbs,switches,swdown,start+1,end, totalBulbs,swSize);
		swap((switches+i),(switches+start));
	}


}

void funcTest(int *array,int bulbs, int suitch, int swdown, int start, int end, int totalBulbs)
{
	int *switches = new int[suitch];
	for (int s=0; s< suitch; ++s)
	{
		switches[s] = s;
	}
	permut(array,bulbs, switches, swdown, start, end, totalBulbs, suitch);
}
int main()
{
	cout <<"test"<<endl;

	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	cout <<" t "<< t<<endl;
	for (int tc=1; tc<=1; ++tc)
	{
		int bulbs,sw,swdown;
		int totalBulbs=0;
		cin >> bulbs;  cin >>sw;
		cout << " bulbs "<< bulbs<< " switch "<< sw<<endl;
		int *bulbVec = new int [bulbs];
		for (int b=0; b<bulbs; ++b)
		{
			int bulbval;
			cin >> bulbval;
			bulbVec[b] = bulbval;
			
		}
		funcTest(bulbVec,bulbs,sw,swdown,0,bulbs-1,totalBulbs);
		cout << endl;
		cout<<"#"<<tc<<":"<<res<<endl; 
	}
	return 0; 
}
