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

        logic

            permutation
  
            2, 2 ---> 5, 5 --- OK
            2, 2 ---> 5, 5 --- OK Rotation 
            2, 2 ---> 7, 4 --- OK
            2, 2 ---> 4, 7 --- OK Rotation 
            2, 2 ---> 3, 6 --- OK
            2, 2 ---> 6, 3 --- OK Rotation 
            2, 2 ---> 10, 8 ---OK
            2, 2 ---> 8, 10 ---OK Rotation 

               8 - 2,2

            5, 5 ---> 2, 2 --- NA
            5, 5 ---> 2, 2 --- NA 
            5, 5 ---> 5, 5 --- NA
            5, 5 ---> 5, 5 --- NA
            5, 5 ---> 7, 4 --- NA
            5, 5 ---> 4, 7 --- NA
            5, 5 ---> 3, 6 --- NA
            5, 5 ---> 6, 3 --- NA
            5, 5 ---> 10, 8 -- OK
            5, 5 ---> 8, 10 -- OK

               2 - 5,5

            7, 4 ---> 2, 2  -- NA
            7, 4 ---> 2, 2  -- NA
            7, 4 ---> 5, 5  -- NA
            7, 4 ---> 5, 5  -- NA
            7, 4 ---> 7, 4  -- NA
            7, 4 ---> 4, 7  -- NA
            7, 4 ---> 3, 6  -- NA
            7, 4 ---> 6, 3  -- NA
            7, 4 ---> 10, 8 -- OK
            7, 4 ---> 8, 10 -- OK

                2 - 7,4

            3, 6 ---> 2, 2 -- NA
            3, 6 ---> 2, 2 -- NA
            3, 6 ---> 5, 5 -- NA
            3, 6 ---> 5, 5 -- NA
            3, 6 ---> 7, 4 -- NA
            3, 6 ---> 4, 7 -- OK
            3, 6 ---> 3, 6 -- NA
            3, 6 ---> 6, 3 -- NA
            3, 6 ---> 10, 8 - OK
            3, 6 ---> 8, 10 - OK

                3 - 3, 6
            ( ( ( 3, 6 ),  4, 7) , 10, 8)

            10, 8 --->2, 2 -- NA
            10, 8 --->2, 2 -- NA
            10, 8 --->5, 5 -- NA
            10, 8 --->7, 4 -- NA
            10, 8 --->4, 7 -- NA
            10, 8 --->3, 6 -- NA
            10, 8 --->6, 3 -- NA
            10, 8 --->10, 8 - NA

------------------------------------------
    
                5, 5   7, 4  3, 6  10, 8  4, 7  6, 3   8, 10 
        2, 2     OK     OK    OK    OK     OK     OK    OK  
        5, 5     -      -     -     OK     -       -    OK
        7, 4     -      -     -     OK     -       -    OK
        3, 6     -      -     -     OK     OK      -    OK
        10, 8    -      -     -     -      -       -    -
        
    */

    freopen("input.txt","r",stdin);

    int t,blocks;
    cin>>t;
    cout <<"test  cases "<<t<<endl;
    for (int tc =1; tc<=1; ++tc)
    {
        cin>> blocks;
        int **blocks_arr = new int*[blocks];
        int x,y;
        for (int b =0; b<blocks; ++b)
        {
            cin>> x;
            cin>> y;
            blocks_arr[b] = new int [2];
            blocks_arr[b][0]=x;
            blocks_arr[b][1]=y;
            
            cout << blocks_arr[b][0] << ", "<<  blocks_arr[b][1];
            cout<<endl;
        }                
        cout<<endl;
    }


    return 0;
}