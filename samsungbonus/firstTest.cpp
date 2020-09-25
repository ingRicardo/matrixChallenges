#include <iostream>
using namespace std;

//function to print the array
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        cout<< " "<< arr[i];
    }
    cout<<endl;
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
int * arr = new int[3];
arr[0] = 4;
arr[1] = 8;
arr[2] = -2;

   //calling permutation function
    permutation(arr, 0, 3-1);
return 0;
}
