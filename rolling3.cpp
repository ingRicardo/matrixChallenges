#include <iostream>
#include  <stdio.h>
#include <fstream>
using namespace std;
void print_matrix(int N, int **m){
	
	for(int row=0; row< N; row++){

		cout << "\n";

		for (int col=0; col <N; col++){
			cout<< " " <<  m[row][col];

		}		
	}
	cout << endl;


}

bool isValid(int N, int row,int  col){

	return row > -1 && row < N && col> -1 && col < N;
}
int findPath(int **grid, int row, int col, int N){

int answer = 1 ;
int smallest = 500;
int newDirection =0;
int nextRow =0;
int nextCol = 0;
int nextValue =0;
int deltaRow[] = {0 ,1 ,0 ,-1 };
int deltaCol[] = {1 ,0 ,-1 ,0 };
int deltaSize =  sizeof(deltaRow)/sizeof(deltaRow[0]);

	while(isValid(N,row,col)){

//		if(!isValid(N, row, col))
//		break;	

		for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++){
			nextRow = row + deltaRow[deltaIdx];
			nextCol = col + deltaCol[deltaIdx];
	
			if (isValid(N,nextRow,nextCol)){
				nextValue = grid[nextRow][nextCol];

				if( smallest > nextValue ){
					smallest = nextValue;
					newDirection =deltaIdx;


				}

			}
				


		}
	row += deltaRow[newDirection];
	col += deltaCol[newDirection];

	if (!isValid(N,row,col))
		break;

	answer++;
	}

return answer;

}

int findMax(int **m , int N ){

	int maxElem = m[0][0];

	for(int i =0 ; i < N; i++)
		for (int j = 0; j < N; j++)
			if(m[i][j] > maxElem )
				maxElem = m[i][j];


return maxElem;
}
int main(){
	
	freopen("input.txt", "r", stdin);

	int test_case = 0 ,N=0,i,j,num;
	cin >> test_case;
		for(int tc = 1; tc < test_case; tc++){
			cout << "\ntest case "<< tc << "\n";
			cin >> N;
			int **matrix  = new int*[N];

			for(int i=0; i< N; i++)
				matrix[i] =  new int [N];


	//		cout << "\n N "<< N<< "\n";
			for(i =0 ; i < N; i++){
				for(j = 0; j < N; j++){
					cin>>num;
					matrix[i][j] = num;
				}
				
			}
		print_matrix(N,matrix);
		int idxcc =0, max =0;
		
		int **pathMatr = new int*[N];
		for (int i = 0; i < N; i++)
			pathMatr[i] = new int[N];


		for (int row =0 ; row < N; row++){
			cout << "\n";	
			for (int col =0; col< N; col++){
				idxcc = findPath(matrix, row, col, N);
				//cout << " idxcc "<< idxcc<< "\n";
				pathMatr[row][col] = idxcc;
			}

		}

		cout<< "\n print idx matrix \n ";

		print_matrix(N,pathMatr);

		cout << "\n max elem \n";

		cout << " "<< findMax(pathMatr , N)<<"\n";
		cout<< endl;


//cout << "\n testing \n";

//cout << " " << findPath(matrix,0,0,N) << "\n";

	
		}





return 0;
}


