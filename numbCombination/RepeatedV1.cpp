#include <iostream>
using namespace std;

int checkDigitEqualsInSamePosition(int n, int m, int totc1, int &pos, bool *visitedPos, bool *visitedPosV2);
int checkIfDigitApearsInNumberVisPos(int totDiffPos, int n, int digit, int &pos,bool *visited, int currpos);
int merginFunctionsV2( int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, bool *visitedPosV2, int currpos);

int main()
{
    bool *visitedPos = new bool[5];
    bool *visitedPosV2 = new bool[5];
    for (int i=0; i<5; i++)
    {
       visitedPos[i] = false;
       visitedPosV2[i] = false;
    }
    int totSamePos =0, pos=4, a = 13456, b=33516 ;
    cout << " a "<< a <<endl << " b "<< b <<endl;
    cout << " total same pos => "<<checkDigitEqualsInSamePosition(a, b, totSamePos,pos,visitedPos,visitedPosV2)<<endl;
    for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPos[i];
    }
    cout << endl;
    for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPosV2[i];
    }
    cout << endl;
    //cout << "Testing mergingFunctiosv2.........." <<endl;
    int currpos =4, digit=0;
    cout << " tota diff pos => "<<merginFunctionsV2( a, digit, b, pos, visitedPos, visitedPosV2, currpos)<<endl; 

   for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPos[i];
    }
    cout << endl;

       for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPosV2[i];
    }
    cout << endl;
    return 0;
}

int checkDigitEqualsInSamePosition(int n, int m, int totSamePos, int &pos, bool *visitedPos, bool *visitedPosV2) {
    if (n == 0 ) {
       return totSamePos;
    } else {
       if ( n%10 == m%10 ) {
          visitedPos[pos] = true;
          visitedPosV2[pos] = true;
          totSamePos++;
       } 
           pos-=1;
          return checkDigitEqualsInSamePosition(n/10, m/10,totSamePos, pos, visitedPos, visitedPosV2);
    }
}


int checkIfDigitApearsInNumberVisPos(int totDiffPos,int n, int digit,int &pos,bool *visitedPos, bool *visitedPosV2, int currpos)
{
  if (n == 0) {
       return totDiffPos;
    } else {
      /*
         m 11432
         n 12433
           10110
      */
     cout << " digit inside "<< digit <<" pos "<<pos<<" isVisited "<< visitedPos[pos] << " currpos "<< currpos << " digit "<< n % 10<<" isVisited "<<visitedPosV2[currpos]<<endl;
       if (n % 10 == digit && pos != currpos && !visitedPos[pos] && !visitedPosV2[currpos] ) {
          cout << "Equals == n "<< n << " digit "<< digit << " pos "<< pos << " currpos "<<currpos<<" vistedPos " << visitedPos[pos] <<endl;
          visitedPos[currpos] = true;
          visitedPosV2[currpos] = true;

  
          totDiffPos++;
          //return totDiffPos;
       } else {
          //pos-=1;
         // currpos-=1;
          
       }
        currpos-=1;
       return checkIfDigitApearsInNumberVisPos(totDiffPos,n/10, digit, pos, visitedPos, visitedPosV2, currpos);
    }

}

int merginFunctionsV2(int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, bool *visitedPosV2,int currpos)
{
   int totDiffPos=0;
   for (int x=4; x >-1; --x)
   {
      currentNumber = currentNumber/10;
      for (int p=4; p >-1; --p)
      {
         
         digit = currentNumber%10; 

         //cout << " merginFunctionsV2 digit "<< digit << " pos "<< p <<endl;
         totDiffPos=checkIfDigitApearsInNumberVisPos(totDiffPos, variableNumber, digit, p, visitedPos, visitedPosV2,currpos);

      }
   }
   return totDiffPos;
}