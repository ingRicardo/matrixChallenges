#include<iostream>
using namespace std;

void printarr(int *arr, int size)
{
    for(int i=0; i< size; ++i)
    {
        cout << " "<< arr[i];
    }
    cout <<endl;
}

int main()
{

    freopen("input.txt","r",stdin);
    int T;
    cin>>T;

    cout << "T "<<T<<endl;
    for (int tc=1; tc<=1; ++tc)
    {

        int subtest;
        cin>> subtest;
        cout << " subtest : "<< subtest<<endl;
        int b1, c1 , d1;
        int *numberb1 = new int[5];
        int bitmp;
        for (int s=1; s<=1; ++s)
        {
            cin>> b1;
            cout << " b1 "<< b1 <<endl;
            bitmp = b1;
            int i=5-1;
            while (bitmp != 0)
            {
                numberb1[i] = bitmp%10;
                bitmp /= 10;
                i-=1;
            }

            printarr(numberb1, 5);
            cin>> c1;
            cout << " c1 "<< c1<<endl;
        
            cin>> d1;
            cout << " d1 "<< d1<<endl;

            cout<<" === "<<endl;
        }
        

    }
    

return 0;
}