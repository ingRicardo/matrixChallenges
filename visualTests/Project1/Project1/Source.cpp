#include <iostream>

using namespace std;

/*

 CUT THE FIRST TREE and combine it cutting another tree

 example max trees that can be cut down = 2

1 0 1 0 0 0 0	X 0 X 0 0 0 0
1 1 1 1 0 0 1	V V V V 0 0 V
0 0 1 2 1 0 1	0 0 V 2 V 0 V
0 0 2 0 0 1 1	0 0 2 0 0 V V
1 0 0 1 0 2 0	1 0 0 1 0 2 0
0 1 1 0 0 1 0	0 1 1 0 0 V 0
0 0 0 1 0 0 0	0 0 0 1 0 0 0

tota trees = 18
2 trees cut down
11 burnt trees
5 trees alive

trees alive = 	    tota trees - trees cut down	 - burnt trees
	5	       18       - 2              - 11


-------------------------------------
1 0 1 0 0 0 0	X 0 1 0 0 0 0
1 1 1 1 0 0 1	X V V V 0 0 V
0 0 1 2 1 0 1	0 0 V 2 V 0 V
0 0 2 0 0 1 1	0 0 2 0 0 V V
1 0 0 1 0 2 0	1 0 0 1 0 2 0
0 1 1 0 0 1 0	0 1 1 0 0 V 0
0 0 0 1 0 0 0	0 0 0 1 0 0 0

total = 18 - 2 - 10
6

---------


---------
	cuttree1 =false;
	cuttree2 =false;
	burnt_trees_acc=0;
	for (int row =0 ; row < h; row++) //loop start from postion 0,0
		for (int col =0; col < w; col++)
		{	
			if (current == 1 && !visited[row][col])
			{
				visited[row][col] = true;
				for (int row1 =row ; row1 < h; row1++) //loop start from position 0,1
					for (int col1 =col+1; col1 < w; col1++)	
					{
						if (current2 == 1 && !visited[row1][col1])
						{
							visited[row1][col1] = true;

						} //end if
				
						if (current2 == 2)
						{
							int burnt_ trees = BFS (); 
							burnt_trees_acc += burnt_trees;

						}

					}// end loop
			}//end if
	}//end loop
*/


void wildFire()
{
	freopen("C:\\Users\\SRT\\Repositories\\SoftCer\\matrixChallenges\\visualTests\\Project1\\in.txt","r", stdin);
	int T = 0;
	cin >> T;
	cout << "Test T --->"<< T << endl;

	cout << " start wildFire " << endl;

}
int main()
{
	
	cout << "test riky   mac" << endl;
	wildFire();
	return 0;
}

