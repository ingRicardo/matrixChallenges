#include <iostream>

using namespace std;

int main(){

//int arr1[] = { 1,0,-1,1,1,1,0,0};
//int arr1[] = { 1,0,0,0,0,0,0,-1};
//int arr1[] = { 1,0,0,0,-1,0,0,-1};
int arr1[] = { 1,0,1,0,-1,0,0,-1};



int size = sizeof(arr1)/sizeof(arr1[0]);

int i,idn=0,idp=0,ct=0;

for(i=0; i< size; i++){
	
	if(arr1[i] > 0){
		
	ct++;
	idp=i;	
		} if(arr1[i] < 0){
		ct++;
		idn=i;
	}
	
	if(idp<idn && arr1[idp]!=0 && arr1[idn]!=0){
if(ct >0){
	ct -- ;
	ct --;
}
	}
			

}

cout << "\n tot "<<abs( ct)<<"\n";
return 0;
}
