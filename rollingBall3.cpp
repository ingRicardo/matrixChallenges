#include <iostream>
#include <fstream>
using namespace std;

void print(int ** grid, int N){

	for(int i =0; i < N; i++){
		cout<< "\n";
		for(int j=0; j<N; j++){
			cout<< " "<< grid[i][j];
		}
	}
	
	cout<<endl;

}
bool isValid(int N, int row, int col ){

	return row>-1 && row<N && col>-1 && col<N ;

}


int findPath(int **grid, int row, int col, int N){

	int answer = 1;
	int smallest = 500;
	int newDirection = 0;
	int nextRow = 0;
	int nextCol = 0;
	int nextValue = 0;
	int deltaRow[] = { 0, 1, 0, -1 };
	int deltaCol[] = { 1, 0, -1, 0 };
	int deltaSize = sizeof(deltaRow) / sizeof(deltaRow[0]);

	while (isValid(N, row, col)){

		for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++){
			nextRow = row + deltaRow[deltaIdx];
			nextCol = col + deltaCol[deltaIdx];

			if (isValid(N, nextRow, nextCol)){
				nextValue = grid[nextRow][nextCol];

				if (smallest > nextValue){
					smallest = nextValue;
					newDirection = deltaIdx;

				}

			}

		}

		row += deltaRow[newDirection];
		col += deltaCol[newDirection];

		if (!isValid(N, row, col) || smallest < grid[row][col])
			break;
		 else 
			answer++;

	}

	return answer;
}
int getMax(int **grid,int N){

	int row=0 , col=0, max; 
		max = findPath(grid,row,col,N);

		for( row =0 ; row< N; row++){
				cout<<"\n";
			for( col=0; col<N; col++){
				if(  findPath(grid,row,col,N) > max ){
					max = findPath(grid,row,col,N);	
				}
				cout << " "<< findPath(grid,row,col,N);
				
			}

		}
return max;

}
int main(){

	freopen("input.txt", "r", stdin);

	int test_case =0,N=0,i,j,num;
	cin >> test_case;

	for(int tc=1; tc <= test_case; tc++){
		cout<< "test case "<< tc;
		cout<<endl;

		cin >> N;
		int **grid = new int*[N];

		for(int i=0; i<N; i++)
			grid[i] = new int[N];


		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++){
				cin >> num;
				grid[i][j] = num;
			}
		
		print(grid, N);
		  
		int max = getMax(grid,N);

		cout <<endl;
		cout << "#"<<tc << ":"<< max;
		cout << endl;

		

		}
		

	return 0;
}
