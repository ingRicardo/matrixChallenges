import java.io.File;
import java.util.Scanner;

/**
 * @author SRT
 *
 */

public class mirror {

/**
* @param args
*/
final static int RIGHT =0, DOWN =1, LEFT=2,UP =3;

public static void main(String[] args) {
// TODO Auto-generated method stub

	Scanner sc = null;
        try {
            sc = new Scanner(new File("input.txt"));
         
        } catch(Exception e) {
           
        }
       
int TEST_CASES = sc.nextInt();
       
int [] rowDelta = new int []{0,1,0,-1};
int [] colDelta = new int []{1,0,-1,0};

for (int t=1; t <= TEST_CASES; t++) {

    int N = sc.nextInt();
      int grid[][] = new int[N][N];
     
       for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }
    int currentDirection = RIGHT;
    int answer = 0,col = 0, row = 0;
do {

	if (isMirror(grid, row,col)) {
		currentDirection = changeDirection(currentDirection,grid[row][col] );
		answer++;
	}

	col += colDelta [currentDirection];
	row += rowDelta [currentDirection];

} while (isValid(grid, row, col));
 
       
System.out.println(String.format("#%d %d", t, answer));

}

       
}
static int changeDirection(int current, int mirror) {
 int newDirection = RIGHT;


switch (current) {
	case RIGHT:
		newDirection = (mirror == 1) ? UP : DOWN;
		break;
	case LEFT:
		newDirection = (mirror == 1 ) ? DOWN : UP;
		break;
	case UP:
		newDirection = (mirror ==1) ? RIGHT :LEFT;
		break;
	case DOWN:
		newDirection = (mirror ==1) ? LEFT :RIGHT;
		break;

}


	return newDirection;
}


static boolean isMirror(int[][] g, int r, int c) {

	return g[r][c] !=0;
}

static private boolean isValid(int [][] grid, int r, int c) {

	return r >-1 && r<grid.length && c>-1 && c < grid.length;

}

}
