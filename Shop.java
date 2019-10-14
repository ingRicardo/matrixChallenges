package shopper; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Shop {

    static float globalMin = Float.MAX_VALUE;

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("C:/Users/SRT/algorithms/robot/src/shopper/input.txt");
        Scanner sc = new Scanner (file);

        int T = sc.nextInt();

        // Loops thru each test case
        for(int tc=1; tc<=T; tc++){
            int coupons = sc.nextInt();
            int consoleCost = sc.nextInt();
           //  System.out.println("coupons " + coupons);
           //  System.out.println(" consoleCost " + consoleCost );
            int[][] couponList = new int[coupons][2];

            // Captures the coupons price and discount
            for(int i=0; i<couponList.length; i++){
                couponList[i][0] = sc.nextInt();//cost
                couponList[i][1] = sc.nextInt();// discount percentage
            }

            System.out.println("#" + tc + " " + bestPrice(consoleCost, couponList));
        }
    }

    public static float bestPrice(int consoleCost, int[][] couponList){
        globalMin = consoleCost;
        return operation(0, consoleCost, couponList, 1, 0);
    }

    public static float operation(int pos, int consoleCost, int[][] couponList, float accDiscount, int accPrice){
        if(pos>=couponList.length){
            return globalMin;
        }

        for(int i=pos; i<couponList.length; i++){
            float discount = 1 - couponList[i][1] * 0.01f;//discount
            float newAccDiscount = discount * accDiscount;

            int couponCost = couponList[i][0];//coupon COST
            int newAccPrice = couponCost + accPrice;

            float newConsoleCost = consoleCost * newAccDiscount + newAccPrice;
            globalMin = min(globalMin, newConsoleCost);
            
            operation(i+1, consoleCost, couponList, newAccDiscount, newAccPrice);
        }
        return globalMin;
    }

    public  static float min(float a, float b){
        return (a < b)? a : b;
    }

}