
#include <iostream>
using namespace std;

void printArr(int **a,int n) 
{ 
    for (int i=0; i<n; i++) 
        cout <<" "<< a[i][0] << ", "<<a[i][1]<<" "; 
    cout <<endl;
}

int ** swap2(int **ar, int size)
{
     int **temp = new int*[2];
           temp[0][0] = ar[0][0];
           temp[0][1] = ar[0][1];

    ar[0][0] = ar[size-1][0];
    ar[0][1] = ar[size-1][1]; 
    
    ar[size-1][0] = temp[0][0]; 
    ar[size-1][1] = temp[0][1];

    return ar;
}

int ** swap3(int **ar, int size, int i)
{
    int **temp = new int*[2];
    temp[i][0] = ar[i][0];
    temp[i][1] = ar[i][1];
    
    ar[i][0] = ar[size-1][0];
    ar[i][1] = ar[size-1][1]; 
    
    ar[size-1][0] = temp[0][0]; 
    ar[size-1][1] = temp[0][1]; 

    return ar;
}

void fun(int ** blocks_arr, int size, int n)
{

    if (size == 1) 
    { 
        printArr(blocks_arr, n); 
        return; 
    } 
    for(int i=0; i< size; i++)
    {
       // cout << " "<<blocks_arr[i][0] <<", "<<blocks_arr[i][1]<<endl;

        fun(blocks_arr,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1)
        {
            blocks_arr =swap2(blocks_arr, size);
        }    
        // If size is even, swap ith and last 
        // element 
        else
        {
            blocks_arr =swap3(blocks_arr, size, i);
        }



    }
}

int main()
{
    freopen("input.txt","r",stdin);

    int t,size=0,x,y,n=0;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=1; ++tc)
    {

        cin>> size;
        n= size;
        int **blocks_arr = new int*[size];
        for (int b =0; b<size; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            blocks_arr[b][1]=y;

           
        }
        fun(blocks_arr, size, n);
    }



    return 0;
}