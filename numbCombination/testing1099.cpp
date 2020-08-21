#include <iostream>
using namespace std;

void printarr(int *arr, int size)
{
    for(int i=0; i< size; ++i)
    {
        cout << " "<< arr[i];
    }
    cout <<endl;
}

int bruteForce2()
{
    cout << "bruteForce2 "<<endl;
    int bitmp,size =5,i;
    int *number;
    for(int x = 10000; x < 100000; ++x)
    {
        bitmp = x; i=5-1;
        number = new int[size];
        while (bitmp != 0)
        {
            number[i] = bitmp%10;
            bitmp /= 10;            
            i-=1;
        }
        printarr(number, size);
}
    
    
    
    


return 0;
}


int main()
{
    int *bi = new int[5];
    /*  int bi = 33516;
    bi[0] = 3;
    bi[1] = 3;
    bi[2] = 5;
    bi[3] = 1;
    bi[4] = 6;
    */

//brute force
    int *array = new int[5];
  
    for(int i =1; i <= 9 ; ++i)
    {
        for(int j =0; j <= 9 ; ++j)
        { 
            for(int k =0; k <= 9 ; ++k)
            {
                for(int l =0; l <= 9 ; ++l)
                {
                    for(int m =0; m <= 9 ; ++m)
                    {
                        array[0] = i; 
                        array[1] = j;
                        array[2] = k;
                        array[3] = l; 
                        array[4] = m; 
                        for (int s=0; s< 5; ++s)
                        {
    //                        cout << array[s];

                        }
      //                  cout <<endl;
                    }
                }
            }
        }
    }

    bruteForce2();
    return 0;
}

