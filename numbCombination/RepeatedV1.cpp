#include <iostream>
using namespace std;

int checkDigitEqualsInSamePosition(int n, int m, int totc1, int &pos, bool *visitedPos);
int checkIfDigitApearsInNumberVisPos(int n, int digit, int &pos,bool *visited, int currpos);
int merginFunctionsV2(int start, int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, int currpos);

int main()
{
    
    bool *visitedPos = new bool[5];
    for (int i=0; i<5; i++)
    {
       visitedPos[i] = false;
    }
    int totSamePos =0, pos=4, a = 12312, b=95820 ;
    cout << " a "<< a <<endl << " b "<< b <<endl;
    cout << " total same pos => "<<checkDigitEqualsInSamePosition(a, b, totSamePos,pos,visitedPos)<<endl;
    for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPos[i];
    }
    cout << endl;

    cout << "Testing mergingFunctiosv2.........." <<endl;
    int currpos =4, start=0, digit=0;
    merginFunctionsV2(start, a, digit, b, pos, visitedPos, currpos); 


    return 0;
}

int checkDigitEqualsInSamePosition(int n, int m, int totSamePos, int &pos, bool *visitedPos) {
    if (n == 0 ) {
       return totSamePos;
    } else {
       if ( n%10 == m%10 ) {
          visitedPos[pos] = true;
          totSamePos++;
       } 
           pos-=1;
          return checkDigitEqualsInSamePosition(n/10, m/10,totSamePos, pos, visitedPos);
    }
}


int checkIfDigitApearsInNumberVisPos(int n, int digit,int &pos,bool *visitedPos, int currpos)
{
  if (n == 0) {
       return false;
    } else {
      /*
         m 11432
         n 12433
           10110
      */
     cout << " digit inside "<< digit <<" pos "<<pos<<  " currpos "<< currpos <<endl;
       if (n % 10 == digit && pos != currpos && !visitedPos[pos] && !visitedPos[currpos] ) {
          cout << "Equals == n "<< n << " digit "<< digit << " pos "<< pos << " currpos "<<currpos<<" vistedPos " << visitedPos[pos] <<endl;
          visitedPos[pos] = true;
          visitedPos[currpos] = true;
          return true;
       } else {
          //pos-=1;
          currpos-=1;
          return checkIfDigitApearsInNumberVisPos(n/10, digit, pos, visitedPos, currpos);
       }
    }

}

int merginFunctionsV2(int start, int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, int currpos)
{
   int tmp = 0;
   for (int x=3; x >-1; --x)
   {
      currentNumber = currentNumber/10;
      for (int p=4; p >-1; --p)
      {
        
         digit = currentNumber%10; 

         cout << " merginFunctionsV2 digit "<< digit << " pos "<< p <<endl;
         checkIfDigitApearsInNumberVisPos(variableNumber, digit, p, visitedPos, currpos);

      }
   }
   return 0;
}