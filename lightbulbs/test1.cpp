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

void permut(int *array,int bulbs, int suitch, int swdown, int start, int end)
{
	//if (start == end)
	if (start == 3)
	{
		//printArray(array,bulbs);
		return;
	}
	
	int i;
	for (i=start; i<=end; i++)
	{

		cout << " i "<< i << " start "<< start << " end "<< end<< endl;
		swap( (array+i),(array+start));
		permut(array,bulbs,suitch,swdown,start+1,end);
		swap((array+i),(array+start));
	}


}

void funcTest(int *array,int bulbs, int suitch, int swdown, int start, int end)
{
	permut(array,bulbs, suitch, swdown, start, end);
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
		cin >> bulbs;  cin >>sw;
		cout << " bulbs "<< bulbs<< " switch "<< sw<<endl;
		int *bulbVec = new int [bulbs];
		for (int b=0; b<bulbs; ++b)
		{
			int bulbval;
			cin >> bulbval;
			bulbVec[b] = bulbval;
			
		}
		funcTest(bulbVec,bulbs,sw,swdown,0,bulbs-1);
		cout << endl;
		cout<<"#"<<tc<<":"<<res<<endl; 
	}
	return 0; 
}
