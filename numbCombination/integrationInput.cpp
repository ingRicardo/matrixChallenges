
#include <iostream>
using namespace std;

int checkDigitEqualsInDiffPosition(int a, int digit,  int currpos, int pos, bool *&visiteda,bool *&visitedb, int &total_d)
{

   if (a == 0 ) {
       return total_d;
    } else {
        //cout <<"current "<< currentNumber%10 << " currpos "<< currpos <<" isCurrposVisited "<<  visitedPos[currpos]<<endl;
        //cout <<" digit "<< digit << " pos "<< pos <<" isPosVisited "<<  visitedPosV2[pos]<<endl;
        if ( a%10 == digit && !visiteda[pos] && !visitedb[currpos]) {
         
        // cout << " equals " << digit << " pos "<< pos << " currpos "<< currpos<< endl;
         visiteda[pos] = true;
         visitedb[currpos] = true;
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
          visiteda[pos] = true;
          visitedb[pos] = true;
          total_c++;
       } 
           pos-=1;
          return checkDigitEqualsInSamePosition(a/10, b/10,total_c, pos, visiteda, visitedb);
    }
}

void operationArr(int *bi, int *ci, int *di, int size)
{
    bool *visiteda = new bool[size];
    bool *visitedb = new bool[size];
    for(int i=0; i<size; ++i)
    {
        visiteda[i] = false;
        visitedb[i] = false;
    }


    for (int a =10000; a< 100000; ++a)
    {
        bool match = true;
        for(int x =0; x< size; ++x)
        {
            int total_c=0, total_d =0,pos=4; 
            total_c = checkDigitEqualsInSamePosition(a, bi[x], total_c,pos,visiteda,visitedb);
        
            int currpos =4, digit=bi[x];
            //cout << " tota diff pos => "<<merginFunctionsV2( a, digit, b, pos, visitedPos, visitedPosV2, currpos)<<endl; 
            int rem, posVariable=4;
            for (int i = 0; i < size; i++) {
                rem = digit %10;
                digit = digit / 10;
            // cout << rem << " => " <<posVariable << endl;
                total_d = checkDigitEqualsInDiffPosition(a, rem, currpos, posVariable, visiteda,visitedb,total_d);
                posVariable--;
            }

            for(int i=0; i<size; ++i)
            {
                visiteda[i] = false;
                visitedb[i] = false;
            }

            if (total_c == ci[x] && total_d == di[x])
            {  
               continue;
            }
            else
            {
                match = false;
                break;
            }
            
        }
        if(match)
            cout << a <<endl;
        
        

    }




     
}

void operation(int b, int c, int d)
{
    bool *visiteda = new bool[5];
    bool *visitedb = new bool[5];
    for(int i=0; i<5; ++i)
    {
        visiteda[i] = false;
        visitedb[i] = false;
    }
    for (int a =10000; a< 100000; ++a)
    {
        int total_c=0, total_d =0,pos=4; 
        total_c = checkDigitEqualsInSamePosition(a, b, total_c,pos,visiteda,visitedb);
        int currpos =4, digit=b;
        //cout << " tota diff pos => "<<merginFunctionsV2( a, digit, b, pos, visitedPos, visitedPosV2, currpos)<<endl; 
        int rem, posVariable=4;
        for (int i = 0; i < 5; i++) {
            rem = digit %10;
            digit = digit / 10;
           // cout << rem << " => " <<posVariable << endl;
            total_d = checkDigitEqualsInDiffPosition(a, rem, currpos, posVariable, visiteda,visitedb,total_d);
            posVariable--;
        }
        if (total_c == c && total_d == d)
        {   
            cout << b <<endl;
            cout << a <<endl;
            cout << endl<<" total same pos => "<<total_c<< " diff pos -> "<<total_d<< endl;
            for(int i=0; i<5; ++i)
            {
                cout << " "<< visiteda[i] ;
            
            }
            cout<<endl;
            for(int i=0; i<5; ++i)
            {
                cout << " "<< visitedb[i] ;
            
            }
            cout <<endl;
        }
        //cout << "totnum diff pos => "<< total_d <<endl;
        for(int i=0; i<5; ++i)
        {
            visiteda[i] = false;
            visitedb[i] = false;
        }
    }
    /*
    for (int i=0; i<5; i++)
    {
      cout <<" " << visiteda[i];
    }
    cout << endl;
    for (int i=0; i<5; i++)
    {
      cout <<" " << visitedb[i];
    }
    cout << endl;
    */
}
int main()
{
    freopen("input.txt","r", stdin);

    int t;
    cin >> t;
    for(int tc=1; tc<= 1; ++tc)
    {
        int st;
        cin >> st;
        cout << " "<< st<<endl;
        int b,c,d;
        int *bi = new int[st];
        int *ci = new int[st];
        int *di = new int[st];
        for(int i=0; i <st; ++i)
        {
            
            cin >> b;cin >> c; cin>>d;
            bi[i] = b;
            ci[i] = c;
            di[i] = d;
         //   cout << b << " " << c << " "<< d <<endl;
            //operation(b, c,  d);
           
        }
         operationArr(bi, ci, di, st);

    }

    return 0;
}