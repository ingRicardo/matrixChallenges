#include <iostream>
#include <string>
using namespace std;

void printarr(int *arr, int size)
{
    for(int i=0; i< size; ++i)
    {
        cout << " "<< arr[i];
    }
    cout <<endl;
}
void findStrictlyIncreasingNum(int start, int *array , int n,string out) 
{ 
    // If number becomes N-digit, print it 
    if (n == 0) 
    { 
        cout << out << " "; 
        //cout << " out "<< " n "<< n <<endl;
       // printarr(array,n);
        return; 
    } 
  
    // start from (prev digit + 1) till 9 
    for (int i = start; i <= 9; i++) 
    { 
        // append current digit to number 
        string str = out + to_string(i); 
      
        //array[n] = i;
        //cout << " "<< i <<" n "<< n;
        // recurse for next digit 
        findStrictlyIncreasingNum(i + 1, array, n - 1,str); 
    } 
} 

void gennumb(int n,int *b1, int c1, int d1)
{
     cout << "N "<<n<<" C1 "<<c1 <<" D1 "<<d1<<endl;
     cout << " B1 : "<<endl;
     printarr(b1,5);
    int s = 5;
     findStrictlyIncreasingNum(0, b1, s,""); 
}
void operation(int n, int b1, int c1, int d1)
{
    //cout << "N "<<n<<" B1 "<<b1 << " C1 "<<c1 <<" D1 "<<d1<<endl;
    int bitmp = b1;
    int size =5;
    int *number = new int[bitmp];
    int i=5-1;
    while (bitmp != 0)
    {
        number[i] = bitmp%10;
        bitmp /= 10;
        i-=1;
    }
    gennumb(n,number,c1,d1);

}
int main()
{
    freopen("input.txt","r",stdin);
    int T,N,B1,C1,D1;
    cin >>T;
    for(int tc=1; tc<=1;++tc)
    {
        cin>>N,cin>>B1,cin>>C1,cin>>D1;
        //cout << "N "<<N<<" B1 "<<B1 << " C1 "<<C1 <<" D1 "<<D1<<endl;
        operation( N, B1, C1, D1);

    }
    




    return 0;
}