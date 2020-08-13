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

void permut(int *array,int bulbs, int *switches, int swdown, int start, int end, int totalBulbs, int swSize)
{
	//if (start == end)
	if (start == swSize)
	{
		//printArray(switches,swSize);

		int *arrTmp = new int [end+1];
		for(int i=0; i<end+1; i++)
		{
			arrTmp[i] = array[i]; 
		}
	//	cout << "original :"<<endl;
	//	printArray(arrTmp,end+1);
		for (int s=0; s < 3; ++s) // attempts
		{
			totalBulbs=0;
			for (int  i =switches[s]-1 , j =0 ; j < end+1; i+=switches[s]+1, j++)
        	{
				//cout << " i "<< i <<endl;
				
				if( i < end+1 && arrTmp[i] == 1 )
				{
					arrTmp[i] = 0;
				}
				else if (i < end+1 && arrTmp[i] == 0 )
				{
					arrTmp[i] = 1;
				}
				
				if( !arrTmp[j])
				{
					totalBulbs+=1;
				}
				
			}
		//	cout << " s "<<s<<endl;
		//	printArray(arrTmp,end+1);
		//	cout << " totalBulbs "<< totalBulbs<<endl;
			if ( totalBulbs > res)
            	res = totalBulbs;
			
		} 
		
		
		return;
	}
	
	int i;
	//for (i=start; i<=end; i++)
	for (i=start; i<swSize; i++)
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
	int val=1;
	//cout << "initial switches "<<endl;
	for (int s=0; s< suitch; ++s)
	{
		switches[s] = val;
		val++;
	//	cout << " "<< switches[s]; 
	}
//	cout <<endl;
//	cout <<endl;

	permut(array,bulbs, switches, swdown, start, end, totalBulbs, suitch);
}
int main()
{
	//cout <<"test"<<endl;

	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	//cout <<" t "<< t<<endl;
	for (int tc=1; tc<=t; ++tc)
	{
		int bulbs,sw,swdown;
		int totalBulbs=10000;
		res=0;
		cin >> bulbs;  cin >>sw;
	//	cout << " bulbs "<< bulbs<< " switch "<< sw<<endl;
		int *bulbVec = new int [bulbs];
		for (int b=0; b<bulbs; ++b)
		{
			int bulbval;
			cin >> bulbval;
			bulbVec[b] = bulbval;
			
		}
		funcTest(bulbVec,bulbs,sw,swdown,0,bulbs-1,totalBulbs);
	//	cout << endl;
		cout<<"#"<<tc<<":"<<res<<endl; 
	}
	return 0; 
}
