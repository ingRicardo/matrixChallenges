//https://stackoverflow.com/questions/39032564/recursively-check-if-all-digits-of-a-number-are-different


#include <iostream>
using namespace std;
bool checkIfDigitApearsInNumber(int n, int digit, bool *visited);
bool checkIfDigitApearsInTwoNumbers(int n,int m,bool *visited);
int checkIfDigitApearsInNumberTest(int n, int m, bool *visited, int totc1);
int checkIfDigitApearsInNumberTestPos(int n, int m,bool *visited, int totc1, int &pos, bool *visitedPos);
int checkIfDigitApearsInNumberTestPosSingle(int n, int tmpn,int totc1, int &pos, bool *visitedPos);
int checkIfDigitApearsInNumberVisPos(int n, int digit, int &pos,bool *visited, int currpos);
void testingTwoFunc(int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos);
int merginFunctions(int start, int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, int currpos);

int merginFunctionsV2(int start, int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, int currpos);

int main()
{
    
    bool * visited = new bool [10];
    for (int i=0; i<10; i++)
    {
       visited[i] = false;
    }

    bool *visitedPos = new bool[5];
    for (int i=0; i<5; i++)
    {
       visitedPos[i] = false;
    }

    //cout << checkIfDigitApearsInNumber(12343,1, visited);
    //cout << checkIfDigitApearsInTwoNumbers(23213, 23423,visited); 
    int totc1 =0;
   cout << checkIfDigitApearsInNumberTest(12433, 11432,visited, totc1);
   cout<<endl;
   int pos=4;
   checkIfDigitApearsInNumberTestPos(12433, 11432,visited, totc1,pos,visitedPos);
   for (int i=0; i<10; i++)
    {
      cout <<" " << visited[i];
    }
cout <<endl;
for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPos[i];
    }
cout << endl;
int tmpn =0;
checkIfDigitApearsInNumberTestPosSingle(11432,tmpn,totc1, pos,visitedPos);
int singlenum=0;
pos=4;
//cout << "Tesing....."<<endl;
//testingTwoFunc(12433, singlenum, 11432,  pos,visitedPos);

cout << "Testing mergingFunctiosv2.........." <<endl;
int currpos =4, start=0, digit=0;
merginFunctionsV2(start, 12433, digit, 11432, pos, visitedPos, currpos); 

    return 0;
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

int merginFunctions(int start, int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos, int currpos)
{

    if (currentNumber == 0 ) {
       return currentNumber;
    } else {
         /*
         m 11432   variableNumber
         n 12433   currentNumber
           10110
           x1xx2
           x2xx3

         for(int start=; )

         */
       
      
      digit = currentNumber%10; 
      cout << " merginFunctions digit "<< digit << " pos "<< pos <<endl;
      checkIfDigitApearsInNumberVisPos(variableNumber, digit, pos, visitedPos, currpos);

      return 0;
    } 
     //cout << " digit-> "<< digit <<endl ;
     //pos -=1;
    // return merginFunctions(currentNumber/10, digit, variableNumber, pos, visitedPos);
      return 0;
}
void testingTwoFunc(int currentNumber, int &digit, int variableNumber,  int &pos, bool *visitedPos)
{

   for (int i=0; i<5; i++)
    {
      cout <<" " << visitedPos[i];
    }
      cout <<endl;
   //checkIfDigitApearsInNumberTestPosSingle(variableNumber, digit, 0, pos,visitedPos);
   //checkIfDigitApearsInNumberTestPosSingle
   //checkIfDigitApearsInNumberVisPos
   int currpos =4, start=0;
   merginFunctions(start,currentNumber, digit, variableNumber, pos, visitedPos, currpos);
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
          return true;
       } else {
          //pos-=1;
          currpos-=1;
          return checkIfDigitApearsInNumberVisPos(n/10, digit, pos, visitedPos, currpos);
       }
    }

}
int checkIfDigitApearsInNumberTestPosSingle(int n, int tmpn, int totc1, int &pos, bool *visitedPos)
{
    if (n == 0 ) {
       return n;
    } else {
      
      tmpn = n%10; 
    } 
     cout << " tmpn-> "<< tmpn <<endl ;
     pos-=1;
     return checkIfDigitApearsInNumberTestPosSingle(n/10, tmpn, totc1, pos, visitedPos);
    
}

int checkIfDigitApearsInNumberTestPos(int n, int m,bool *visited, int totc1, int &pos, bool *visitedPos) {
    if (n == 0 ) {
       return totc1;
    } else {
       cout << " m "<< m <<endl ;
       cout << " n "<< n <<endl ;
       if ( n%10 == m%10 ) {
          cout << "equals n "<< n<< " m "<< m << endl;
          visited[n%10] = true;
          visitedPos[pos] = true;
          totc1++;
          
          
          cout << " pos "<< pos<<endl;
       } 
           pos-=1;
          return checkIfDigitApearsInNumberTestPos(n/10, m/10,visited, totc1, pos, visitedPos);
    }
}


int checkIfDigitApearsInNumberTest(int n, int m,bool *visited, int totc1) {
    if (n == 0 ) {
       return totc1;
    } else {
       cout << " m "<< m <<endl ;
       cout << " n "<< n <<endl ;
       if ( n%10 == m%10 ) {
          cout << " n "<< n<< " m "<< m << endl;
          visited[n%10] = true;
          totc1++;
       } 
          return checkIfDigitApearsInNumberTest(n/10, m/10,visited, totc1);
    }
}





bool checkIfDigitApearsInNumber(int n, int digit,bool *visited) {
    if (n == 0) {
       return false;
    } else {
       if (n % 10 == digit) {
          visited[digit] = true;
          return true;
       } else {
          return checkIfDigitApearsInNumber(n/10, digit, visited);
       }
    }
}

//https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
bool checkIfDigitApearsInTwoNumbers(int n,int m,bool *visited) {
    if (n == 0) {
       return false;
    } else {
       if (n % 10 ==  m % 10) {
          visited[n % 10] = true;
          return true;
       } else {
          return checkIfDigitApearsInTwoNumbers(n/10, m/10, visited);
       }
    }
}

// create a function similar but with one extra parameter position
// position will increment the value in each recursion