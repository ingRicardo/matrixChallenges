#include <iostream>
using namespace std;

void printBool(bool **visited, int n){
	for (int row = 0; row< n; row++)
	{
		cout << endl;
		for (int col = 0; col <n; col++)
			cout << " " << visited[row][col];
	}
	cout<<endl;
}

bool isValid(int **grid, int row, int col, bool **visited, int n)
{

	return row>-1 && row<n && col>-1 && col<n && !visited[row][col];
}

void countPahts(int a1, int b1, int **grid , int cameraTime,int lastTime, bool camera, bool end,int x, int y, int a2, int b2, int c1, int d1, bool **visited,int n, int& cc, int &paths   )
{
	int current = grid[x][y];

	if (current == 0 && cc == cameraTime || current ==0 && cc == lastTime)
		return;

	if (  current== cameraTime && cc == cameraTime ) 
	{
		camera = true;
	}

	if (current == lastTime && cc == lastTime )
	{
		end =true;
	}
	if(end && camera)
	{
		paths++;
		printBool(visited,n);
		return;

	}

	visited[x][y] = true;

	cc++;
	int deltaRow [] ={ 0,1, 0,-1 };
	int deltaCol[] = { 1,0,-1, 0 };
	int deltaSize = sizeof(deltaRow)/sizeof(deltaRow[0]);
	for( int  idx =0; idx<deltaSize; idx++  )
	{
		int nextRow =x + deltaRow[idx];
		int nextCol=y + deltaCol[idx];
		if(isValid(grid,nextRow,nextCol,visited,n))
		{

			 countPahts(a1,b1,grid,cameraTime,lastTime,camera,end,nextRow,nextCol,a2,b2,c1,d1,visited,n,cc,paths);
				
		}
	}

	// backtrack from current position and remove it from current path
	visited[x][y] = false;
	cc--;
}
	

void getAns(int **grid, bool **visited,int  n, int lastTime, int a1, int b1, int a2, int b2, int c1, int d1, int cameraTime,int &paths)
{
//the coordinates of the laboratory (a1, b1) 
//the coordinates of the place where the escaped zombie was caught (a2, b2). 
//contains the coordinates of the CCTV that captured the zombie (c1, d1) .
   cout << "laboratory "<< a1 << ", "<<b1 <<endl;
   cout << "time zombie was captured "<< lastTime<<endl;
   cout << "time CCTV cpture the zombi "<< cameraTime<<endl;
	
   int aa1 =a1, bb1=b1;
   int cc =0;	
   bool camera = false, end= false;
   countPahts(a1,b1, grid ,cameraTime,lastTime,camera, end, aa1, bb1,  a2,  b2,  c1,  d1, visited, n, cc ,paths);
   cout << "\ncount paths "<< paths << endl;	
   
}
int main()
{
    int T, n, timeCaptured, a1, b1, a2, b2, c1, d1, timeVideoTaken,paths=0;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		paths = 0;
		cin >> n;
		int **grid = new int*[n];
        	bool **visited = new bool*[n];
		cin >> timeCaptured;
		cin >> a1; cin >> b1; cin >> a2; cin >> b2;
		cin >> c1; cin >> d1; cin >> timeVideoTaken;
		// cout << "\n n=> "<<n; 
		a1 = a1-1;b1= b1-1;a2 = a2-1;b2 =b2 -1;c1 = c1-1;d1 = d1-1;
		for (int row = 0; row<n; row++)
		{
			cout << endl;
			grid[row] = new int[n];
            		visited[row] = new bool[n];
			for (int col = 0; col<n; col++)
			{
				if(row == a1 && col == b1){
                    			grid[row][col] = 0;
               			 }
				else if (row == a2 && col == b2)
                		{
                    			grid[row][col] =timeCaptured;
               			 }	
				else if(row ==c1 && col == d1)
               			{
                    			grid[row][col] =timeVideoTaken;
               			}
				else
			       	{
                    			grid[row][col] = 0;
               			}
				cout << " " << grid[row][col];
			}

		}
		cout << endl;
		getAns(grid, visited, n, timeCaptured, a1, b1, a2, b2, c1, d1, timeVideoTaken,paths);
		cout << endl;
		cout << "#" << tc << ":" <<paths<< endl;
	}
	
    return 0;
}
