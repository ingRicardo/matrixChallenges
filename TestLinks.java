/**
 * 
 */
package shortest;

import java.io.File;
import java.util.Scanner;


/**
 * @author SRT
 *
 */

class Point{
	
	int x, y;
	
	public Point(int x, int y) {
		
		this.x = x;
		this.y =y;
		
	}
}

class queueNode {
	
	Point pt;
	int dist;
	
	public queueNode(Point pt, int dist) {
		
		this.pt = pt;
		this.dist = dist;
	}
	
}

class node {
	
	queueNode data;
	node next;
}

class linked_list{
	
	private static node head, tail;
	
	public linked_list() {
		head =null;
		tail = null;
		
	}
	
	public void push(  queueNode n ) {
		node tmp = new node();
		tmp.data = n;
		tmp.next = null;
		
		if(head == null) {
			head = tmp;
			tail =tmp;
		}else {
			
			tail.next =tmp;
			tail = tail.next;
			
		}
		
	}
	
	public static void display() {
		
		node tmp = new node();
		tmp = head;
		while (tmp != null) {
			
			System.out.println("data X " + tmp.data.pt.x + "\n");
			System.out.println("data Y " + tmp.data.pt.y + "\n");
			System.out.println("dta dist " + tmp.data.dist + "\n");
			tmp = tmp.next;
		}
		
		
	}
	
	public  boolean isEmpty() {
		node tmp = new node();
		tmp = head;
		
		if(tmp == null)
			return true;
		else
			return false;
		
	}
	
	public  void pop() {	
		//node tmp = new node();
		//tmp = head;
		head = head.next;
		
	}
	public  node front() {
		
		node tmp= new node();
		tmp = head;
		return tmp;
	}
	
	
}


public class TestLinks {

	/**
	 * @param args
	 */
	public static int rowDelta []= {0, 1, 1, 1, 0, -1, -1, -1};
	public static int colDelta []= {1, 1, 0, -1, -1, -1, 0, 1};

	
	public static boolean isValid(int [][] grid, int row, int col) {
		
		return row>-1 && row < grid.length && col>-1 && col< grid.length;
		
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
	public static int shortestPathBinaryMatrix( int [][] grid, Point src, Point dest ) {
		
		if(grid[src.x][src.y] == 1 || grid[dest.x][dest.y] ==1 ) {
			return -1;
		}
		
		int N = grid.length, M = grid[0].length;
		
		boolean [][] visited = new boolean[N][M];
		
		visited[src.x][src.y] = true;
		linked_list q = new linked_list();
		
		int deltaSize = rowDelta.length;
		
		queueNode s = new queueNode(src, 1);
		q.push(s);
		
		while (!q.isEmpty() ) {
			node curr = q.front();
			
			Point pt = curr.data.pt;
			
			if(pt.x == dest.x && pt.y == dest.y)
				return curr.data.dist;
			
			
			q.pop();
			
			for (int deltaIdx = 0; deltaIdx < deltaSize; deltaIdx++)
			{

				int row = pt.x + rowDelta[deltaIdx];
				int col = pt.y + colDelta[deltaIdx];

				// if adjacent cell is valid, has path and 
				// not visited yet, enqueue it. 
				if (isValid(grid,row, col) && grid[row][col] == 0 && !visited[row][col]){
					//cout << "\n adjacent \n";
					// mark cell as visited and enqueue it 
					Point newPoint = new Point(row, col);
					queueNode Adjcell = new queueNode(newPoint, curr.data.dist + 1);
					q.push(Adjcell);
				}
			}
			
			
		}
		
		
		
		return -1;
	}
	
	
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
