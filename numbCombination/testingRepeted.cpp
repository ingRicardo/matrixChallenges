//https://stackoverflow.com/questions/39032564/recursively-check-if-all-digits-of-a-number-are-different


#include <iostream>
using namespace std;
bool checkIfDigitApearsInNumber(int n, int digit);
int main()
{
    cout << checkIfDigitApearsInNumber(12343,1);

    return 0;
}

bool checkIfDigitApearsInNumber(int n, int digit) {
    if (n == 0) {
       return false;
    } else {
       if (n % 10 == digit) {
          return true;
       } else {
          return checkIfDigitApearsInNumber(n/10, digit);
       }
    }
}