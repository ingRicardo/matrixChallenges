// testFrodo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int lowestCost = INT_MAX;
 
int minVal(int a, int b){
	int min = a;
	if (b<min)
		min = b;
	return min;
}
int findPath(int cost, int pos, int **enemies, int **myOrcs, int N, int M){

	if (cost >= lowestCost) return lowestCost;

	if (pos >= N) return cost;


	int toll = enemies[pos][1];
	int cost1 = findPath(cost + toll, pos + 1, enemies, myOrcs, N, M);

	int totalMercenaries = 0;
	int enemiesThisRound = enemies[pos][0];

	int **newOrcs = new int *[N];

	for (int i = 0; i<N; i++){
		newOrcs[i] = new int[M];
		for (int j = 0; j<M; j++){
			newOrcs[i][j] = 0;
		}
	}

	for (int i = 0; i< N; i++){

		newOrcs[i][0] = myOrcs[i][0];
		newOrcs[i][1] = myOrcs[i][1];
		totalMercenaries += newOrcs[i][0];//find total orcs
	}

	newOrcs[pos][0] = enemies[pos][0];
	newOrcs[pos][1] = 3;
	int hireCost = toll * 2;

	int cost2 = findPath(cost + hireCost, pos + 1, enemies, newOrcs, N, M); //path en H

	//return  new orcs to original 
	newOrcs[pos][0] = myOrcs[pos][0];
	newOrcs[pos][1] = myOrcs[pos][1];
	if (totalMercenaries >= enemiesThisRound){

		//battle
		for (int i = 0; i<N; i++){
			int mercenariosRound = newOrcs[i][0];

			if (mercenariosRound >= enemiesThisRound){
				newOrcs[i][0] -= enemiesThisRound;
				enemiesThisRound = 0;

			}
			else { //enemiesThisRound > mercenariosRound

				enemiesThisRound -= newOrcs[i][0];
				newOrcs[i][0] = 0;
			}

			if (enemiesThisRound <1)break;
		}

		//remove 1 turn

		for (int i = 0; i< N; i++){
			newOrcs[i][1] = newOrcs[i][1] - 1;
			if (newOrcs[i][1] == 0){
				newOrcs[i][0] = 0;
			}

		}
		int cost3 = findPath(cost, pos + 1, enemies, newOrcs, N, M); // Path en B
		lowestCost = minVal(cost1, minVal(cost2, cost3));
	}
	else {
		lowestCost = minVal(cost1, cost2);
	}

	return lowestCost;


}
int getAnswer(int N, int M, int **enemies){
	int cost = 0, pos = 0;
	int **myOrcs = new int*[N];
	for (int i = 0; i<N; i++){

		myOrcs[i] = new int[M];
		for (int j = 0; j<M; j++){
			myOrcs[i][j] = 0;
		}
	}
	lowestCost = INT_MAX;

	return findPath(cost, pos, enemies, myOrcs, N, M);


}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input2.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++){

		int N, M = 2, num = 0;

		cin >> N;

		int **enemies = new int *[N];
		for (int i = 0; i<N; i++){
			enemies[i] = new int[M];
			cout << "\n";
			for (int j = 0; j<M; j++){
				cin >> num;
				enemies[i][j] = num;
				cout << " " << enemies[i][j];
			}
		}
		//code goes here
		//
		//

		cout << "\n#" << tc << ":" << getAnswer(N, M, enemies) << endl;
	}
	cout << endl;

	return 0;
}





