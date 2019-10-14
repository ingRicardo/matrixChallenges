/**
 * 
 */
package frodo;

import java.io.File;
import java.util.Scanner;



/**
 * @author SRT
 *
 */
public class Frodo {

	/**
	 * @param args
	 */
	
	static int lowestCost= Integer.MAX_VALUE;
	
	
	static int findPath(int cost, int pos, int[][] Enemies, int [][] myOrcs){
		
		//base
			if (cost>=lowestCost) return lowestCost;
			
			if(pos >= Enemies.length) return cost;
			
			int toll = Enemies[pos][1];
			int cost1 = findPath(cost + toll, pos +1, Enemies,myOrcs);  //path en path
		
			
			//declare new tmp array to keep the origonal array values
			int newOrcs[][] = new int[myOrcs.length][2];
			int totalMercenaries=0;
			//copy the current values to temp array
			for(int i=0; i< newOrcs.length; i++){
				newOrcs[i][0] = myOrcs[i][0];
				newOrcs[i][1] = myOrcs[i][1];
				totalMercenaries +=newOrcs[i][0];//find total orcs
			}
			newOrcs[pos][0] = Enemies[pos][0];
			newOrcs[pos][1] = 3;
			int hireCost =toll *2;
			int cost2 = findPath(cost + hireCost, pos +1, Enemies,newOrcs); //path en H	
		
			//return  new orcs to original 
			newOrcs[pos][0] =myOrcs[pos][0];
			newOrcs[pos][1] =myOrcs[pos][1];
			
			int enemiesThisRound = Enemies[pos][0];
			if(totalMercenaries >= enemiesThisRound){
				//battle
				for(int i =0; i<newOrcs.length; i++){
					int mercenariosRound = newOrcs[i][0];
					if(mercenariosRound>=enemiesThisRound){
						newOrcs[i][0] -= enemiesThisRound;
						enemiesThisRound =0;
					}else { //enemiesThisRound > mercenariosRound
						enemiesThisRound -=newOrcs[i][0];
						newOrcs[i][0] =0;
					}
					if(enemiesThisRound <1 )break;
				}
				//remove 1 turn 
				for(int i=0; i< newOrcs.length; i++){
					newOrcs[i][1] = newOrcs[i][1] -1;
					if(newOrcs[i][1] == 0){
						newOrcs[i][0] = 0;
					}		
				}
				int cost3 = findPath(cost , pos +1, Enemies,newOrcs); // Path en B
				lowestCost = Math.min(cost1, Math.min(cost2,cost3));
			}else {
				lowestCost = Math.min(cost1, cost2);
			}
			return lowestCost;
		}
	
	static int getAnswer(int N, int[][] Enemies){

		int[][] myOrcs = new int[N][2];
		
		int cost=0,pos=0;
		lowestCost=Integer.MAX_VALUE;
		
		return findPath(cost, pos, Enemies, myOrcs);

	}
	
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = null;
		
		try {
			sc = new Scanner(  new File("C:\\Users\\SRT\\algorithms\\robot\\src\\frodo\\input2.txt")  );
		} catch (Exception e){
			e.printStackTrace();
		}
		int test_case =  sc.nextInt();
		
		int N=0;

		for (int tc = 1; tc <= test_case; tc++){
			//if(tc ==1 ) {
			N = sc.nextInt();
			int grid [][] =  new int [N][2];

			for(int row = 0 ; row < grid.length ; row++) {
				System.out.println(" ");
				for(int col=0; col< grid[0].length; col++) {
					grid[row][col] = sc.nextInt();
					System.out.print(" "+ grid[row][col]);
				}
			}
			System.out.println("\n");
							
			System.out.println("#"+tc+":"+getAnswer(N,grid));
			//}	
		}
		
	}

}
