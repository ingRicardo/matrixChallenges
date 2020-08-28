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
//http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs3343/lecture25.html
//https://www.mathplanet.com/education/algebra-2/discrete-mathematics-and-probability/permutations-and-combinations
void testCompare(int *number, int *b1, int c1, int d1, int size , 
                bool * &natural, int &c1count, int &d1count)
{

    //printarr(number, size);
    //printarr(b1, size);

    /*
    bi 33516
    A  13456

    3x51x
    1x45x

    3x51x
    1x45x

    18211
    ------
    31728
    31782
    31820

    ci=0;di=3
    XXX11
    3X7XX

    18211
    31728

    1 == 3
        X
    8 == 1
        X
    2 == 7
        X
    1 == 2
        X
    1 == 8
        X




    1 == 3
        X
    1 == 1
        YES
        X8211
        3X728
    8 == 3
        X
    8 == 7
        X
    8 == 2
        X
    8 == 8
        YES
        XX211
        3X72X
    2 == 3
        X
    2 == 7
        X
    2 == 2
        YES
        XXX11
        3X7XX
    1 == 3
        X
    1 == 7
        X
    1 == 3
        X
    1 == 7
        X


    ci=0;di=3
    XXX11
    3X7XX

    ci=0;di=3
    XXX11
    3XXX0

    */

  int *numtmp =  new int [size]; 
  for (int p =0; p<size; ++p)
  {
      numtmp[p] = number[p];
  }
  int *b1tmp =  new int[size];
  for (int p =0; p<size; ++p)
  {
      b1tmp[p] = b1[p];
  }

  int * naturaln = new int[10];
  for (int p =0; p<10; ++p)
  {
      naturaln[p] = p;
  }

  bool * visited = new bool[10];
  for (int p =0; p<10; ++p)
  {
     visited[p] = false;
  }

  int i=0, j=0;
    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if(numtmp[i]==b1tmp[j]  && !visited[numtmp[i]] )
            {

                if (j==i )
                {
                    c1count++;
                 //   numtmp[j] = 99;
                 //   b1tmp[j] = 99;
                    visited[numtmp[i]] = true;
                    
                }
                /*else if ( i != j && !position[j])
                {
                    position[j] = true;
                    d1count++;
                }
                */
            }

        }
    }
    for (int y =0 ; y < size; ++y)
    {
        int ini = b1tmp[y];
        for (int x =0 ; x < size; ++x)
        {
            if (numtmp[x] == ini && x != y  && !visited[numtmp[x]] && !visited[ini] )
            {
                //numtmp[x] = 99;
               // b1tmp[x] = 99;
               // cout << " "<< ini;
                d1count++;
                visited[numtmp[x]] = true;
                visited[ini] = true;
                
            }
        }
    }

        if (d1count == d1 && c1count == c1)
        {
            cout << " c1 count "<< c1count << " d1 count "<<d1count<<endl;
            printarr(numtmp, size);
            printarr(b1tmp, size);

        }


}

int bruteForce2(int *b1, int c1, int d1)
{
    cout << "bruteForce2 "<<endl;
    int bitmp,size =5,i;
    int *number;
    int c1count=0,d1count=0;

    for(int x = 10000; x < 100000; ++x)
    {
        c1count=0;d1count=0;
        bool *natural = new bool[10];
        for(int n=0; n< 10; ++n)
        {
            natural[n] = false;
        }

        bitmp = x; i=5-1;
        number = new int[size];
        while (bitmp != 0)
        {
            number[i] = bitmp%10;
            bitmp /= 10;            
            i-=1;
        }
        //create another array of numbers 
        testCompare(number,b1,c1,d1,size, natural, c1count, d1count);

            
    }


return 0;

}
void gennumb(int n,int *b1, int c1, int d1)
{
    cout << "N "<<n<<" C1 "<<c1 <<" D1 "<<d1<<endl;
    cout << " B1 : "<<endl;
    printarr(b1,5);
    cout << "------"<<endl;
    int s = 5;
    bruteForce2(b1, c1, d1);
     //findStrictlyIncreasingNum(0, b1, s-1,""); 
}
void operation(int n, int b1, int c1, int d1)
{
    //cout << "N "<<n<<" B1 "<<b1 << " C1 "<<c1 <<" D1 "<<d1<<endl;
    int bitmp = b1;
    int size =5;
    int *numberb1 = new int[bitmp];
    int i=5-1;
    while (bitmp != 0)
    {
        numberb1[i] = bitmp%10;
        bitmp /= 10;
        i-=1;
    }
    gennumb(n,numberb1,c1,d1);

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