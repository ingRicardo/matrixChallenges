#include <iostream>
using namespace std;
int main()
{
    cout <<" wooden block stacking"<<endl;


    /*
    # of blocks = 5
    dimensions of the blocks
    2 2
    5 5 
    7 4
    3 6
    10 8
    output = 4  // number of height that could be obtained when stacking the blocks
     _ _ _ _ _ _ _ _
    |   |   | | |   |
    |_ _|2X2| | |   |
    |_ _ _ _|_|_|3X6|
    |       | |     |
    |_ _ _ _|_|5X5  |
    |       |       |
    |_ _ _ _|7X4    |
    |               |
    |               |
    |_ _ _ _ _ _ _ _| 10X8

    2X2    
     _ _ _ _ _ _ _ _
    |   |       | | |
    |_ _|   3X6 | | |
    |_ _ _ _ _ _| | |
    |_ _ _ _ _ _ _| |
    |           4x7 |
    |               |
    |               |
    |               |
    |               |
    |_ _ _ _ _ _ _ _| 10X8

    ANSWER = (10X8),(4X7),(3X6),(2X2) = 4
    */



    return 0;
}