//https://stackoverflow.com/questions/39032564/recursively-check-if-all-digits-of-a-number-are-different


#include <iostream>
using namespace std;
bool checkIfDigitApearsInNumber(int n, int digit, bool *visited);
bool checkIfDigitApearsInTwoNumbers(int n,int m,bool *visited);
int checkIfDigitApearsInNumberTest(int n, int m, bool *visited, int totc1);

int main()
{
    
    bool * visited = new bool [10];
    for (int i=0; i<10; i++)
    {
       visited[i] = false;
    }

    //cout << checkIfDigitApearsInNumber(12343,1, visited);
    //cout << checkIfDigitApearsInTwoNumbers(23213, 23423,visited); 
    int totc1 =0;
    cout << checkIfDigitApearsInNumberTest(12433, 11433,visited, totc1);
   cout<<endl;
   for (int i=0; i<10; i++)
    {
      cout <<" " << visited[i];
    }

    return 0;
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