#include <iostream>
using namespace std;
//https://www.programiz.com/cpp-programming/examples/swapping
//https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/


//Prints the array 
void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
} 

int * swap2(int ar[], int size)
{
    int temp = ar[0]; 
    ar[0] = ar[size-1]; 
    ar[size-1] = temp; 

    return ar;
}

int * swap3(int ar[], int size, int i)
{
    int temp = ar[i]; 
    ar[i] = ar[size-1]; 
    ar[size-1] = temp; 

    return ar;
}

void heapPermutation(int ar[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
        printArr(ar, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(ar,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1)
        {
            ar =swap2(ar, size);
        }    
        // If size is even, swap ith and last 
        // element 
        else
        {
            ar =swap3(ar, size, i);
        }
            
    } 
} 

int main()
{
    int ar[] = {1, 2, 3}; 
    int n = sizeof ar/sizeof ar[0]; 
    heapPermutation(ar, n, n); 
 //   cout << " testin genPermut "<<endl;
    return 0;
}