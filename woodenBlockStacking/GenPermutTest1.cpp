
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

void printarray2D(int arrX[], int arrY[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        cout << "\t"<< arrX[i]<< ", "<<arrY[i] ;
        int curX = arrX[i]; int curY = arrY[i];
        for(j=0; j<size; j++)
        {
            if(j!=i)
            {
               // cout << "\t ("<< arrY[j]<< ", "<< arrX[j]<<")";
                 
            }
        }
   //    cout << endl;
    }
    cout << endl;
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
void permutation(int *arrX,int *arrY, int start, int end)
{
    if(start==end)
    {
       // printarray(arrX, end+1);
        //printarray(arrY, end+1);
        printarray2D(arrX, arrY, end+1);
      
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arrX+i), (arrX+start));
        swap((arrY+i), (arrY+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arrX, arrY,start+1, end);
        swap((arrX+i), (arrX+start));
        swap((arrY+i), (arrY+start));
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
        int *arrX = new int[size];
        int *arrY = new int[size];
        for (int b =0; b<size; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            arrX[b] = x;
            blocks_arr[b][1]=y;
            arrY[b] = y;

           
        }
       // fun(blocks_arr, size, n);


       // int arr[] = {1, 2, 3}; 
      //  int s = sizeof arr/sizeof arr[0]; 
         permutation(arrX,arrY, 0, size-1);
    }



    return 0;
}