#include <iostream>
using namespace std;
//http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs3343/lecture25.html
void swap (int v[], int i, int j) {
	int	t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

/* recursive function to generate permutations */
void perm (int v[], int n, int start) {

	/* this function generates the permutations of the array
	 * from element i to element n-1
	 */
	int	j;

	/* if we are at the end of the array, we have one permutation
	 * we can use (here we print it; you could as easily hand the
	 * array off to some other function that uses it for something
	 */
	if (start == n) {
		for (j=0; j<n; j++) cout << v[j];
		cout<<"\n";
	} else
		/* recursively explore the permutations starting
		 * at index i going through index n-1
		 */
		for (j=start; j<n; j++) {

			/* try the array with i and j switched */

			swap (v, start, j);
			perm (v, n, start+1);

			/* swap them back the way they were */

			swap (v, start, j);
		}
}
			
/* little driver function to print perms of first 5 integers */

int main () {
	int size =5;
	int	v[size], i;

	for (i=0; i<size; i++) v[i] = i+1;
	perm (v, size, 0);
	return 0;
}