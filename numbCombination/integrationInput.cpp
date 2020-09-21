
#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r", stdin);

    int t;
    cin >> t;
    for(int tc=1; tc<= t; ++tc)
    {
        int st;
        cin >> st;
        cout << " "<< st<<endl;
        int b,c,d;
        for(int i=1; i <=st; ++i)
        {

            cin >> b;cin >> c; cin>>d;
            cout << b << " " << c << " "<< d <<endl;

        }
    

    }

    return 0;
}