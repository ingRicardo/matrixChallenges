
#include <iostream>
using namespace std;

//function to print the array
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

 
//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

 
//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
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
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        for (int b =0; b<size; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            arr1[b] = x;
            blocks_arr[b][1]=y;
            arr2[b] = y;

           
        }
       // fun(blocks_arr, size, n);


       // int arr[] = {1, 2, 3}; 
      //  int s = sizeof arr/sizeof arr[0]; 
         permutation(arr1, 0, size-1);
    }



    return 0;
}