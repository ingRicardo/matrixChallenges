#include <iostream>
using namespace std;

int checkDigitEqualsInDiffPosition(int a, int digit,  int currpos, int pos, bool *&visiteda,bool *&visitedb, int &total_d)
{
   if (a == 0 ) {
       return total_d;
    } else {
        if ( a%10 == digit && !visiteda[pos] && !visitedb[currpos]) {
            visiteda[pos] = true; visitedb[currpos] = true;
            total_d++;
       } 
          currpos-=1;
          return  checkDigitEqualsInDiffPosition(a/10, digit,  currpos, pos, visiteda, visitedb, total_d);
    }
}

int checkDigitEqualsInSamePosition(int a, int b, int &total_c, int &pos, bool *&visiteda, bool *&visitedb) {
    if (a == 0 ) {
       return total_c;
    } else {
       if ( a%10 == b%10 ) {
          visiteda[pos] = true; visitedb[pos] = true;
          total_c++;
       } 
           pos-=1;
          return checkDigitEqualsInSamePosition(a/10, b/10,total_c, pos, visiteda, visitedb);
    }
}

int operationArr(int *bi, int *ci, int *di, int size)
{
    bool *visiteda = new bool[5], *visitedb = new bool[5];
    for(int i=0; i<5; ++i)
    {
        visiteda[i] = false; visitedb[i] = false;
    }
    int res=0, total_c=0, total_d =0,pos=0, currpos =0, digit=0,rem=0;
    bool match;
    for (int a =10000; a< 100000; ++a)
    {
        match = true;
        for(int x =0; x< size; ++x)
        {
            total_c=0, total_d =0,pos=4, currpos =4, digit=bi[x],rem=0;
            total_c = checkDigitEqualsInSamePosition(a, bi[x], total_c,pos,visiteda,visitedb);
            for (int i = 0,posVariable=4; i < 5; i++, posVariable--) {
                rem = digit %10;
                digit = digit / 10;
                total_d = checkDigitEqualsInDiffPosition(a, rem, currpos, posVariable, visiteda,visitedb,total_d);
            }
            for(int i=0; i<5; ++i)
            {
                visiteda[i] = false; visitedb[i] = false;
            }
            if (total_c == ci[x] && total_d == di[x]){  continue; }
            else { match = false; break;}
        }
        if(match){ res++; /* cout << a <<endl;*/}
    }
    return res;
}

int main()
{
    freopen("input.txt","r", stdin);
    int t;
    cin >> t;
    for(int tc=1; tc<= t; ++tc)
    {
        int st,res, b,c,d;
        cin >> st;
        int *bi = new int[st], *ci = new int[st], *di = new int[st];
        for(int i=0; i <st; ++i)
        {
            cin >> b;cin >> c; cin>>d;
            bi[i] = b;ci[i] = c;di[i] = d;
        }
         res=operationArr(bi, ci, di, st);
         cout << "#"<<tc<<":"<<res<<endl;
    }

    return 0;
}