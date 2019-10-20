#include <iostream>
#include <climits>
using namespace std;

float globalMin = INT_MAX;

float min(float a, float b){

	return(a<b)?a:b;

}

float operation (  int pos, int consoleCost, int **couponList, float accDiscount, int accPrice,int coupons  ){
	
	if(pos>=coupons){

		return globalMin;
	}


	for(int i=pos; i<coupons;i++){

		float discount = 1 - couponList[i][1] * 0.01f;
		float newAccDiscount = discount * accDiscount;

		int couponCost = couponList[i][0];
		int newAccPrice = couponCost + accPrice;
		float newConsoleCost = consoleCost * newAccDiscount + newAccPrice;
		globalMin = min(globalMin,newConsoleCost);

		operation(i+1,consoleCost, couponList,newAccDiscount, newAccPrice,coupons);
	}

	return globalMin;

}




float bestPrice(  int consoleCost, int **couponList ,int coupons){

	globalMin = consoleCost;

	return operation(0,consoleCost, couponList,1,0,coupons);

}

int main(){

	cout<<"testing"<<endl;
	

	freopen("input.txt","r", stdin);
	int coupons;
	int consoleCost;

	int T;
	cin >>T;
	for(int tc = 1; tc<=T; tc++){


		
		cin>>coupons;
		cin>>consoleCost;
	//	cout<<"coupons "<<coupons<<endl;
//		cout<<"consoleCost "<<consoleCost<<endl;
		int **couponList = new int *[coupons];
		int cost =0, discount=0,M=2;
		for (int i =0; i<coupons; i++){
			cin >> cost;
			cin >> discount;

			couponList[i] = new int[M];
			couponList[i][0] = cost;
			couponList[i][1] = discount;


		}
		
				
		cout<<"#"<<tc<<" "<<bestPrice(consoleCost,couponList,coupons)<<endl;


	}

return 0;
}
