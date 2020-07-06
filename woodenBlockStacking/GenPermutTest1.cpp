
#include <iostream>
using namespace std;
//https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
//function to print the array
int resu=0;
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
 
   //    cout << endl;
    }
    cout << endl;
}

int ** buildMat (int arrX[], int arrY[], int size)
{

    int **mat = new int*[size];

    for(int i=0; i< size; i++)
    {
        mat[i] = new int[2];
        mat[i][0] = arrX[i];
        mat[i][1] = arrY[i];


    }
return mat;
}
int operation (int **mat, int size)
{
    int re =1;
    int i=0;
 //   cout << mat[i][0] << ","<< mat[i][1] ;
    for(int j=1; j< size+1; j++)
    {
        // cout << " "<< mat[i][0] << "," << mat[i][1];
        if (  j < (size) && i < (size+1)  &&  ( ( (mat[i][0] >= mat[j][0]) && (mat[i][1] >= mat[j][1]) ) || 
                ( (mat[i][1] >= mat[j][0]) && (mat[i][0] >= mat[j][1]) )  )  )       
        {
 //          cout << " "<< mat[j][0] << "," << mat[j][1];
            i++;
            re++;
        }
        else
        {
            break;
        }
        
    }
 //  cout <<endl;
return re;
}
void printMat(int **mat, int size)
{
    for(int i=0; i< size; i++)
    {
        cout << " "<< mat[i][0] <<","<< mat[i][1];
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
void permutation(int *arrX,int *arrY, int start, int end)
{
    if(start==end)
    {
       // printarray(arrX, end+1);
        //printarray(arrY, end+1);
        //printarray2D(arrX, arrY, end+1);
        int ** mat = buildMat(arrX,arrY,end+1);
        int re=operation (mat,end+1);
        if (re>resu)
            resu = re;

      //  printMat(mat, end+1);

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
        resu=0;
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

            cout << arrX[b] << ", "<<  arrY[b] ;
            cout<<endl; 
        }
       // fun(blocks_arr, size, n);


       // int arr[] = {1, 2, 3}; 
      //  int s = sizeof arr/sizeof arr[0]; 
     //   if(t != 22)
         permutation(arrX,arrY, 0, size-1);
        
         cout << "#"<<tc << ":"<<resu<<endl;
    }



    return 0;
}