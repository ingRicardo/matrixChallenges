#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void print(int **grid, int N, int M){

	cout <<"\n printing matrix \n";

	for(int i=0; i<N; i++){
		cout<< "\n";
		for(int j=0; j<M; j++)
			cout<< " "<< grid[i][j];

	}
	cout << endl;
}

bool isValid(int row, int N, int col, int M){

	return row >-1 && row<N && col >-1 && col<M;

}
bool isHouse(int **grid, int row, int col){

	return grid[row][col] == 1;

}


bool isAntenna (int **grid, int row, int col){

	return grid[row][col] == 2 || grid[row][col] ==3 || grid[row][col] ==4;

}
int antennaPower(int **grid, int row, int col){
int val = grid[row][col];
	if (grid[row][col] ==2 || grid[row][col] == 3 || grid[row][col] == 4)
		return val -=1;
return 0;
}



int getAntennas(int **grid, int N, int M, int rowDelta[], int colDelta[], int deltaSize , int col, int row){
int nextRow=0,nextCol=0, antennas=0;
	for(int deltaIdx=0; deltaIdx < deltaSize-1; deltaIdx++){

			nextRow=   row + rowDelta[deltaIdx];
			nextCol=  col + colDelta[deltaIdx];
			if(isValid(nextRow,  N, nextCol, M) && isAntenna(grid,nextRow,nextCol) )
							antennas++;

	}
return antennas;
}

int house_signal(int **grid, int N, int M, int rowDelta[], int colDelta[], int deltaSize , int col, int row, int power){

int touch_house =0,rt=0,ct=0,nextRow=0,nextCol=0;
			for(int deltaIdx=0; deltaIdx < deltaSize-1; deltaIdx++){
			 rt = 0;
			 ct = 0;
	  			for(int j=0; j<power; j++){
	   				
					rt += rowDelta[deltaIdx];
           				ct += colDelta[deltaIdx];
	   				nextRow=   row + rt;
	   				nextCol=  col + ct;

	    				if(isValid(nextRow,  N, nextCol, M) && isHouse(grid,nextRow,nextCol))
							touch_house++;	
					
        			}

       			} 


return touch_house;
} 
int house_surrounded_by_antennas(int antennas){

	if (antennas ==2 ||  antennas ==3 ||  antennas ==4 )
		return antennas -=1;

return 0;

}

int findNoSignalHouses(int **grid, int rowDelta[], int colDelta[], int N, int M,int deltaSize){

int row=0, col=0,houses=0,touch_house=0,noSignalHouses=0;
int duplicate_houses=0,houses_with_signal=0;
	for(int row=0; row<N; row++)
		for(int col=0; col<M; col++)
		  if(isHouse(grid,row,col)){
    			houses++; 
			duplicate_houses += house_surrounded_by_antennas(getAntennas(grid,N,M,rowDelta,colDelta,deltaSize,col,row));
		  }else if(isAntenna(grid,row,col))
	           	houses_with_signal += house_signal(grid,  N,  M,  rowDelta,  colDelta,  deltaSize ,  col,  row, antennaPower(grid,row,col));
  		
	noSignalHouses = houses - (houses_with_signal-duplicate_houses);

 return noSignalHouses; 
}
int main(){


	freopen("input.txt","r",stdin);
	int test_case =0;
	cin >> test_case;
	int rowDelta[] ={0,1,0,-1,0};
	int colDelta[] ={1,0,-1,0,1};
	int deltaSize = sizeof(rowDelta)/sizeof(rowDelta[0]),answer =0;

	for(int tc = 1; tc<=test_case; tc++){
		cout<< "\ntest case "<<tc <<"\n";
		int N =0,M=0,num=0;
		cin >> N;
		cin >> M;
		cout << "\n N "<<N<<"\n M "<<M;
		int **matrix =  new int*[N];
		for (int i=0; i<N; i++)
			matrix[i] = new int[M];
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M;j++){
				cin>> num;
				matrix[i][j] = num;
			}
		}	

		print(matrix, N, M);
			answer =findNoSignalHouses(matrix,rowDelta,colDelta,N,M,deltaSize );
			cout << "#"<<tc<<":"<<answer<<"\n";	
	}


return 0;
}
