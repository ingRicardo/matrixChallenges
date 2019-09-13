/**
 * 
 */
package beans;

import java.io.File;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * @author SRT
 *
 */

class Point {
	
	int row, col;
	
	public Point(int row, int col) {
		
		this.row =  row;
		this.col = col;
	}
	
}

class queueNode {
	
	Point point;
	int dist;
	
	public queueNode(Point point, int dist) {
		this.point = point;
		this.dist = dist;
	}
	
}


public class Shorest {
	
	public static int rowDelta []= {0, 1, 1, 1, 0, -1, -1, -1};
	public static int colDelta []= {1, 1, 0, -1, -1, -1, 0, 1};

	
	public static boolean isValid(int [][] grid, int row, int col) {
		
		return row>-1 && row < grid.length && col>-1 && col< grid.length;
		
	}
	
	public static int shortestPathBinaryMatrix( int [][] grid, Point src, Point dest ) {
		
		if(grid[src.row][src.col] == 1 || grid[dest.row][dest.col] ==1 ) {
			return -1;
		}
		int N = grid.length;
		boolean [][] visited = new boolean[N][N];
		visited[src.row][src.col] = true;
		
		Point point = new Point(src.row, src.col);		
		queueNode initial = new queueNode(point, 1);

		LinkedList <queueNode> q = new LinkedList<>();
		
		q.offer(initial);
		
		while(!q.isEmpty()) {
			
			queueNode curr = q.getFirst();
			Point pt = curr.point;
			
			// If we have reached the destination cell, 
			// we are done 
			if (pt.row == dest.row && pt.col == dest.col)
				return curr.dist;
			
			q.pop();
			
			for (int i = 0; i < rowDelta.length  ; i++)
			{
				
				int row = pt.row + rowDelta[i];
				int col = pt.col + colDelta[i];

				// if adjacent cell is valid, has path and 
				// not visited yet, enqueue it. 
				if (isValid(grid,row, col) && grid[row][col]==0 && !visited[row][col]){
					// mark cell as visited and enqueue it 
					visited[row][col] = true;
					Point newPoint = new Point(row, col);
					queueNode Adjcell = new queueNode(newPoint, curr.dist + 1);
					
					q.offer(Adjcell);
				}
			}
			
		}
		
		
		return -1;
	}
	
	
	public static void print_grid(int [][] grid){

		for(int row =0 ; row < grid.length; row++){
		System.out.println("");
			for(int col=0; col < grid[0].length; col++){
				
				System.out.print(" "+ grid[row][col]);

			}
		}

		System.out.println("");
	}
	
	
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = null;

		try {
			sc = new Scanner(  new File("C:\\Users\\SRT\\algorithms\\robot\\src\\beans\\inputB.txt")  );
		} catch (Exception e){
			e.printStackTrace();
		}

		int test_case =  sc.nextInt();

		int answer = 0, N=0;

		for (int tc = 1; tc <= test_case; tc++){

			N = sc.nextInt();
			int grid [][] =  new int [N][N];

			for(int row = 0 ; row < grid.length ; row++)
				for(int col=0; col< grid[0].length; col++)
					grid[row][col] = sc.nextInt();
//Integer.MAX_VALUE

			print_grid(grid);
			
			Point source = new Point(0, 0);
			Point dest = new Point(N-1, N-1);
			
			int dist = shortestPathBinaryMatrix(grid, source, dest);
			
			if (dist != Integer.MAX_VALUE)
				System.out.println("Shortest Path is " + dist);
			else
				System.out.println("Shortest Path dosen't exist");
			
			answer = dist;
			
			System.out.println("#"+tc+":"+answer);
			
		}
		
	}

}
