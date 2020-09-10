//https://stackoverflow.com/questions/39032564/recursively-check-if-all-digits-of-a-number-are-different


#include <iostream>
using namespace std;
bool checkIfDigitApearsInNumber(int n, int digit, bool *visited);
bool checkIfDigitApearsInTwoNumbers(int n,int m,bool *visited);
int checkIfDigitApearsInNumberTest(int n, int m, bool *visited, int totc1);
int checkIfDigitApearsInNumberTestPos(int n, int m,bool *visited, int totc1, int &pos, bool *visitedPos);
int checkIfDigitApearsInNumberTestPosSingle(int n, int tmpn,int totc1, int &pos, bool *visitedPos);
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

    return 0;
}


int checkIfDigitApearsInNumberTestPosSingle(int n, int tmpn, int totc1, int &pos, bool *visitedPos)
{
    if (n == 0 ) {
       return n;
    } else {
      
      tmpn = n%10; 
    } 
     cout << " tmpn-> "<< tmpn <<endl ;
     
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