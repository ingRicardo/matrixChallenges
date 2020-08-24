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
    */

    for (int j=0; j<size; ++j)
    {
        if( !natural[b1[j]] && number[j] == b1[j] )
        {
            natural[b1[j]] = true;
            c1count+=1;
        }
        
    }
    int i=0;
    do 
    {
        for (int j=0; j<size; ++j)
        {
            if (!natural[b1[j]] && b1[j] == number[i])
            {
                natural[b1[j]] = true;
                d1count+=1;
            }
        }
        i+=1;

    }while(i < size);
    //cout <<"----"<<endl;
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
        //cout << " c1count "<< c1count << " d1count "<< d1count <<endl; 
        if (c1count == c1 && d1count == d1)
        {
            cout << " c1count "<< c1count << " d1count "<< d1count <<endl; 
            printarr(number, size);
            for(int i =0; i< 10; ++i)
            {
               if (natural[i])
                    cout<< " "<< i;
            }

        }

    }


return 0;

}
void gennumb(int n,int *b1, int c1, int d1)
{
    cout << "N "<<n<<" C1 "<<c1 <<" D1 "<<d1<<endl;
    cout << " B1 : "<<endl;
    printarr(b1,5);
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