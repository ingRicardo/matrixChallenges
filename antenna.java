import java.io.File;
import java.util.Scanner;

public class antenna {


public static void print(int [][] grid, int N, int M){

	System.out.println("\nprinting matrix \n");
	for(int i=0; i<N; i++){
	System.out.println("");
		for(int j=0; j<M; j++)
		System.out.print(" "+ grid[i][j]);	

	}
	System.out.println("");
}

public static boolean isValid(int row, int N, int col, int M){

	return row >-1 && row<N && col >-1 && col<M;

}
public static boolean isHouse(int [][]grid, int row, int col){

	return grid[row][col] == 1;

}


public static boolean isAntenna (int [][]grid, int row, int col){

	return grid[row][col] == 2 || grid[row][col] ==3 || grid[row][col] ==4;

}
public static int antennaPower(int [][]grid, int row, int col){
int val = grid[row][col];
	if (grid[row][col] ==2 || grid[row][col] == 3 || grid[row][col] == 4)
		return val -=1;
return 0;
}



public static int getAntennas(int [][]grid, int N, int M, int rowDelta[], int colDelta[], int deltaSize , int col, int row){
int nextRow=0,nextCol=0, antennas=0;
	for(int deltaIdx=0; deltaIdx < deltaSize; deltaIdx++){

			nextRow=   row + rowDelta[deltaIdx];
			nextCol=  col + colDelta[deltaIdx];
			if(isValid(nextRow,  N, nextCol, M) && isAntenna(grid,nextRow,nextCol) )
							antennas++;

	}
return antennas;
}

public static int house_signal(int [][]grid, int N, int M, int rowDelta[], int colDelta[], int deltaSize , int col, int row, int power){

int touch_house =0,rt=0,ct=0,nextRow=0,nextCol=0;
			for(int deltaIdx=0; deltaIdx < deltaSize; deltaIdx++){
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
public static int house_surrounded_by_antennas(int antennas){

	if (antennas ==2 ||  antennas ==3 ||  antennas ==4 )
		return antennas -=1;

return 0;

}

public static int findNoSignalHouses(int [][]grid, int rowDelta[], int colDelta[], int N, int M,int deltaSize){

int houses=0,touch_house=0,noSignalHouses=0;
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


public static void main(String[] args){
	Scanner sc = null;
        try {
            sc = new Scanner(new File("input.txt"));
         
        } catch(Exception e) {
           
        }
       
int TEST_CASES = sc.nextInt();
       
int [] rowDelta = new int []{0,1,0,-1};
int [] colDelta = new int []{1,0,-1,0};
int answer =0;
for (int t=1; t <= TEST_CASES; t++) {
System.out.println("\n  test case "+ t +"\n");
    int N = sc.nextInt(), M= sc.nextInt();
      int grid[][] = new int[N][M];
      int deltaSize = rowDelta.length; 
       for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }


	print(grid, N, M);
	answer =findNoSignalHouses(grid,rowDelta,colDelta,N,M,deltaSize );
		//	cout << "#"<<tc<<":"<<answer<<"\n";	
System.out.println("# "+ t + ":"+ answer + "\n");


  }

 }


}



